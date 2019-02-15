// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BTDecorator_CheckIsGrabbed.generated.h"

/**
 * 
 */
UCLASS()
class NPJ2018SENIORPROJECT_API UBTDecorator_CheckIsGrabbed : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTDecorator_CheckIsGrabbed();

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
	
	
};
