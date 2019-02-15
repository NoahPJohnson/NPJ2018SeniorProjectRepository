// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class NPJ2018SENIORPROJECT_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool GetActive();
	
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool newPickupState);

	/*Function to call when pickup is collected*/
	//Combines blueprint and code implementation
	UFUNCTION(BlueprintNativeEvent) 
	void Collect();
	virtual void Collect_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool isActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Return mesh for the pickup
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

private:
	/** Static mesh to visualize element in level*/
	/**Forward declaration, we don't need to declare or include class*/
	/**Allows access from Blueprint and the level*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess=true))
	class UStaticMeshComponent* PickupMesh;
	
};
