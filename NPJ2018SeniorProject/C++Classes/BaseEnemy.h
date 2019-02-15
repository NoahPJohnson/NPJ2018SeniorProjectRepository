// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEnemy.generated.h"


//enum to store the current state of gameplay
UENUM(BlueprintType)
enum class EAIState : uint8
{
	ENeutral,
	EPacing,
	EAttack,
	EHitstun
};

UCLASS()
class NPJ2018SENIORPROJECT_API ABaseEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void DetermineAIState();

	void SetAIState(EAIState newState);

	void HandleAIState(float DeltaTime);

	void SetPlayerReference();

	float GetGrabThreshold();

	void StartGrabCountdown();

	void StartGrabCountUP();

	void SetInsideBoxFalse();

	bool GetIsGrabbed();

	void GetGrabbed();

	void GetThrown(float);

	void Recover();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	class UStaticMeshComponent* EnemyMesh;

	AActor * playerReference;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	bool isInsideBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	bool isAbleToCountDown;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	bool isGrabbed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	float grabThreshold;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	float grabThresholdStart;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	bool recoveryState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	float recoveryTime;

	FTimerHandle RecoveryTimer;

	FTimerHandle GrabThresholdTimer;

	FTimerHandle StateTimer;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy Movement", meta = (AllowPrivateAccess = true))
	float maxDistance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy Movement", meta = (AllowPrivateAccess = true))
	float speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy Movement", meta = (AllowPrivateAccess = true))
	FVector oldPlayerRelativeVector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy Movement", meta = (AllowPrivateAccess = true))
	FVector playerRelativeVector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy Movement", meta = (AllowPrivateAccess = true))
	FVector moveVector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy Movement", meta = (AllowPrivateAccess = true))
	FRotator enemyRotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy Movement", meta = (AllowPrivateAccess = true))
	bool takingAction;

	EAIState CurrentState;
};
