// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"


UCLASS()
class NPJ2018SENIORPROJECT_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/**The pickup to spawn*/
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> whatToSpawn;

	FTimerHandle SpawnTimer;

	/**Minimum spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;

	/*Maximum spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**Returns whereToSpawn subobject*/
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return whereToSpawn; };

	/**Find a random point within the BoxComponent*/
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

	/**This function toggles whether or not the spawn volumes should spawn pickups*/
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SetSpawningActive(bool bShouldSpawn);

private:
	/**Box Component to specify where pickups should be spawned*/
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = true))
	class UBoxComponent* whereToSpawn;
	
	/**Handle spawning a new pickup*/
	void SpawnPickup();

	/*The Current spawn delay*/
	float SpawnDelay;
};
