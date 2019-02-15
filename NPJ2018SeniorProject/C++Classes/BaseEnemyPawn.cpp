// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEnemyPawn.h"
#include "BaseEnemyController.h"
#include "NPJ2018SeniorProjectCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

// Sets default values
ABaseEnemyPawn::ABaseEnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create static mesh component
	EnemyPawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyPawnMesh"));
	RootComponent = EnemyPawnMesh;


	isInsideBox = false;
	isAbleToCountDown = false;
	isGrabbed = false;
	grabThresholdStart = grabThreshold = 2.0;
	//recoveryState = false;
	//recoveryTime = 3.0;
}

// Called when the game starts or when spawned
void ABaseEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	AIControllerClass = ABaseEnemyController::StaticClass();
	
	SetPlayerReference();
}

// Called every frame
void ABaseEnemyPawn::Tick(float DeltaTime)
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
}

// Called to bind functionality to input
void ABaseEnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseEnemyPawn::SetPlayerReference()
{
	TArray<AActor*> FoundPlayer;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANPJ2018SeniorProjectCharacter::StaticClass(), FoundPlayer);
	if (FoundPlayer[0] != nullptr)
	{
		playerReference = FoundPlayer[0];
		//oldPlayerRelativeVector = FVector((playerReference->GetActorLocation().X - this->GetActorLocation().X), (playerReference->GetActorLocation().Y - this->GetActorLocation().Y), (playerReference->GetActorLocation().Z - this->GetActorLocation().Z));
	}
}

float ABaseEnemyPawn::GetGrabThreshold()
{
	return grabThreshold;
}

void ABaseEnemyPawn::StartGrabCountdown()
{
	GetWorldTimerManager().ClearTimer(GrabThresholdTimer);
	if (isInsideBox == false)
	{
		isInsideBox = true;
		isAbleToCountDown = true;
	}
}

void ABaseEnemyPawn::StartGrabCountUP()
{
	isAbleToCountDown = false;
	GetWorldTimerManager().SetTimer(GrabThresholdTimer, this, &ABaseEnemyPawn::SetInsideBoxFalse, 0.5f, false);
}

void ABaseEnemyPawn::SetInsideBoxFalse()
{
	isInsideBox = false;
}

void ABaseEnemyPawn::GetGrabbed()
{
	GetWorldTimerManager().ClearTimer(RecoveryTimer);
	isGrabbed = true;
	//ANPJ2018SeniorProjectCharacter * playerCall = Cast<ANPJ2018SeniorProjectCharacter>(playerReference);
	//playerCall->SetHoldingEnemy(true);
	AttachToActor(playerReference, FAttachmentTransformRules::KeepRelativeTransform);
	SetActorRelativeLocation(FVector(70.0, 0.0, 5.0));
	SetActorRelativeRotation(FRotator(0.0, 0.0, 0.0));
	SetActorEnableCollision(false);
	PrimaryActorTick.bCanEverTick = false;
	//AIControllerClass->SetAIState();
}

bool ABaseEnemyPawn::GetIsGrabbed()
{
	return isGrabbed;
}

void ABaseEnemyPawn::GetThrown(float force)
{
	if (isGrabbed == true)
	{
		SetActorRelativeLocation(FVector(130.0, 0.0, 5.0));
		DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
		EnemyPawnMesh->SetSimulatePhysics(true);
		EnemyPawnMesh->IgnoreActorWhenMoving(playerReference, true);
		SetActorEnableCollision(true);
		PrimaryActorTick.bCanEverTick = true;
		EnemyPawnMesh->AddImpulse((GetActorForwardVector() + GetActorUpVector() / 2)*force, NAME_None, true);
		isGrabbed = false;
		//recoveryState = true;
		// Set the timer on
		//GetWorldTimerManager().SetTimer(RecoveryTimer, this, &ABaseEnemyPawn::Recover, recoveryTime, false);

		//UE_LOG(LogClass, Log, TEXT("Forward = %f"), GetActorUpVector().Size());
		//UE_LOG(LogClass, Log, TEXT("Up = %f"), GetActorForwardVector().Size());
		//UE_LOG(LogClass, Log, TEXT("Force = %f"), force);
		UE_LOG(LogClass, Log, TEXT("Throw velocity = %f"), GetVelocity().Size());
	}
}

