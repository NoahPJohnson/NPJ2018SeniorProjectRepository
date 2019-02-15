// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_ConfirmPlayerInRange.h"
#include "C++Classes/BaseEnemyController.h"
#include "Engine.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

UBTDecorator_ConfirmPlayerInRange::UBTDecorator_ConfirmPlayerInRange()
{

}

/*void UBTDecorator_ConfirmPlayerInRange::OnNodeActivation(FBehaviorTreeSearchData& SearchData)
{

}*/

void UBTDecorator_ConfirmPlayerInRange::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
}

/*EBlackboardNotificationResult UBTDecorator_ConfirmPlayerInRange::OnBlackboardKeyValueChange(const UBlackboardComponent& Blackboard, FBlackboard::FKey ChangedKeyID)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "KeyChanged");
	return EBlackboardNotificationResult::ContinueObserving;
}*/

bool UBTDecorator_ConfirmPlayerInRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	ABaseEnemyController* EnemyController = Cast<ABaseEnemyController>(OwnerComp.GetAIOwner());
	if (EnemyController)
	{
		ACharacter* player = Cast<ACharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (player != nullptr)
		{
			if ((player->GetActorLocation() - EnemyController->GetPossessedPawn()->GetActorLocation()).Size() < 1700.0f)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "Inside Range");
				return false;
			}
			else
			{
				return true;
			}
			//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "Check Condition");
		}
	}
	return false;
}


