// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"


UCLASS()
class NPJ2018SENIORPROJECT_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

protected:

	//Constructor
	UMyCharacterMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//Init
	//virtual void InitializeComponent() override;

	//Tick
	//virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

protected:
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;
public:
	virtual void SetMovementMode(EMovementMode NewMovementMode, uint8 NewCustomMode = 0) override;
};
