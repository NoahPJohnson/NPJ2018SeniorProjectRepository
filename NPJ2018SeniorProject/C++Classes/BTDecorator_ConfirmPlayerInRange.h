// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BTDecorator_ConfirmPlayerInRange.generated.h"

/**
 * 
 */
UCLASS()
class NPJ2018SENIORPROJECT_API UBTDecorator_ConfirmPlayerInRange : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()

public:
		UBTDecorator_ConfirmPlayerInRange();
	
		//virtual void OnNodeActivation(FBehaviorTreeSearchData& SearchData) override;

		virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

		//virtual EBlackboardNotificationResult OnBlackboardKeyValueChange(const UBlackboardComponent& Blackboard, FBlackboard::FKey ChangedKeyID) override;

		virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
};
