// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "NPJ2018SeniorProjectCharacter.h"
//#include "C++Classes/Pickup.h"
//#include "C++Classes/BatteryPickup.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
//#include "Vector.h"
#include <cmath>
#include "TimerManager.h"


//////////////////////////////////////////////////////////////////////////
// ANPJ2018SeniorProjectCharacter

ANPJ2018SeniorProjectCharacter::ANPJ2018SeniorProjectCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//Create Collection sphere
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(200.f);
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

    //Set a base power level for the character
	initialPower = 2000.f;
	characterPower = initialPower;

	//Sprinting stuff
	baseSpeed = GetCharacterMovement()->MaxWalkSpeed;
	sprintSpeedBonus = 800.0f;
	sprintBoostLimit = GetCharacterMovement()->MaxWalkSpeed + sprintSpeedBonus;
	sprintBoostAcceleration = 500.0f;
	sprintBoostBonus = sprintBoostBase = -200.0f;
	isSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = baseSpeed;
	baseMinSpeed = GetCharacterMovement()->MinAnalogWalkSpeed;
	//GetCharacterMovement()->MaxWalkSpeed = 1400;

	//Flying stuff
	//defaultAirControl = GetCharacterMovement()->AirControl;
	defaultAirControl = 0.5f;
	GetCharacterMovement()->AirControl = defaultAirControl;
	GetCharacterMovement()->MaxFlySpeed = 200;
	flightSpeedLimit = 1400;
	flightSpeedBonus = 200;
	flightSpeedBonusAcceleration = 450;

	//Crouching/Sliding/Gliding stuff
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	isCrouching = false;
	isSliding = false;
	buildUpSpeedIncrease = 550.0f;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ANPJ2018SeniorProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ANPJ2018SeniorProjectCharacter::Fly);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ANPJ2018SeniorProjectCharacter::StopFly);

	PlayerInputComponent->BindAction("Collect", IE_Released, this, &ANPJ2018SeniorProjectCharacter::CollectPickups);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ANPJ2018SeniorProjectCharacter::Sprint);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ANPJ2018SeniorProjectCharacter::Crouch_Slide_Glide);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ANPJ2018SeniorProjectCharacter::StopCrouch_Slide_Glide);

	PlayerInputComponent->BindAxis("MoveForward", this, &ANPJ2018SeniorProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ANPJ2018SeniorProjectCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ANPJ2018SeniorProjectCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ANPJ2018SeniorProjectCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ANPJ2018SeniorProjectCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ANPJ2018SeniorProjectCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ANPJ2018SeniorProjectCharacter::OnResetVR);
}


void ANPJ2018SeniorProjectCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ANPJ2018SeniorProjectCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ANPJ2018SeniorProjectCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ANPJ2018SeniorProjectCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ANPJ2018SeniorProjectCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ANPJ2018SeniorProjectCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		if (isSprinting == true)
		{
			AddMovementInput(Direction / 20, Value);
		}
		else
		{
			AddMovementInput(Direction, Value);
		}
		//GetInputAxisValue("MoveForward");
		//UE_LOG(LogClass, Log, TEXT("left Y is %f"), GetInputAxisValue("MoveForward"));
	}
}

void ANPJ2018SeniorProjectCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		
		//float newYaw = Rotation.Yaw;;
		//UE_LOG(LogClass, Log, TEXT("MyCharacter's rotation is %f"), newYaw);
		//const FRotator YawRotation(0, newYaw, 0);
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		if (isSprinting == true)
		{
			AddMovementInput(Direction / 20, Value);
		}
		else
		{
			AddMovementInput(Direction, Value);
		}
		
		
		//UE_LOG(LogClass, Log, TEXT("LEFT X is %f"), GetInputAxisValue("MoveRight"));
	}
}

void ANPJ2018SeniorProjectCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//Handle Sprint
	if (abs(GetInputAxisValue("MoveForward")) < 0.2f && abs(GetInputAxisValue("MoveRight")) < 0.2f && isSprinting == true && isSliding == false)
	{
		isSprinting = false;
		GetCharacterMovement()->MaxWalkSpeed = baseSpeed;
		GetCharacterMovement()->MinAnalogWalkSpeed = baseMinSpeed;
		sprintBoostBonus = sprintBoostBase;
		//UE_LOG(LogClass, Log, TEXT("Stopped sprinting because inputs too shallow"));
	}
	if (isSprinting == true && isSliding == false)
	{
		AddMovementInput(GetActorForwardVector(), 1.0f);
		if (GetCharacterMovement()->MaxWalkSpeed < sprintBoostLimit)
		{
			sprintBoostBonus += sprintBoostAcceleration * DeltaTime;
			GetCharacterMovement()->MaxWalkSpeed += sprintBoostBonus * DeltaTime;
			GetCharacterMovement()->MaxWalkSpeed = FMath::Clamp(GetCharacterMovement()->MaxWalkSpeed, 0.0f, sprintBoostLimit);
			//GetCharacterMovement()->MinAnalogWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;

			//UE_LOG(LogClass, Log, TEXT("MyCharacter's sprint bonus is %f"), sprintBoostBonus);
			//UE_LOG(LogClass, Log, TEXT("MyCharacter's max speed is %f"), GetCharacterMovement()->MaxWalkSpeed);
			//UE_LOG(LogClass, Log, TEXT("MyCharacter's speed is %f"), GetVelocity().Size());
		}
	}


	//Handle Flight
	if (isFlying == true)
	{
		if (GetCharacterMovement()->MaxFlySpeed < flightSpeedLimit)
		{
			flightSpeedBonus += flightSpeedBonusAcceleration * DeltaTime;
			GetCharacterMovement()->MaxFlySpeed += flightSpeedBonus * DeltaTime;
			GetCharacterMovement()->MaxFlySpeed = FMath::Clamp(GetCharacterMovement()->MaxFlySpeed, 0.0f, flightSpeedLimit);
		}
		AddMovementInput(GetActorUpVector(), 0.7f);

		if (GetCharacterMovement()->IsMovingOnGround() == true)
		{
			StopFly();
		}
	}

	if (GetCharacterMovement()->IsMovingOnGround() == true && (flightSpeedBonus > 100 || GetCharacterMovement()->MaxFlySpeed > 200))
	{
		flightSpeedBonus = 100;
		GetCharacterMovement()->MaxFlySpeed = 200;
	}

	//Handle Gliding
	if (isGliding == true)
	{
		if (GetCharacterMovement()->MaxWalkSpeed < flightSpeedLimit)
		{
			flightSpeedBonus += flightSpeedBonusAcceleration * DeltaTime;
			GetCharacterMovement()->MaxWalkSpeed += flightSpeedBonus * DeltaTime;
			GetCharacterMovement()->MaxWalkSpeed = FMath::Clamp(GetCharacterMovement()->MaxFlySpeed, 0.0f, flightSpeedLimit);
		}
		if (GetCharacterMovement()->MaxFlySpeed < flightSpeedLimit)
		{
			flightSpeedBonus += flightSpeedBonusAcceleration * DeltaTime;
			GetCharacterMovement()->MaxFlySpeed += flightSpeedBonus * DeltaTime;
			GetCharacterMovement()->MaxFlySpeed = FMath::Clamp(GetCharacterMovement()->MaxFlySpeed, 0.0f, flightSpeedLimit);
		}

		if (GetCharacterMovement()->IsMovingOnGround() == true)
		{
			StopCrouch_Slide_Glide();
		}
	}

	//Handle Crouch / Slide
	if ((isSliding == true || isCrouching == true) && (abs(GetInputAxisValue("MoveForward")) >= 0.2f || abs(GetInputAxisValue("MoveRight")) >= 0.2f))
	{
		if (buildUpSpeed < sprintBoostLimit)
		{
			buildUpSpeed += buildUpSpeedIncrease * DeltaTime;
			//UE_LOG(LogClass, Log, TEXT("We built up this speed: %f"), buildUpSpeed);
		}
		else
		{
			//UE_LOG(LogClass, Log, TEXT("We built up this speed: %f"), buildUpSpeed);
		}
	}
	else if ((isSliding == true || isCrouching == true) && (abs(GetInputAxisValue("MoveForward")) < 0.2f || abs(GetInputAxisValue("MoveRight")) < 0.2f))
	{
		buildUpSpeed = baseSpeed;
	}

	//UE_LOG(LogClass, Log, TEXT("MyCharacter's speed is %f"), GetVelocity().Size());
	PowerChangeEffect();
}

void ANPJ2018SeniorProjectCharacter::CollectPickups()
{
	//UE_LOG(LogClass, Log, TEXT("You have pressed the button"));
	//Get all overlapping actors and store them in an array
	/*TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);

	float collectedPower = 0;

	//For each collected actor...
	for (int iCollected = 0; iCollected < CollectedActors.Num(); iCollected++)
	{
		//Cast the actor to a pickup
		APickup* const TestPickup = Cast<APickup>(CollectedActors[iCollected]);
		//If the cast is successful and the pickup is valid and active
		if (TestPickup && !TestPickup->IsPendingKill() && TestPickup->GetActive())
		{
			//Call the pickup's collect function
			TestPickup->Collect();
			//Check to see if the pickup is also a battery
			ABatteryPickup* const testBattery = Cast<ABatteryPickup>(TestPickup);
			if (testBattery)
			{
				//increase the collected power
				//collectedPower += testBattery->GetPower();
			}
			//Deactivates the pickup
			TestPickup->SetActive(false);
		}
	}
	if (collectedPower > 0)
	{
		UpdateCharacterPower(collectedPower);
	}*/
}

void ANPJ2018SeniorProjectCharacter::Sprint()
{
	if (GetCharacterMovement()->IsFalling() == false)
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
	}
}

void ANPJ2018SeniorProjectCharacter::Fly()
{
	if (GetCharacterMovement()->IsFalling() == true)
	{
		if (isGliding == true)
		{
			StopCrouch_Slide_Glide();
		}
		isFlying = true;
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		
		isSprinting = false;

		GetCharacterMovement()->MinAnalogWalkSpeed = baseMinSpeed;
		sprintBoostBonus = sprintBoostBase;
		//AddMovementInput(GetActorUpVector(), 1.0f);
		//UE_LOG(LogClass, Log, TEXT("Fly Please"));
	}
}

void ANPJ2018SeniorProjectCharacter::StopFly()
{
	if (isFlying == true)
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		flightSpeedBonus = 100;
		GetCharacterMovement()->MaxFlySpeed = 200;
		GetCharacterMovement()->MaxWalkSpeed = baseSpeed;
		GetCharacterMovement()->AirControl = defaultAirControl;
		//GetCharacterMovement()->GravityScale = 1;
		isFlying = false;
		
	}
	if (GetCharacterMovement()->IsMovingOnGround() == false)
	{
		GetCharacterMovement()->Launch((GetActorUpVector() * 400) + ((GetActorForwardVector() * GetCharacterMovement()->MaxFlySpeed) * (abs(GetInputAxisValue("MoveForward")) + abs(GetInputAxisValue("MoveRight")))));
	}
}

void ANPJ2018SeniorProjectCharacter::Crouch_Slide_Glide()
{
	//GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	//Crouch
	if (isCrouching == false && GetCharacterMovement()->IsMovingOnGround() == true && isSprinting == false)
	{
		isCrouching = true;
		buildUpSpeed = baseSpeed;
		GetCharacterMovement()->MaxWalkSpeed = 0;
		GetCharacterMovement()->SetJumpAllowed(false);
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
		GetCharacterMovement()->BrakingDecelerationWalking = 700.0;
		//GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		//GetCharacterMovement()->BrakingDecelerationFlying = 10.0f;
		//UE_LOG(LogClass, Log, TEXT("MyCharacter's Ground Friction is %f"), GetCharacterMovement()->GroundFriction);
		//GetCharacterMovement()->Launch(GetActorForwardVector()*GetCharacterMovement()->MaxWalkSpeed);
		buildUpSpeed = baseSpeed;
		GetCharacterMovement()->MaxWalkSpeed = 0;
		
	}

	//Glide
	if (isGliding == false && GetCharacterMovement()->IsMovingOnGround() == false)
	{
		isGliding = true;
		if (isFlying == true)
		{
			StopFly();
		}
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		//GetCharacterMovement()->bApplyGravityWhileJumping = true;
		

		GetCharacterMovement()->GravityScale = 0.08f;
		
		GetCharacterMovement()->AirControl = 1.0f;
		flightSpeedBonus = 100;
		GetCharacterMovement()->MaxFlySpeed = 200;
		GetCharacterMovement()->MaxWalkSpeed = GetCharacterMovement()->Velocity.Size();
		GetCharacterMovement()->MaxWalkSpeed = FMath::Clamp(GetCharacterMovement()->MaxFlySpeed, 0.0f, flightSpeedLimit);
		isSprinting = false;

		GetCharacterMovement()->MinAnalogWalkSpeed = baseMinSpeed;
		sprintBoostBonus = sprintBoostBase;
	}
}

void ANPJ2018SeniorProjectCharacter::StopCrouch_Slide_Glide()
{
	if ((isSliding == true || isCrouching == true) && GetCharacterMovement()->IsMovingOnGround() == true)
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
		
	}
	if (isGliding == true)
	{
		isGliding = false;
		//UE_LOG(LogClass, Log, TEXT("Stop Gliding Please"));
		GetCharacterMovement()->GravityScale = 1.0f;
		//GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		GetCharacterMovement()->MaxWalkSpeed = baseSpeed;
		GetCharacterMovement()->AirControl = defaultAirControl;
	}
	//UnCrouch();
	//UE_LOG(LogClass, Log, TEXT("UnCrouch Please"));
}

float ANPJ2018SeniorProjectCharacter::GetInitialPower()
{
	return initialPower;
}

float ANPJ2018SeniorProjectCharacter::GetCurrentPower()
{
	return characterPower;
}

//Called whenever power is increased or decreased
void ANPJ2018SeniorProjectCharacter::UpdateCharacterPower(float powerChange)
{
	if (characterPower < (initialPower*1.25))
	{
		characterPower += powerChange;
		//Part of all character classes
		//GetCharacterMovement()->MaxWalkSpeed = baseSpeed + speedFactor * characterPower;
	}
	//Call visual effect
	PowerChangeEffect();
}
