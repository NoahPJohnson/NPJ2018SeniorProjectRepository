// Fill out your copyright notice in the Description page of Project Settings.

#include "TestPlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "CollidingPawnMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "ConstructorHelpers.h"
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

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder'"));
	UStaticMesh* MyMesh = MeshAsset.Object;
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

	OurVisibleComponent->SetStaticMesh(MyMesh);
	APlayerController* Controller = CreateDefaultSubobject<APlayerController>(TEXT("Controller"));

	//Default Movement Speed
    baseSpeed = 10.0f;

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
	UE_LOG(LogClass, Log, TEXT("The Pawn is here."));
	//UE_LOG(LogClass, Log, TEXT("The pawn is at X: %f"), GetActorLocation().X);
	//UE_LOG(LogClass, Log, TEXT("The pawn is at Y: %f"), GetActorLocation().Y);
	//UE_LOG(LogClass, Log, TEXT("The pawn is at Z: %f"), GetActorLocation().Z);
}

// Called every frame
void ATestPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//FRotator testRotation = FRotator(-90.0,45.0,0.0);
	//GetController()->SetControlRotation(testRotation);
	//Handle Flight
	if (isFlying == true)
	{
		UE_LOG(LogClass, Log, TEXT("tick CONTROL Roll = %f"), GetController()->GetControlRotation().Roll);
		UE_LOG(LogClass, Log, TEXT("tick CONTROL Pitch = %f"), GetController()->GetControlRotation().Pitch);
		UE_LOG(LogClass, Log, TEXT("tick CONTROL Yaw = %f"), GetController()->GetControlRotation().Yaw);
		/*if (isCrouching == false)
		{
			FRotator testRotation = FRotator(-90.0, 45.0, 0.0);
			GetController()->SetControlRotation(testRotation);
			isCrouching = true;
		}*/
		//UE_LOG(LogClass, Log, TEXT("Flight Speed = %f"), GetCharacterMovement()->MaxFlySpeed);
		/*if (GetCharacterMovement()->MaxFlySpeed < flightSpeedLimit)
		{
			//flightSpeedBonus += flightSpeedBonusAcceleration * DeltaTime;
			//GetCharacterMovement()->MaxFlySpeed += flightSpeedBonus * DeltaTime;
			GetCharacterMovement()->MaxFlySpeed = FMath::Clamp(GetCharacterMovement()->MaxFlySpeed, 0.0f, flightSpeedLimit);
		}*/
		if (isAscending == true)
		{
			//AddMovementInput(GetActorUpVector(), 1.0f);
			GetMovementComponent()->AddInputVector((GetActorUpVector())* baseSpeed);
			
		}
		else
		{
			//AddMovementInput(GetActorUpVector(), 0.0f);
			if ((FMath::Abs(GetInputAxisValue("MoveForward")) < 0.2f && FMath::Abs(GetInputAxisValue("MoveRight")) < 0.2f) && savedVerticalAxis < 0.2 && savedHorizontalAxis < 0.2)
			{
				UE_LOG(LogClass, Log, TEXT("Stop flying from Tick()"));
				//StopFly();
				SwitchCharacter();
			}
			else if (savedVerticalAxis >= 0.2 || savedHorizontalAxis >= 0.2)
			{
				UE_LOG(LogClass, Log, TEXT("Reset Saved Values."));
				savedVerticalAxis = 0;
				savedHorizontalAxis = 0;
				/*AController* test = GetController();
				if (test == nullptr)
				{
					UE_LOG(LogClass, Log, TEXT("GetController() returns NULL."));
				}
				else
				{
					UE_LOG(LogClass, Log, TEXT("test is not null."));
				}*/
			}
		}
		/*if (GetCharacterMovement()->IsMovingOnGround() == true)
		{
			StopFly();
		}*/
	}

	//GetMovementComponent()->TickComponent(DeltaTime, LEVELTICK_All, PrimaryActorTick);
	//AddActorWorldOffset(ConsumeMovementInputVector() * baseSpeed, true);
	
}

// Called to bind functionality to input
void ATestPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	PlayerInputComponent->BindAxis("MoveForward", this, &ATestPlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATestPlayerPawn::MoveRight);

	PlayerInputComponent->BindAxis("TurnRate", this, &ATestPlayerPawn::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATestPlayerPawn::LookUpAtRate);

	PlayerInputComponent->BindAction("Jump", IE_Repeat, this, &ATestPlayerPawn::Ascend);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ATestPlayerPawn::StopAscend);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ATestPlayerPawn::SwitchCharacter);

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

void ATestPlayerPawn::Sprint()
{
	/*if (GetCharacterMovement()->IsFalling() == false)
	{
		if (isSprinting == false)
		{
			isSprinting = true;
			//GetCharacterMovement()->MinAnalogWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;

			//PowerChangeEffect();
			//UE_LOG(LogClass, Log, TEXT("sprinting is %s"), (isSprinting ? TEXT("true") : TEXT("False")));
			//UE_LOG(LogClass, Log, TEXT("MyCharacter's sprint speed is %f"), GetVelocity().Size());
			//UE_LOG(YourLog, Warning, TEXT("MyCharacter's Bool is %s"), (MyCharacter->MyBool ? TEXT("True") : TEXT("False")));
		}
		else
		{
			isSprinting = false;
			GetCharacterMovement()->MaxWalkSpeed = baseSpeed;
			GetCharacterMovement()->MinAnalogWalkSpeed = baseMinSpeed;
			sprintBoostBonus = sprintBoostBase;
			//UE_LOG(LogClass, Log, TEXT("MyCharacter's speed is %f"), GetVelocity().Size());
		}
	}*/
}

void ATestPlayerPawn::Jump()
{
	/*if (isJumping == false)
	{
		isJumping = true;
		CollisionCapsule->AddImpulse(FVector(0, 0, 1.0) * jumpForce, NAME_None, true);
	}*/
}

void ATestPlayerPawn::SwitchCharacter()
{
	APlayerController* controller = Cast<APlayerController>(GetController());
	if (controller != NULL)
	{
		UE_LOG(LogClass, Log, TEXT("Discovered Player Controller"));
		controller->UnPossess();
		Destroy();
		//ANPJ2018SeniorProjectCharacter* characterToSpawn = Cast<ANPJ2018SeniorProjectCharacter>(GetWorld()->SpawnActor(characterToSpawn->StaticClass()));
		ANPJ2018SeniorProjectCharacter* characterToSpawn = GetWorld()->SpawnActor<ANPJ2018SeniorProjectCharacter>(characterToSpawn->StaticClass(), GetActorLocation(), GetActorRotation());
		controller->Possess(characterToSpawn);
	}
}

void ATestPlayerPawn::SetSavedAxis(float vValue, float hValue)
{
	savedVerticalAxis = vValue;
	savedHorizontalAxis = hValue;
	isAscending = true;
}

void ATestPlayerPawn::SetCameraPosition(FVector newPosition, FRotator newRotation)
{
	//CameraBoom->SetRelativeLocation(newPosition, true);
	//CameraBoom->bUsePawnControlRotation = false;
	//CameraBoom->bInheritPitch = false;
	//CameraBoom->bInheritRoll = false;
	//CameraBoom->bInheritYaw = false;

	UE_LOG(LogClass, Log, TEXT("new Rotation Roll = %f"), newRotation.Roll);
	UE_LOG(LogClass, Log, TEXT("new Rotation Pitch = %f"), newRotation.Pitch);
	UE_LOG(LogClass, Log, TEXT("new Rotation Yaw = %f"), newRotation.Yaw);
	//CameraBoom->SetRelativeRotation(newRotation, true);
	/*AController* test = GetController();
	if (test == nullptr)
	{
		UE_LOG(LogClass, Log, TEXT("GetController() returns NULL."));
	}
	else
    { 
		UE_LOG(LogClass, Log, TEXT("test is not null."));
	}*/
	//FRotator test2 = GetControlRotation();
	//CameraBoom->bUsePawnControlRotation = true;
	GetController()->SetControlRotation(newRotation);
	UE_LOG(LogClass, Log, TEXT("CONTROL Roll = %f"), GetController()->GetControlRotation().Roll);
	UE_LOG(LogClass, Log, TEXT("CONTROL Pitch = %f"), GetController()->GetControlRotation().Pitch);
	UE_LOG(LogClass, Log, TEXT("CONTROL Yaw = %f"), GetController()->GetControlRotation().Yaw);
	
	//GetController()->SetControlRotation(newRotation);
	//CameraBoom->bUsePawnControlRotation = true;
	//CameraBoom->bInheritPitch = true;
	//CameraBoom->bInheritRoll = true;
	//CameraBoom->bInheritYaw = true;
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
		if (FMath::Abs(GetInputAxisValue("MoveForward")) < 0.2f && FMath::Abs(GetInputAxisValue("MoveRight")) < 0.2f)
		{
			StopFly();
		}
	}
}

void ATestPlayerPawn::Fly()
{
	/*if (GetCharacterMovement()->IsFalling() == true)
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		if (isGliding == true)
		{
			isGliding = false;
			//StopCrouch_Slide_Glide();
		}
		isFlying = true;
		//GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		//UMyCharacterMovementComponent* CustomMovement = CreateDefaultSubobject<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName);
		UMyCharacterMovementComponent* CustomMovement = Cast<UMyCharacterMovementComponent>(GetMovementComponent());
		//UMyCharacterMovementComponent* CustomMovement = new UMyCharacterMovementComponent;

		if (CustomMovement)
		{
			CustomMovement->SetMovementMode(MOVE_Custom);
			UE_LOG(LogClass, Log, TEXT("Custom Movement Exists."));
		}
		else
		{
			UE_LOG(LogClass, Log, TEXT("Custom Movement Doesn't Exist."));
		}
		//GetCharacterMovement()->AirControl = defaultAirControl;
		//GetCharacterMovement()->BrakingDecelerationFlying = 10000;
		//GetCharacterMovement()->bCheatFlying = true;
		//GetCharacterMovement()->bOrientRotationToMovement = false;
		//GetCharacterMovement()->bUseControllerDesiredRotation = true;
		isSprinting = false;

		//GetCharacterMovement()->MinAnalogWalkSpeed = baseMinSpeed;
		sprintBoostBonus = sprintBoostBase;
		//AddMovementInput(GetActorUpVector(), 1.0f);
		//UE_LOG(LogClass, Log, TEXT("Fly Please"));

	}*/
}

void ATestPlayerPawn::StopFly()
{
	/*if (isFlying == true)
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Falling);
		flightSpeedBonus = 100;
		GetCharacterMovement()->MaxFlySpeed = flightSpeedNormal;
		GetCharacterMovement()->MaxWalkSpeed = baseSpeed;
		GetCharacterMovement()->AirControl = defaultAirControl;
		//GetCharacterMovement()->GravityScale = 1;
		isFlying = false;
		if (GetCharacterMovement()->IsMovingOnGround() == false && isGliding == false)
		{
			
			isGliding = true;
		}
		//UE_LOG(LogClass, Log, TEXT("MyCharacter onGround is %s"), (GetCharacterMovement()->IsMovingOnGround() ? TEXT("True") : TEXT("False")));
	}*/

}

void ATestPlayerPawn::Crouch_Slide_Glide()
{
	//GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	//Crouch
	/*if (isCrouching == false && GetCharacterMovement()->IsMovingOnGround() == true && isSprinting == false)
	{
		isCrouching = true;
		buildUpSpeed = baseSpeed;
		GetCharacterMovement()->MaxWalkSpeed = 0;
		GetCharacterMovement()->SetJumpAllowed(false);
		//UE_LOG(LogClass, Log, TEXT("Crouch Please"));
	}
	//Crouch();
	//UE_LOG(LogClass, Log, TEXT("Crouch Please"));

	//Slide
	if (isSliding == false && GetCharacterMovement()->IsMovingOnGround() == true && isSprinting == true)
	{
		isSliding = true;
		isSprinting = false;
		GetCharacterMovement()->GroundFriction = 0.0f;
		GetCharacterMovement()->BrakingFrictionFactor = 0.0f;
		GetCharacterMovement()->BrakingDecelerationWalking = -600.0;
		//GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		//GetCharacterMovement()->BrakingDecelerationFlying = 10.0f;
		//UE_LOG(LogClass, Log, TEXT("MyCharacter's Ground Friction is %f"), GetCharacterMovement()->GroundFriction);
		//GetCharacterMovement()->Launch(GetActorForwardVector()*GetCharacterMovement()->MaxWalkSpeed);
		buildUpSpeed = baseSpeed;
		GetCharacterMovement()->MaxWalkSpeed *= 2;
		GetCharacterMovement()->MaxWalkSpeed = 0;

	}*/

	//Glide
	/*if (isGliding == false && GetCharacterMovement()->IsMovingOnGround() == false)
	{
	//UE_LOG(LogClass, Log, TEXT("Glide Please"));
	isGliding = true;
	if (isFlying == true)
	{
	StopFly();
	}

	float storedVelocity = GetCharacterMovement()->Velocity.Size();
	StopJumping();
	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	GetCharacterMovement()->MaxFlySpeed = 0;
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	GetCharacterMovement()->SetMovementMode(MOVE_Falling);
	GetCharacterMovement()->MaxFlySpeed = flightSpeedNormal;
	//StopJumping();
	//GetCharacterMovement()->bApplyGravityWhileJumping = true;


	//UE_LOG(LogClass, Log, TEXT("MyCharacter jumping is %s"), (IsJumping() ? TEXT("True") : TEXT("False")));
	//UE_LOG(LogClass, Log, TEXT("MyCharacter jumping 2 is %s"), (IsJumpProvidingForce() ? TEXT("True") : TEXT("False")));
	GetCharacterMovement()->GravityScale = 0.08f;

	GetCharacterMovement()->AirControl = 1.0f;
	flightSpeedBonus = 100;
	GetCharacterMovement()->MaxWalkSpeed = storedVelocity;
	//GetCharacterMovement()->MaxWalkSpeed = storedVelocity;

	GetCharacterMovement()->MaxWalkSpeed = FMath::Clamp(GetCharacterMovement()->MaxWalkSpeed, 0.0f, flightSpeedLimit);
	//UE_LOG(LogClass, Log, TEXT("MyCharacter's velocity is %f"), GetCharacterMovement()->MaxWalkSpeed);
	//GetCharacterMovement()->Launch(GetActorForwardVector() * GetCharacterMovement()->MaxWalkSpeed * (abs(GetInputAxisValue("MoveForward")) + abs(GetInputAxisValue("MoveRight"))));
	isSprinting = false;

	GetCharacterMovement()->MinAnalogWalkSpeed = baseMinSpeed;
	sprintBoostBonus = sprintBoostBase;
	}*/
}

void ATestPlayerPawn::StopCrouch_Slide_Glide()
{
	/*if ((isSliding == true || isCrouching == true) && GetCharacterMovement()->IsMovingOnGround() == true)
	{
		isCrouching = false;
		isSliding = false;
		GetCharacterMovement()->GroundFriction = 8.0f;
		GetCharacterMovement()->BrakingFrictionFactor = 1.0f;
		GetCharacterMovement()->BrakingDecelerationWalking = 2048.0;
		//GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		//GetCharacterMovement()->BrakingDecelerationFlying = 0.0f;
		GetCharacterMovement()->MinAnalogWalkSpeed = baseMinSpeed;
		sprintBoostBonus = sprintBoostBase;
		GetCharacterMovement()->SetJumpAllowed(true);
		if (buildUpSpeed > baseSpeed)
		{
			GetCharacterMovement()->MaxWalkSpeed = buildUpSpeed;
			Sprint();
		}
		else
		{
			GetCharacterMovement()->MaxWalkSpeed = baseSpeed;
		}

	}*/
	/*if (isGliding == true)
	{
	isGliding = false;

	//UE_LOG(LogClass, Log, TEXT("Stop Gliding Please"));
	GetCharacterMovement()->GravityScale = 1.0f;
	//GetCharacterMovement()->SetMovementMode(MOVE_Walking);

	GetCharacterMovement()->AirControl = defaultAirControl;
	if (GetCharacterMovement()->IsMovingOnGround() == true)
	{
	GetCharacterMovement()->MaxWalkSpeed = GetCharacterMovement()->MaxFlySpeed;
	isSprinting = true;
	Crouch_Slide_Glide();
	}
	else
	{
	GetCharacterMovement()->MaxWalkSpeed = baseSpeed;
	}
	}*/
	//UnCrouch();
	//UE_LOG(LogClass, Log, TEXT("UnCrouch Please"));
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

