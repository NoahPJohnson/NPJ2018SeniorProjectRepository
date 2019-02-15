// Fill out your copyright notice in the Description page of Project Settings.

#include "TestTaskCode.h"
#include "GameFramework/Character.h"
#include "BaseEnemyController.h"
#include "BaseEnemyCharacter.h"
#include "Engine.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

UTestTaskCode::UTestTaskCode()
{

}

EBTNodeResult::Type UTestTaskCode::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* NodeMemory)
{
	ABaseEnemyController* CharacterController = Cast<ABaseEnemyController>(ownerComponent.GetAIOwner());
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "Task Execute");
	if (CharacterController != nullptr)
	{
		ACharacter* player = Cast<ACharacter>(ownerComponent.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharacterController->enemyKeyID));
		if (player != nullptr)
		{
			if ((CharacterController->GetPawn()->GetActorLocation() - player->GetActorLocation()).Size() > 1100)
			{
				CharacterController->MoveToActor(player, 5.0f, true, true, true, 0, true);
				//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "Task Execute For REAL");
				UE_LOG(LogClass, Log, TEXT("Task Execute"));
			}
			else
			{
				CharacterController->StopMovement();
				//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "It is time to stoooooop.");
			}
			return EBTNodeResult::Succeeded;
		}
		else
		{
			
			return EBTNodeResult::Failed;
		}
	}

	

	
	return EBTNodeResult::Failed;
}


