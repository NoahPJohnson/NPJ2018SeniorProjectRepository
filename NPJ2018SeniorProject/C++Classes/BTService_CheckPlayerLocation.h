// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_CheckPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class NPJ2018SENIORPROJECT_API UBTService_CheckPlayerLocation : public UBTService
{
	GENERATED_BODY()
	
public:

	UBTService_CheckPlayerLocation();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory, float DeltaTime) override;
	
	
};
