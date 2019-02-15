// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseEnemyCharacter.generated.h"

UCLASS()
class NPJ2018SENIORPROJECT_API ABaseEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseEnemyCharacter();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UCapsuleComponent* GetCollisionRoot();

	UPROPERTY(EditAnywhere, Category = Behavior)
	class UBehaviorTree* enemyBehaviorTree;

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
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "AI Controller Class"), Category = Pawn)
	//TSubclassOf<AController> BaseEnemyController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	class USkeletalMeshComponent* EnemyCharacterMesh;

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
	bool isRecovering;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	float recoveryTime;

	FTimerHandle RecoveryTimer;

	FTimerHandle GrabThresholdTimer;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
	class UCapsuleComponent* CollisionRoot;


};
