// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"
#include "Components/StaticMeshComponent.h"


//Set default values
ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);
	batteryPower = 150.f;
}

void ABatteryPickup::Collect_Implementation()
{
	//Use the base pickup behavior
	Super::Collect_Implementation();
	//Destroy the battery
	Destroy();
}

float ABatteryPickup::GetPower()
{
	return batteryPower;
}