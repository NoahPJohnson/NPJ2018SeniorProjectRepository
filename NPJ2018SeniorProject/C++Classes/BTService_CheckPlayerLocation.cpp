// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_CheckPlayerLocation.h"
#include "GameFramework/Character.h"
#include "BaseEnemyController.h"
#include "BaseEnemyCharacter.h"
#include "Engine.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



UBTService_CheckPlayerLocation::UBTService_CheckPlayerLocation()
{
	bCreateNodeInstance = true;
}

void UBTService_CheckPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory, float DeltaTime)
{
	ABaseEnemyController* EnemyController = Cast<ABaseEnemyController>(OwnerComponent.GetAIOwner());
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "ticking");
	if (EnemyController != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "enemy controller ok");
		ACharacter* player = Cast<ACharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (player != nullptr)
		{
			OwnerComponent.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyController->enemyKeyID, player);
			//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "ENEMY EXISTS");
		}
	}
}

