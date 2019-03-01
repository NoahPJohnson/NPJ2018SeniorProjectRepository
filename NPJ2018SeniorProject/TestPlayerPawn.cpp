// Fill out your copyright notice in the Description page of Project Settings.

#include "TestPlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimBlueprint.h"
#include "Components/CapsuleComponent.h"
#include "CollidingPawnMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "ConstructorHelpers.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "C++Classes/BaseEnemy.h"
#include "C++Classes/BaseEnemyCharacter.h"
#include "NPJ2018SeniorProjectCharacter.h"

// Sets default values
ATestPlayerPawn::ATestPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootComponent"));
	RootComponent = CollisionCapsule;
	CollisionCapsule->InitCapsuleSize(42.f, 96.0f);
	CollisionCapsule->SetCollisionProfileName(TEXT("Pawn"));
	CollisionCapsule->bHiddenInGame = false;

	//AutoPossessPlayer = EAutoReceiveInput::Player0;

	/*static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder'"));
	UStaticMesh* MyMesh = MeshAsset.Object;
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

	OurVisibleComponent->SetStaticMesh(MyMesh);*/

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshAsset(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin'"));
	USkeletalMesh* MyMesh = MeshAsset.Object;
	OurVisibleComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
	//USkeletalMeshComponent* characterMesh = GetMesh();
	OurVisibleComponent->SetSkeletalMesh(MyMesh);
	OurVisibleComponent->SetRelativeRotation(FRotator(0.0, 270.0, 0.0));
	OurVisibleComponent->SetRelativeLocation(FVector(0.0, 0.0, -80.0));

	// load the animation blueprint
	const ConstructorHelpers::FObjectFinder<UAnimBlueprint>AnimObject(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP'"));

	// generated class is important here :)
	OurVisibleComponent->SetAnimInstanceClass(AnimObject.Object->GeneratedClass);

	APlayerController* Controller = CreateDefaultSubobject<APlayerController>(TEXT("Controller"));

	//Default Movement Speed
    baseSpeed = 1000.0f;
	currentMoveSpeed = baseSpeed;
	maxSpeed = 2500.0f;
	currentMomentumDelta = currentMoveSpeed*0.0008f;
	currentMomentumVector = FVector(0.0, 0.0, 0.0);
	isReadyToSwitch = false;
	timeToSwitch = 0.1f;

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
    CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	CameraBoom->bHiddenInGame = false;
												// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false;

    

	

	GrabBox = CreateDefaultSubobject<UBoxComponent>(TEXT("GrabBox"));
	GrabBox->SetupAttachment(RootComponent);


	//Set a base power level for the character
	initialHealth = 1000.0f;
	currentHealth = initialHealth;
	initialPower = 1000.0f;
	characterPower = initialPower;
	startConsumingPower = false;

	//Sprinting stuff
	//Max walk speed = 600 at start, I think
	//baseSpeed = GetCharacterMovement()->MaxWalkSpeed;
	sprintSpeedBonus = 800.0f;
	//sprintBoostLimit = GetCharacterMovement()->MaxWalkSpeed + sprintSpeedBonus;
	sprintBoostAcceleration = 500.0f;
	sprintBoostBonus = sprintBoostBase = -200.0f;
	isSprinting = false;
	//GetCharacterMovement()->MaxWalkSpeed = 1400;

	//Flying stuff
	isFlying = false;
	//UMyCharacterMovementComponent* CustomMovement = CreateDefaultSubobject<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName);
	jumpForce = 600.0f;
	defaultAirControl = 0.5f;
	//GetCharacterMovement()->MaxFlySpeed = 200;
	flightSpeedLimit = 1400;
	flightSpeedBonus = 200;
	flightSpeedBonusAcceleration = 450;
	//New flying stuff
	flightSpeedNormal = 1000;
	savedHorizontalAxis = 0.0;
	savedVerticalAxis = 0.0;

	//Crouching/Sliding/Gliding stuff
	isCrouching = false;
	isSliding = false;
	buildUpSpeedIncrease = 550.0f;

	//Camera Control stuff
	isLockingOn = false;
	nearestEnemyLocation = GetActorForwardVector();
	startingCameraLocation = FollowCamera->RelativeLocation;
	lockOnCameraLocation = FVector(130.0f, 110.0f, 40.0f);

	//Attack Stuff

	//GrabBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	isReadyToGrab = false;
	isHoldingEnemy = false;
	//grabbedEnemy = nullptr;

	MyPawnMovementComponent = CreateDefaultSubobject<UCollidingPawnMovementComponent>(TEXT("CustomPawnMovementComponent"));
	                        //CreateDefaultSubobject<UCollidingPawnMovementComponent>(TEXT("CustomMovementComponent"));
	MyPawnMovementComponent->UpdatedComponent = RootComponent;
	

}

// Called when the game starts or when spawned
void ATestPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	isFlying = true;
	isReadyToSwitch = false;
	UE_LOG(LogClass, Log, TEXT("The Pawn is here."));
	//UE_LOG(LogClass, Log, TEXT("The pawn is at X: %f"), GetActorLocation().X);
	//UE_LOG(LogClass, Log, TEXT("The pawn is at Y: %f"), GetActorLocation().Y);
	//UE_LOG(LogClass, Log, TEXT("The pawn is at Z: %f"), GetActorLocation().Z);
}

// Called every frame
void ATestPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isReadyToSwitch == false)
	{
		if (timer < timeToSwitch)
		{
			timer += DeltaTime;
		}
		else
		{
			isReadyToSwitch = true;
		}
	}

	//Handle Flight
	if (isFlying == true)
	{
		if (isAscending == true)
		{
			MoveUp(1.0);
		}
		else if (isDescending == true)
		{
			MoveDown(1.0);
		}
		else
		{
			//AddMovementInput(GetActorUpVector(), 0.0f);
			if ((FMath::Abs(GetInputAxisValue("MoveForward")) < 0.2f && FMath::Abs(GetInputAxisValue("MoveRight")) < 0.2f) && savedVerticalAxis < 0.2 && savedHorizontalAxis < 0.2)
			{
				UE_LOG(LogClass, Log, TEXT("Stop flying from Tick()"));
				//StopFly();
				if (isReadyToSwitch == true)
				{
					isReadyToSwitch = false;
					SwitchCharacter(true,true);
					//isCharacterGliding = true;
					//isReadyToSwitch = true;
				}
			}
			else if (savedVerticalAxis >= 0.2 || savedHorizontalAxis >= 0.2)
			{
				UE_LOG(LogClass, Log, TEXT("Reset Saved Values."));
				savedVerticalAxis = 0;
				savedHorizontalAxis = 0;
			}
		}


		if (currentMoveSpeed > baseSpeed)
		{
			currentMoveSpeed -= 80 * DeltaTime;
			currentMoveSpeed = FMath::Clamp(currentMoveSpeed, 1000.0f, 2500.0f);
			MyPawnMovementComponent->SetCurrentSpeed(currentMoveSpeed);
		}
		CalculateMomentumVector(DeltaTime);

		//Handle Check for Floor
		FHitResult outHit;
		FVector startVector = (GetActorUpVector()*-100) + GetActorLocation();
		FVector endVector = (GetActorUpVector()*-60) + startVector;
		DrawDebugLine(GetWorld(), startVector, endVector, FColor::Green, false, 1, 0, 1);
		FCollisionQueryParams collisionParameters;
		if (GetWorld()->LineTraceSingleByChannel(outHit,startVector,endVector,ECC_WorldStatic,collisionParameters))
		{
			if (outHit.bBlockingHit == true && isReadyToSwitch == true)
			{
				UE_LOG(LogClass, Log, TEXT("Touching Ground."));
				//UE_LOG(LogClass, Log, TEXT("You are hitting: %s"), *outHit.GetActor()->GetName());
				//UE_LOG(LogClass, Log, TEXT("Impact Point: %s"), *outHit.ImpactPoint.ToString());
				//UE_LOG(LogClass, Log, TEXT("Normal Point: %s"), *outHit.ImpactNormal.ToString());
				isReadyToSwitch = false;
				SwitchCharacter(false,false);
				
				//isCharacterGliding = false;
				//isReadyToSwitch = true;
			}
		}
		


		//Handle Power Consumption
		if (isFlying == true)
		{
			if (startConsumingPower == false)
			{
				startConsumingPower = true;
				if (characterPower > 0)
				{
					characterPower -= 50;
				}
			}
			if (characterPower > 0)
			{
				characterPower -= 150 * DeltaTime;
			}
			else
			{
				if (currentHealth > 0)
				{
					currentHealth -= 150 * DeltaTime;
					//UE_LOG(LogClass, Log, TEXT("Losing Health: %f"), currentHealth);
				}
			}
		}
		else
		{
			startConsumingPower = false;
			if (characterPower < initialPower)
			{
				characterPower += 100 * DeltaTime;
			}
			else if (currentHealth < initialHealth)
			{
				currentHealth += 100 * DeltaTime;
			}
		}
	}	
}

// Called to bind functionality to input
void ATestPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	PlayerInputComponent->BindAxis("MoveForward", this, &ATestPlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATestPlayerPawn::MoveRight);

	PlayerInputComponent->BindAxis("TurnRate", this, &ATestPlayerPawn::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATestPlayerPawn::LookUpAtRate);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATestPlayerPawn::Ascend);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ATestPlayerPawn::StopAscend);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ATestPlayerPawn::Descend);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ATestPlayerPawn::StopDescend);

	PlayerInputComponent->BindAction("LockOn", IE_Pressed, this, &ATestPlayerPawn::CameraLockOn);
}

void ATestPlayerPawn::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f) && MyPawnMovementComponent && (MyPawnMovementComponent->UpdatedComponent == RootComponent))
	{

		//MyPawnMovementComponent->AddInputVector(GetActorForwardVector() * Value);

		
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		if (isSprinting == true || isSliding == true)
		{
			//AddMovementInput(Direction / 20, Value);
			GetMovementComponent()->AddInputVector((Direction / 20) * Value);
		}
		else
		{
			//AddMovementInput(Direction, Value);
			GetMovementComponent()->AddInputVector((Direction) * Value);
			//UE_LOG(LogClass, Log, TEXT("Move, please."));
		}
		//GetInputAxisValue("MoveForward");
		//UE_LOG(LogClass, Log, TEXT("left Y is %f"), GetInputAxisValue("MoveForward"));
		
	}
}

void ATestPlayerPawn::MoveRight(float Value)
{
    if ((Controller != NULL) && (Value != 0.0f) && MyPawnMovementComponent && (MyPawnMovementComponent->UpdatedComponent == RootComponent))
	{
		//MyPawnMovementComponent->AddInputVector(GetActorRightVector() * Value);
		
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();

		//float newYaw = Rotation.Yaw;;
		//UE_LOG(LogClass, Log, TEXT("MyCharacter's rotation is %f"), newYaw);
		//const FRotator YawRotation(0, newYaw, 0);
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		if (isSprinting == true || isSliding == true)
		{
			//AddMovementInput(Direction / 20, Value);
			GetMovementComponent()->AddInputVector((Direction / 20) * Value);
		}
		else
		{
			//AddMovementInput(Direction, Value);
			GetMovementComponent()->AddInputVector((Direction)*Value);
			//UE_LOG(LogClass, Log, TEXT("Move, please."));
		}

		
		//UE_LOG(LogClass, Log, TEXT("LEFT X is %f"), GetInputAxisValue("MoveRight"));
	}
}

void ATestPlayerPawn::MoveUp(float Value)
{
	//AddMovementInput(GetActorUpVector(), 1.0f);
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector Direction = GetActorUpVector();//FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Z);
	if (isSprinting == true || isSliding == true)
	{
		//AddMovementInput(Direction / 20, Value);
		GetMovementComponent()->AddInputVector((Direction / 20) * 1.0);
	}
	else
	{
		//AddMovementInput(Direction, Value);
		GetMovementComponent()->AddInputVector((Direction)* 1.0);
		//UE_LOG(LogClass, Log, TEXT("Move, please."));
	}
}

void ATestPlayerPawn::MoveDown(float Value)
{
	//AddMovementInput(-GetActorUpVector(), 1.0f);
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector Direction = GetActorUpVector();
	if (isSprinting == true || isSliding == true)
	{
		//AddMovementInput(Direction / 20, Value);
		GetMovementComponent()->AddInputVector((Direction / 20) * -1.0);
	}
	else
	{
		//AddMovementInput(Direction, Value);
		GetMovementComponent()->AddInputVector((Direction)* -1.0);
		//UE_LOG(LogClass, Log, TEXT("Move, please."));
	}
}

void ATestPlayerPawn::Turn(float AxisValue)
{
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += AxisValue;
	SetActorRotation(NewRotation);
}

void ATestPlayerPawn::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATestPlayerPawn::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

UPawnMovementComponent* ATestPlayerPawn::GetMovementComponent() const
{
	return MyPawnMovementComponent;
}

void ATestPlayerPawn::CalculateMomentumVector(float DeltaTime)
{
	if (isAscending == true)
	{
		if (currentMomentumVector.Z < 1.0)
		{
			currentMomentumVector += FVector(0.0, 0.0, currentMomentumDelta) * DeltaTime;
		}
	}
	else
	{
		if (currentMomentumVector.Z > 0.0)
		{
			currentMomentumVector += FVector(0.0, 0.0, -currentMomentumDelta) * DeltaTime;
		}
	}
	if (isDescending == true)
	{
		if (currentMomentumVector.Z > -1.0)
		{
			currentMomentumVector += FVector(0.0, 0.0, -currentMomentumDelta) * DeltaTime;
		}
	}
	else
	{
		if (currentMomentumVector.Z < 0.0)
		{
			currentMomentumVector += FVector(0.0, 0.0, currentMomentumDelta) * DeltaTime;
		}
	}
	if (GetInputAxisValue("MoveForward") > 0.0)
	{
		if (currentMomentumVector.X < 1.0 && currentMomentumVector.X < GetInputAxisValue("MoveForward"))
		{
			currentMomentumVector += FVector(currentMomentumDelta, 0.0, 0.0) * DeltaTime;
		}
	}
	else
	{
		if (currentMomentumVector.X > 0.0)
		{
			currentMomentumVector += FVector(-currentMomentumDelta, 0.0, 0.0) * DeltaTime;
		}
	}
	if (GetInputAxisValue("MoveForward") < 0)
	{
		if (currentMomentumVector.X > -1.0 &&  currentMomentumVector.X > GetInputAxisValue("MoveForward"))
		{
			currentMomentumVector += FVector(-currentMomentumDelta, 0.0, 0.0) * DeltaTime;
		}
	}
	else
	{
		if (currentMomentumVector.X < 0.0)
		{
			currentMomentumVector += FVector(currentMomentumDelta, 0.0, 0.0) * DeltaTime;
		}
	}
	if (GetInputAxisValue("MoveRight") > 0)
	{
		if (currentMomentumVector.Y < 1.0 && currentMomentumVector.Y < GetInputAxisValue("MoveRight"))
		{
			currentMomentumVector += FVector(0.0, currentMomentumDelta, 0.0) * DeltaTime;
		}
	}
	else
	{
		if (currentMomentumVector.Y > 0.0)
		{
			currentMomentumVector += FVector(0.0, -currentMomentumDelta, 0.0) * DeltaTime;
		}
	}
	if (GetInputAxisValue("MoveRight") < 0)
	{
		if (currentMomentumVector.Y > -1.0 && currentMomentumVector.Y > GetInputAxisValue("MoveRight"))
		{
			currentMomentumVector += FVector(0.0, -currentMomentumDelta, 0.0) * DeltaTime;
		}
	}
	else
	{
		if (currentMomentumVector.Y < 0.0)
		{
			currentMomentumVector += FVector(0.0, currentMomentumDelta, 0.0) * DeltaTime;
		}
	}

	currentMomentumVector.X = FMath::Clamp(currentMomentumVector.X, -1.0f, 1.0f);
	currentMomentumVector.Y = FMath::Clamp(currentMomentumVector.Y, -1.0f, 1.0f);
	currentMomentumVector.Z = FMath::Clamp(currentMomentumVector.Z, -1.0f, 1.0f);
}

void ATestPlayerPawn::Sprint()
{

}

void ATestPlayerPawn::Jump()
{

}

void ATestPlayerPawn::SwitchCharacter(bool glideValue, bool skidValue)
{
	APlayerController* controller = Cast<APlayerController>(GetController());
	if (controller != NULL)
	{
		UE_LOG(LogClass, Log, TEXT("Discovered Player Controller"));
		FRotator camRotation = CameraBoom->GetSocketRotation(USpringArmComponent::SocketName);
		//UE_LOG(LogClass, Log, TEXT("camRotation Roll = %f"), camRotation.Roll);
		//UE_LOG(LogClass, Log, TEXT("camRotation Pitch = %f"), camRotation.Pitch);
		//UE_LOG(LogClass, Log, TEXT("camRotation Yaw = %f"), camRotation.Yaw);
		//UE_LOG(LogClass, Log, TEXT("Velocity X = %f"), GetVelocity().X);
		//UE_LOG(LogClass, Log, TEXT("Velocity Y = %f"), GetVelocity().Y);
		//UE_LOG(LogClass, Log, TEXT("Velocity Z = %f"), GetVelocity().Z);
		//UE_LOG(LogClass, Log, TEXT("Forward X = %f"), GetActorForwardVector().X);
		//UE_LOG(LogClass, Log, TEXT("Forward Y = %f"), GetActorForwardVector().Y);
		//UE_LOG(LogClass, Log, TEXT("Forward Z = %f"), GetActorForwardVector().Z);
		controller->UnPossess();
		Destroy();
		//ANPJ2018SeniorProjectCharacter* characterToSpawn = Cast<ANPJ2018SeniorProjectCharacter>(GetWorld()->SpawnActor(characterToSpawn->StaticClass()));
		ANPJ2018SeniorProjectCharacter* characterToSpawn = GetWorld()->SpawnActor<ANPJ2018SeniorProjectCharacter>(characterToSpawn->StaticClass(), GetActorLocation(), GetActorRotation());
		controller->Possess(characterToSpawn);

		characterToSpawn->SetCameraPosition(camRotation);
		characterToSpawn->SetGlide(glideValue);
		//UE_LOG(LogClass, Log, TEXT("Current momentum X = %f"), currentMomentumVector.X);
		//UE_LOG(LogClass, Log, TEXT("Current momentum Y = %f"), currentMomentumVector.Y);
		//UE_LOG(LogClass, Log, TEXT("Current momentum Z = %f"), currentMomentumVector.Z);
		//currentMomentumVector.X *= -1;
		FVector launchVector = GetActorForwardVector() + FVector(0.0,0.0,currentMomentumVector.Z);
		float launchForce = FVector(currentMomentumVector.X, currentMomentumVector.Y, 0.0).Size() * currentMoveSpeed;
		
		UE_LOG(LogClass, Log, TEXT("Launch force = %f"), launchForce);
		launchVector = FVector(launchVector.X * launchForce, launchVector.Y * launchForce, launchVector.Z * currentMoveSpeed);
		UE_LOG(LogClass, Log, TEXT("LAUNCH X = %f"), launchVector.X);
		UE_LOG(LogClass, Log, TEXT("LAUNCH Y = %f"), launchVector.Y);
		UE_LOG(LogClass, Log, TEXT("LAUNCH Z = %f"), launchVector.Z);
		characterToSpawn->UpdateHealth(currentHealth);
		characterToSpawn->UpdatePower(characterPower);
		characterToSpawn->MomentumLaunch(launchVector);
		characterToSpawn->SetSkid(skidValue);
	}
}

void ATestPlayerPawn::SetSavedAxis(float vValue, float hValue, bool aValue, bool dValue)
{
	savedVerticalAxis = vValue;
	savedHorizontalAxis = hValue;
	isAscending = aValue;
	isDescending = dValue;
}

void ATestPlayerPawn::SetCameraPosition(FRotator newRotation)
{
	//UE_LOG(LogClass, Log, TEXT("new Rotation Roll = %f"), newRotation.Roll);
	//UE_LOG(LogClass, Log, TEXT("new Rotation Pitch = %f"), newRotation.Pitch);
	//UE_LOG(LogClass, Log, TEXT("new Rotation Yaw = %f"), newRotation.Yaw);
	GetController()->SetControlRotation(newRotation);
	
	//UE_LOG(LogClass, Log, TEXT("CONTROL Roll = %f"), GetController()->GetControlRotation().Roll);
	//UE_LOG(LogClass, Log, TEXT("CONTROL Pitch = %f"), GetController()->GetControlRotation().Pitch);
	//UE_LOG(LogClass, Log, TEXT("CONTROL Yaw = %f"), GetController()->GetControlRotation().Yaw);
	//UE_LOG(LogClass, Log, TEXT("socket Roll = %f"), CameraBoom->GetSocketRotation(USpringArmComponent::SocketName).Roll);
	//UE_LOG(LogClass, Log, TEXT("socket Pitch = %f"), CameraBoom->GetSocketRotation(USpringArmComponent::SocketName).Pitch);
	//UE_LOG(LogClass, Log, TEXT("socket Yaw = %f"), CameraBoom->GetSocketRotation(USpringArmComponent::SocketName).Yaw);
}

void ATestPlayerPawn::SetBoostedSpeed(float newSpeed)
{
	currentMoveSpeed = newSpeed;
	currentMoveSpeed = FMath::Clamp(currentMoveSpeed, baseSpeed, maxSpeed);
	currentMomentumDelta = currentMoveSpeed*0.0008f;
	//GetMovementComponent()->SetCurrentSpeed(currentMoveSpeed);
	MyPawnMovementComponent->SetCurrentSpeed(currentMoveSpeed);
	//isReadyToSwitch = true;
}


void ATestPlayerPawn::Ascend()
{
	if (isAscending == false)
	{
		isAscending = true;
	}
}

void ATestPlayerPawn::StopAscend()
{
	if (isAscending == true)
	{
		isAscending = false;
	}
}

void ATestPlayerPawn::Descend()
{
	if (isDescending == false)
	{
		isDescending = true;
	}
}

void ATestPlayerPawn::StopDescend()
{
	if (isDescending == true)
	{
		isDescending = false;
	}
}

void ATestPlayerPawn::Fly()
{

}

void ATestPlayerPawn::StopFly()
{


}

void ATestPlayerPawn::Crouch_Slide_Glide()
{

}

void ATestPlayerPawn::StopCrouch_Slide_Glide()
{

}

void ATestPlayerPawn::CameraLockOn()
{
	//FVector nearestEnemyLocation = GetActorForwardVector();
	if (isLockingOn == false)
	{
		isLockingOn = true;
		TArray<AActor*> FoundEnemies;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseEnemyCharacter::StaticClass(), FoundEnemies);
		for (int i = 0; i < FoundEnemies.Num(); i++)
		{
			if (Cast<ABaseEnemyCharacter>(FoundEnemies[i])->GetCollisionRoot() != nullptr)
			{
				if ((this->GetActorLocation() - Cast<ABaseEnemyCharacter>(FoundEnemies[i])->GetCollisionRoot()->GetComponentLocation()).Size() < 1000)
				{
					//nearestEnemy = Cast<ABaseEnemyCharacter>(FoundEnemies[i])->GetCollisionRoot();
					//nearestEnemyLocation = nearestEnemy->GetActorLocation();
					//UE_LOG(LogClass, Log, TEXT("Locked on Nearest Enemy"));
					//FollowCamera->SetRelativeLocation(lockOnCameraLocation);
				}
			}
		}
	}
	else
	{
		isLockingOn = false;
		//FollowCamera->SetRelativeLocation(startingCameraLocation);
	}

	//FollowCamera->AddLocalOffset(FVector(100, 100, 0), false);
	//FollowCamera->bUsePawnControlRotation = false;
	//FollowCamera->bUseControllerViewRotation = false;
	//FRotator targetRotation =  UKismetMathLibrary::FindLookAtRotation(FollowCamera->GetComponentLocation(), nearestEnemyLocation);
	//FMath::RInterpTo(FollowCamera->GetComponentRotation(), targetRotation, DeltaTime, 250.0f);
}

void ATestPlayerPawn::Grab()
{
	if (isReadyToGrab == false)
	{
		isReadyToGrab = true;
		GrabBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}

}

void ATestPlayerPawn::SetHoldingEnemy(bool holding)
{
	isHoldingEnemy = holding;
}

void ATestPlayerPawn::PerformGrab(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	/*if (isReadyToGrab == true && grabbedEnemy == nullptr)
	{
		//TArray<AActor*> GrabbedActors;
		//GrabBox->GetOverlappingActors(GrabbedActors, ABaseEnemy::StaticClass());
		if (OtherActor != nullptr)
		{
			//isHoldingEnemy = true;
			grabbedEnemy = Cast<ABaseEnemyCharacter>(OtherActor);
			UE_LOG(LogClass, Log, TEXT("Grabbed Enemy"));
			if (grabbedEnemy != nullptr)
			{
				grabbedEnemy->StartGrabCountdown();
			}
		}
		else
		{
			UE_LOG(LogClass, Log, TEXT("Grabbed Nothing"));
		}
	}*/
}

void ATestPlayerPawn::PerformRelease(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	//UE_LOG(LogClass, Log, TEXT("Grabbed Enemy: %s"), *GrabbedActors[0]->GetName());
	/*if (grabbedEnemy != nullptr)
	{
		if (grabbedEnemy->GetIsGrabbed() == false)
		{
			grabbedEnemy->StartGrabCountUP();
			grabbedEnemy = nullptr;
		}
	}*/
}

void ATestPlayerPawn::Throw()
{
	/*if (isReadyToGrab == true)
	{
		isReadyToGrab = false;
		if (grabbedEnemy != nullptr)
		{
			if (grabbedEnemy->GetIsGrabbed() == true)
			{
				UE_LOG(LogClass, Log, TEXT("Throw please"));
				grabbedEnemy->GetThrown(600.0);
				CameraLockOn();
				grabbedEnemy = nullptr;
			}
		}
	}
	GrabBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);*/
}


float ATestPlayerPawn::GetInitialPower()
{
	return initialPower;
}

float ATestPlayerPawn::GetCurrentPower()
{
	return characterPower;
}

void ATestPlayerPawn::UpdatePower(float newPower)
{
	characterPower = newPower;
}

void ATestPlayerPawn::UpdateHealth(float newHealth)
{
	currentHealth = newHealth;
}

//Called whenever power is increased or decreased
void ATestPlayerPawn::UpdateCharacterPower(float powerChange)
{
	/*if (characterPower < (initialPower*1.25))
	{
	characterPower += powerChange;
	//Part of all character classes
	//GetCharacterMovement()->MaxWalkSpeed = baseSpeed + speedFactor * characterPower;
	}
	//Call visual effect
	PowerChangeEffect();*/
}

