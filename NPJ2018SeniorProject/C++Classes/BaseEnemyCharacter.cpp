// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEnemyCharacter.h"
#include "NPJ2018SeniorProjectCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"

// Sets default values
ABaseEnemyCharacter::ABaseEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CollisionRoot = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionRoot"));
	/*if (CollisionRoot != nullptr)
	{
		CollisionRoot->SetCollisionProfileName(TEXT("Pawn"));
	}*/
	/*if (EnemyCharacterMesh != nullptr)
	{
		UE_LOG(LogClass, Log, TEXT("mesh is %s"), *this->GetMesh()->GetName());
	}*/
	//RootComponent = EnemyCharacterMesh;

	isInsideBox = false;
	isAbleToCountDown = false;
	isGrabbed = false;
	grabThresholdStart = grabThreshold = 0.3;
	recoveryTime = 3.0;
}

// Called when the game starts or when spawned
void ABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	EnemyCharacterMesh = this->GetMesh();

	if (this->GetMesh() != nullptr)
	{
		UE_LOG(LogClass, Log, TEXT("MESH = %s"), *this->GetMesh()->GetName());
	}
	if (CollisionRoot != nullptr && GetCapsuleComponent() != nullptr)
	{
		UE_LOG(LogClass, Log, TEXT("Collision Root is: %s"), *CollisionRoot->GetName());
		//CollisionRoot->bHiddenInGame = false;
		
		CollisionRoot->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		CollisionRoot->SetRelativeLocation(FVector(0.0, 0.0, 300.0));
		if (EnemyCharacterMesh != nullptr)
		{
			EnemyCharacterMesh->AttachToComponent(CollisionRoot, FAttachmentTransformRules::KeepWorldTransform);
			EnemyCharacterMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -80.0f));
			EnemyCharacterMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
		}
	}
	else
	{
		UE_LOG(LogClass, Log, TEXT("Collision Root is null?"));
	}
	SetPlayerReference();
}

// Called every frame
void ABaseEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isInsideBox == true)
	{
		if (isAbleToCountDown == true)
		{
			grabThreshold -= DeltaTime;
			if (grabThreshold < 0)
			{
				isInsideBox = false;
				grabThreshold = grabThresholdStart;
				GetGrabbed();
			}
		}
	}
	else
	{
		if (isGrabbed == false && grabThreshold < grabThresholdStart)
		{
			grabThreshold += DeltaTime;
			if (grabThreshold >= grabThresholdStart)
			{
				grabThreshold = grabThresholdStart;
			}
		}
	}

	if (EnemyCharacterMesh != nullptr)
	{
		if (EnemyCharacterMesh->IsSimulatingPhysics() == true)
		{
			SetActorLocation(FVector(EnemyCharacterMesh->GetSocketLocation("root")));
			SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
	}
	//UE_LOG(LogClass, Log, TEXT("GT = %f"), grabThreshold);
}

// Called to bind functionality to input
void ABaseEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseEnemyCharacter::SetPlayerReference()
{
	TArray<AActor*> FoundPlayer;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANPJ2018SeniorProjectCharacter::StaticClass(), FoundPlayer);
	if (FoundPlayer[0] != nullptr)
	{
		playerReference = FoundPlayer[0];
		//oldPlayerRelativeVector = FVector((playerReference->GetActorLocation().X - this->GetActorLocation().X), (playerReference->GetActorLocation().Y - this->GetActorLocation().Y), (playerReference->GetActorLocation().Z - this->GetActorLocation().Z));
	}
}

UCapsuleComponent* ABaseEnemyCharacter::GetCollisionRoot()
{
	return CollisionRoot;
}

float ABaseEnemyCharacter::GetGrabThreshold()
{
	return grabThreshold;
}

void ABaseEnemyCharacter::StartGrabCountdown()
{
	GetWorldTimerManager().ClearTimer(GrabThresholdTimer);
	UE_LOG(LogClass, Log, TEXT("start please"));
	if (isInsideBox == false)
	{
		isInsideBox = true;
		isAbleToCountDown = true;
	}
}

void ABaseEnemyCharacter::StartGrabCountUP()
{
	UE_LOG(LogClass, Log, TEXT("Count back up"));
	isAbleToCountDown = false;
	GetWorldTimerManager().SetTimer(GrabThresholdTimer, this, &ABaseEnemyCharacter::SetInsideBoxFalse, 0.5f, false);
}

void ABaseEnemyCharacter::SetInsideBoxFalse()
{
	UE_LOG(LogClass, Log, TEXT("STOP please"));
	isInsideBox = false;
}

void ABaseEnemyCharacter::GetGrabbed()
{
	GetWorldTimerManager().ClearTimer(RecoveryTimer);
	GetController()->StopMovement();
	
	GetCharacterMovement()->SetMovementMode(MOVE_None);
	isGrabbed = true;
	ANPJ2018SeniorProjectCharacter * playerCall = Cast<ANPJ2018SeniorProjectCharacter>(playerReference);
	playerCall->CameraLockOn();
	
	AttachToActor(playerReference, FAttachmentTransformRules::KeepWorldTransform);
	SetActorRelativeLocation(FVector(70.0, 0.0, 5.0));
	SetActorRelativeRotation(FRotator(0.0, 0.0, 0.0));
	if (CollisionRoot != nullptr)
	{
		CollisionRoot->SetRelativeLocation(FVector(0.0, 0.0, 0.0));
	}
	SetActorEnableCollision(false);
	PrimaryActorTick.bCanEverTick = false;
	//AIControllerClass->SetAIState();
}

bool ABaseEnemyCharacter::GetIsGrabbed()
{
	return isGrabbed;
}

void ABaseEnemyCharacter::GetThrown(float force)
{
	if (isGrabbed == true)
	{
		//SetActorRelativeLocation(FVector(130.0, 0.0, 5.0));
		DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		SetActorEnableCollision(true);
		
		PrimaryActorTick.bCanEverTick = true;
		if (EnemyCharacterMesh != nullptr)
		{
			EnemyCharacterMesh->SetSimulatePhysics(true);
			EnemyCharacterMesh->IgnoreActorWhenMoving(playerReference, true);
			EnemyCharacterMesh->AddImpulse((GetActorForwardVector() + GetActorUpVector() / 2)*force, NAME_None, true);
			UE_LOG(LogClass, Log, TEXT("No Problem"));
		}
		isGrabbed = false;
		isRecovering = true;
		// Set the timer on
		GetWorldTimerManager().SetTimer(RecoveryTimer, this, &ABaseEnemyCharacter::Recover, recoveryTime, false);

		//UE_LOG(LogClass, Log, TEXT("Forward = %f"), GetActorUpVector().Size());
		//UE_LOG(LogClass, Log, TEXT("Up = %f"), GetActorForwardVector().Size());
		//UE_LOG(LogClass, Log, TEXT("Force = %f"), force);
		UE_LOG(LogClass, Log, TEXT("Throw velocity = %f"), GetVelocity().Size());
		//UE_LOG(LogClass, Log, TEXT("new location x = %f"), GetActorLocation().X);
		//UE_LOG(LogClass, Log, TEXT("new Y = %f"), GetActorLocation().Y);
		//UE_LOG(LogClass, Log, TEXT("and Z = %f"), GetActorLocation().Z);
	}
}

void ABaseEnemyCharacter::Recover()
{
	if (isRecovering == true)
	{
		if (EnemyCharacterMesh != nullptr)
		{
			isRecovering = false;
			EnemyCharacterMesh->SetSimulatePhysics(false);
			EnemyCharacterMesh->IgnoreActorWhenMoving(playerReference, false);
			
			GetCharacterMovement()->SetMovementMode(MOVE_Walking);
			SetActorLocation(FVector(EnemyCharacterMesh->GetSocketLocation("root"))+FVector(0.0,0.0,7.0));
			SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
			if (CollisionRoot != nullptr && GetCapsuleComponent() != nullptr)
			{
				UE_LOG(LogClass, Log, TEXT("Collision Root is: %s"), *CollisionRoot->GetName());
				//CollisionRoot->bHiddenInGame = false;
				CollisionRoot->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepRelativeTransform);
				CollisionRoot->SetRelativeLocation(FVector(0.0, 0.0, 300.0));
				if (EnemyCharacterMesh != nullptr)
				{
					EnemyCharacterMesh->AttachToComponent(CollisionRoot, FAttachmentTransformRules::KeepWorldTransform);
					EnemyCharacterMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -80.0f));
					EnemyCharacterMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
				}
			}
			/*if (CollisionRoot != nullptr)
			{
				//EnemyCharacterMesh->AttachToComponent(CollisionRoot, FAttachmentTransformRules::KeepWorldTransform);
				//EnemyCharacterMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -80.0f));
				//EnemyCharacterMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
			}*/
		}
	}
}

