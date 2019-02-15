// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "TestTaskCode.generated.h"

/**
 * 
 */
UCLASS()
class NPJ2018SENIORPROJECT_API UTestTaskCode : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
	public:
		UTestTaskCode();

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};
