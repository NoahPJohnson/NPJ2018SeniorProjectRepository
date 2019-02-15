// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEnemyController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NPJ2018SeniorProjectCharacter.h"
#include "C++Classes/BaseEnemyCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"



void ABaseEnemyController::Possess(APawn * InPawn)  
{
	Super::Possess(InPawn);

	selfReference = Cast<ABaseEnemyCharacter>(InPawn);
	if (selfReference != nullptr && selfReference->enemyBehaviorTree != nullptr)
	{
		UE_LOG(LogClass, Log, TEXT("possessing: %s"), *selfReference->GetName());
		BlackboardComponent->InitializeBlackboard(*selfReference->enemyBehaviorTree->BlackboardAsset);
		enemyKeyID = BlackboardComponent->GetKeyID("Target");
		BehaviorTreeComponent->StartTree(*selfReference->enemyBehaviorTree);
	}
}

// Sets default values
ABaseEnemyController::ABaseEnemyController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	recoveryState = false;
	recoveryTime = 3.0;
}

// Called when the game starts or when spawned
void ABaseEnemyController::BeginPlay()
{
	Super::BeginPlay();
	//Possess(ABaseEnemyPawn::StaticClass())
	//SetPlayerReference();
	
	//RunBehaviorTree(treeToRun);
	
	UE_LOG(LogClass, Log, TEXT("Run the Tree"));
	//SetAIState(EAIControllerState::EPacing);
}
/*
// Called every frame
void ABaseEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogClass, Log, TEXT("grabThreshold = %f"), grabThreshold);

	if (takingAction == false)
	{
		takingAction = true;
		GetWorldTimerManager().SetTimer(StateTimer, this, &ABaseEnemyController::DetermineAIState, 3.0, false);
	}

	HandleAIState(DeltaTime);
}*/


void ABaseEnemyController::SetPlayerReference()
{
	//TArray<AActor*> FoundPlayer;
	/*UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANPJ2018SeniorProjectCharacter::StaticClass(), FoundPlayer);
	if (FoundPlayer[0] != nullptr)
	{
		playerReference = FoundPlayer[0];
		oldPlayerRelativeVector = FVector((playerReference->GetActorLocation().X - this->GetActorLocation().X), (playerReference->GetActorLocation().Y - this->GetActorLocation().Y), (playerReference->GetActorLocation().Z - this->GetActorLocation().Z));
	}*/
}


void ABaseEnemyController::DetermineAIState()
{
	if (playerReference != nullptr)
	{
		/*playerRelativeVector = FVector((playerReference->GetActorLocation().X - this->GetActorLocation().X), (playerReference->GetActorLocation().Y - this->GetActorLocation().Y), (playerReference->GetActorLocation().Z - this->GetActorLocation().Z));
		UE_LOG(LogClass, Log, TEXT("Depth      Check = %f"), playerRelativeVector.X);
		UE_LOG(LogClass, Log, TEXT("Horizontal Check = %f"), playerRelativeVector.Y);
		UE_LOG(LogClass, Log, TEXT("Vertical   Check = %f"), playerRelativeVector.Z);
		FVector playerDeltaVector = playerRelativeVector - oldPlayerRelativeVector;
		moveVector = playerDeltaVector;
		oldPlayerRelativeVector = playerRelativeVector;
		takingAction = false;*/
	}
}

void ABaseEnemyController::SetAIState(EAIControllerState newState)
{

	CurrentState = newState;
	//HandleAIState(CurrentState);
}

void ABaseEnemyController::HandleAIState(float DeltaTime)
{
	switch (CurrentState)
	{
		//If the game is playing
	case EAIControllerState::EPacing:
	{
		//Player is engaged. Enemy is ready to attack. Move defensively (not too far, not retreating, not closing in). 
		if (playerReference != nullptr)
		{
			
			//FRotator targetRotation = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), playerReference->GetActorLocation());

			//FollowCamera->SetWorldRotation(FMath::RInterpTo(GetController()->GetControlRotation(), targetRotation, DeltaTime, 250.0f));

			//enemyRotation = FRotator(FMath::RInterpTo(this->GetActorRotation(), targetRotation, DeltaTime, 3.0f).Pitch, FMath::RInterpTo(this->GetActorRotation(), targetRotation, DeltaTime, 3.0f).Yaw, this->GetActorRotation().Roll);
			//this->SetActorRelativeRotation(enemyRotation);



		}
	}
	break;
	//If player is out of juice
	case EAIControllerState::EHitstun:
	{

	}
	break;
	//If player has all their juice
	case EAIControllerState::EAttack:
	{
		//Player is targeted. Enemy goes in for close attack or lines up a shot. Move purposefully.

	}
	break;
	default:
	case EAIControllerState::ENeutral:
	{

	}
	break;
	}
}



