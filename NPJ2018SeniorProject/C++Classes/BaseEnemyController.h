// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "C++Classes/BaseEnemyCharacter.h"
#include "BaseEnemyController.generated.h"

/**
 * 
 */


//enum to store the current state of gameplay
UENUM(BlueprintType)
enum class EAIControllerState : uint8
{
	ENeutral,
	EPacing,
	EAttack,
	EHitstun,
	EGrabbed,
	ERecovery
};

UCLASS()
class NPJ2018SENIORPROJECT_API ABaseEnemyController : public AAIController
{
	GENERATED_BODY()
		
	public:
		//virtual void Tick(float DeltaTime) override;
		ABaseEnemyController();

		virtual void BeginPlay() override;

		virtual void Possess(APawn * InPawn) override;

		APawn * GetPossessedPawn() { return selfReference; }

		void SetPlayerReference();

		void DetermineAIState();

		void SetAIState(EAIControllerState newState);

		void HandleAIState(float DeltaTime);

		uint8 enemyKeyID;

	private:
		UPROPERTY(transient)
		class UBlackboardComponent *BlackboardComponent;

		UPROPERTY(transient)
		class UBehaviorTreeComponent *BehaviorTreeComponent;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EnemyController", meta = (AllowPrivateAccess = true))
		UBehaviorTree * treeToRun;

		ABaseEnemyCharacter * selfReference;

		AActor * playerReference;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
		bool recoveryState;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy", meta = (AllowPrivateAccess = true))
		float recoveryTime;

		//FTimerHandle RecoveryTimer;

		//FTimerHandle GrabThresholdTimer;

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

		EAIControllerState CurrentState;
		
	
	
};
