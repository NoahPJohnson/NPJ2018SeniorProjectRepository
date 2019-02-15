// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_CheckIsGrabbed.h"
#include "C++Classes/BaseEnemyController.h"
#include "C++Classes/BaseEnemyCharacter.h"
#include "Engine.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

UBTDecorator_CheckIsGrabbed::UBTDecorator_CheckIsGrabbed()
{

}

bool UBTDecorator_CheckIsGrabbed::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	ABaseEnemyController* EnemyController = Cast<ABaseEnemyController>(OwnerComp.GetAIOwner());
	if (EnemyController)
	{
		ABaseEnemyCharacter* enemyCharacter = Cast<ABaseEnemyCharacter>(EnemyController->GetCharacter());
		if (enemyCharacter)
		{
			if (enemyCharacter->GetIsGrabbed() == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

