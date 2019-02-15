// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEnemy.h"
#include "NPJ2018SeniorProjectCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"


// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Create static mesh component
	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	RootComponent = EnemyMesh;


	

	isInsideBox = false;
	isAbleToCountDown = false;
	isGrabbed = false;
	grabThresholdStart = grabThreshold = 2.0;
	recoveryState = false;
	recoveryTime = 3.0;
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	SetPlayerReference();

	SetAIState(EAIState::EPacing);
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogClass, Log, TEXT("grabThreshold = %f"), grabThreshold);
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

	if (takingAction == false)
	{
		takingAction = true;
		GetWorldTimerManager().SetTimer(StateTimer, this, &ABaseEnemy::DetermineAIState, 3.0, false);
	}

	HandleAIState(DeltaTime);
}


void ABaseEnemy::SetPlayerReference()
{
	TArray<AActor*> FoundPlayer;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANPJ2018SeniorProjectCharacter::StaticClass(), FoundPlayer);
	if (FoundPlayer[0] != nullptr)
	{
		playerReference = FoundPlayer[0];
		oldPlayerRelativeVector = FVector((playerReference->GetActorLocation().X - this->GetActorLocation().X), (playerReference->GetActorLocation().Y - this->GetActorLocation().Y), (playerReference->GetActorLocation().Z - this->GetActorLocation().Z));
	}
}

float ABaseEnemy::GetGrabThreshold()
{
	return grabThreshold;
}

void ABaseEnemy::StartGrabCountdown()
{
	GetWorldTimerManager().ClearTimer(GrabThresholdTimer);
	if (isInsideBox == false)
	{
		isInsideBox = true;
		isAbleToCountDown = true;
	}
}

void ABaseEnemy::StartGrabCountUP()
{
	isAbleToCountDown = false;
	GetWorldTimerManager().SetTimer(GrabThresholdTimer, this, &ABaseEnemy::SetInsideBoxFalse, 0.5f, false);
}

void ABaseEnemy::SetInsideBoxFalse()
{
	isInsideBox = false;
}

void ABaseEnemy::GetGrabbed()
{
	GetWorldTimerManager().ClearTimer(RecoveryTimer);
	isGrabbed = true;
	//ANPJ2018SeniorProjectCharacter * playerCall = Cast<ANPJ2018SeniorProjectCharacter>(playerReference);
	//playerCall->SetHoldingEnemy(true);
	AttachToActor(playerReference, FAttachmentTransformRules::KeepRelativeTransform);
	SetActorRelativeLocation(FVector(70.0, 0.0, 5.0));
	SetActorRelativeRotation(FRotator(0.0, 0.0, 0.0));
	SetActorEnableCollision(false);
	
	
}

bool ABaseEnemy::GetIsGrabbed()
{
	return isGrabbed;
}

void ABaseEnemy::GetThrown(float force)
{
	if (isGrabbed == true)
	{
		SetActorRelativeLocation(FVector(130.0, 0.0, 5.0));
		DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
		EnemyMesh->SetSimulatePhysics(true);
		EnemyMesh->IgnoreActorWhenMoving(playerReference, true);
		SetActorEnableCollision(true);
		EnemyMesh->AddImpulse((GetActorForwardVector() + GetActorUpVector() / 2)*force, NAME_None, true);
		isGrabbed = false;
		recoveryState = true;
		// Set the timer on
		GetWorldTimerManager().SetTimer(RecoveryTimer, this, &ABaseEnemy::Recover, recoveryTime, false);

		//UE_LOG(LogClass, Log, TEXT("Forward = %f"), GetActorUpVector().Size());
		//UE_LOG(LogClass, Log, TEXT("Up = %f"), GetActorForwardVector().Size());
		//UE_LOG(LogClass, Log, TEXT("Force = %f"), force);
		UE_LOG(LogClass, Log, TEXT("Throw velocity = %f"), GetVelocity().Size());
	}
}

void ABaseEnemy::Recover()
{
	if (recoveryState == true)
	{
		EnemyMesh->SetSimulatePhysics(false);
		EnemyMesh->IgnoreActorWhenMoving(playerReference, false);
	}
}

void ABaseEnemy::DetermineAIState()
{
	if (playerReference != nullptr)
	{
		playerRelativeVector = FVector((playerReference->GetActorLocation().X - this->GetActorLocation().X), (playerReference->GetActorLocation().Y - this->GetActorLocation().Y), (playerReference->GetActorLocation().Z - this->GetActorLocation().Z));
		UE_LOG(LogClass, Log, TEXT("Depth      Check = %f"), playerRelativeVector.X);
		UE_LOG(LogClass, Log, TEXT("Horizontal Check = %f"), playerRelativeVector.Y);
		UE_LOG(LogClass, Log, TEXT("Vertical   Check = %f"), playerRelativeVector.Z);
		FVector playerDeltaVector = playerRelativeVector - oldPlayerRelativeVector;
		moveVector = playerDeltaVector;
		oldPlayerRelativeVector = playerRelativeVector;
		takingAction = false;
	}
}

void ABaseEnemy::SetAIState(EAIState newState)
{

	CurrentState = newState;
	//HandleAIState(CurrentState);
}

void ABaseEnemy::HandleAIState(float DeltaTime)
{
	switch (CurrentState)
	{
		//If the game is playing
		case EAIState::EPacing:
		{
			//Player is engaged. Enemy is ready to attack. Move defensively (not too far, not retreating, not closing in). 
			if (playerReference != nullptr)
			{
				FRotator targetRotation = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), playerReference->GetActorLocation());
				
				//FollowCamera->SetWorldRotation(FMath::RInterpTo(GetController()->GetControlRotation(), targetRotation, DeltaTime, 250.0f));

				enemyRotation = FRotator(FMath::RInterpTo(this->GetActorRotation(), targetRotation, DeltaTime, 3.0f).Pitch, FMath::RInterpTo(this->GetActorRotation(), targetRotation, DeltaTime, 3.0f).Yaw, this->GetActorRotation().Roll);
				this->SetActorRelativeRotation(enemyRotation);
				
				
				
			}
		}
		break;
		//If player is out of juice
		case EAIState::EHitstun:
		{

		}
		break;
		//If player has all their juice
		case EAIState::EAttack:
		{
			//Player is targeted. Enemy goes in for close attack or lines up a shot. Move purposefully.

		}
		break;
	default:
		case EAIState::ENeutral:
		{

		}
		break;
	}
}




