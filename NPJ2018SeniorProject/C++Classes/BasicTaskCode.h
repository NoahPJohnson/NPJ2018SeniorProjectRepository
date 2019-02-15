// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BasicTaskCode.generated.h"

/**
 * 
 */
UCLASS()
class NPJ2018SENIORPROJECT_API UBasicTaskCode : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBasicTaskCode();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};
