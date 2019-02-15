// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "C++Classes/Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class NPJ2018SENIORPROJECT_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABatteryPickup();
	
	/*Override the collect function*/
	void Collect_Implementation() override;

	/*Public access for the power level*/
	float GetPower();
protected:
	/*Set the amount of power the battery gives to the character*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BluePrintProtected = true))
	float batteryPower;
};
