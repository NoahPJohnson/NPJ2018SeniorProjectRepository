// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TestPlayerPawn.generated.h"

UCLASS()
class NPJ2018SENIORPROJECT_API ATestPlayerPawn : public APawn
{
	GENERATED_BODY()

	

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CollisionCapsule;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCollidingPawnMovementComponent* MyPawnMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* GrabBox;

public:
	// Sets default values for this pawn's properties
	ATestPlayerPawn();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* OurVisibleComponent;

	UFUNCTION(BlueprintCallable, Category = "Health/Power")
	void UpdatePower(float newPower);

	UFUNCTION(BlueprintCallable, Category = "Health/Power")
	void UpdateHealth(float newHealth);

	/**Accessor for initial power */
	/**Accessor for initial power */
	UFUNCTION(BlueprintPure, Category = "Health/Power")
	float GetInitialHealth() { return initialHealth; }
	UFUNCTION(BlueprintPure, Category = "Health/Power")
	float GetCurrentHealth() { return currentHealth; }

	UFUNCTION(BlueprintPure, Category = "Health/Power")
	float GetInitialPower();
	UFUNCTION(BlueprintPure, Category = "Health/Power")
	float GetCurrentPower();

	UFUNCTION(BlueprintPure, Category = "Special Movement")
	float GetMaxSpeed() { return maxSpeed;  }
	UFUNCTION(BlueprintPure, Category = "Special Movement")
	float GetCurrentSpeed() { return currentMoveSpeed; }

	UFUNCTION(BlueprintPure, Category = "Special Movement")
	float GetBuildUpSpeed() { return currentMomentumVector.Size()*currentMoveSpeed; }

	UFUNCTION(BlueprintCallable, Category = "CameraControl")
	void CameraLockOn();

	UFUNCTION(BlueprintCallable, Category = "CameraControl")
	void SetCameraPosition(FRotator newRotation);

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void SetSavedAxis(float vValue, float hValue, bool aValue, bool dValue);

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void SetBoostedSpeed(float newSpeed);

	

	/**
	Function to update the character's power
	* @param powerChange This is the amount to change the power by, positive or negative
	*/
	UFUNCTION(BlueprintCallable, Category = "Power")
	void UpdateCharacterPower(float powerChange);

	UFUNCTION(BlueprintCallable, Category = "Attacking")
	void SetHoldingEnemy(bool holding);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void MoveUp(float Value);

	void MoveDown(float Value);

	void Turn(float AxisValue);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	virtual UPawnMovementComponent* GetMovementComponent() const override;


	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void Sprint();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void Jump();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void SwitchCharacter(bool glideValue, bool skidValue);

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void CalculateMomentumVector(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void Ascend();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void StopAscend();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void Descend();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void StopDescend();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void Fly();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void StopFly();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void Crouch_Slide_Glide();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void StopCrouch_Slide_Glide();

	UFUNCTION(BlueprintCallable, Category = "Attacking")
	void Grab();



	UFUNCTION()
	void PerformGrab(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void PerformRelease(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable, Category = "Attacking")
	void Throw();


	/**The starting power level of our character*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health/Power", Meta = (BluePrintProtected = true))
		float initialHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health/Power", Meta = (BluePrintProtected = true))
		float initialPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health/Power", Meta = (BluePrintProtected = true))
		bool startConsumingPower;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float timer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float timeToSwitch;


	/**Multiplier for  character speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float baseSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float currentMoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float maxSpeed;

	/**Speed when power level = 0 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float sprintSpeedBonus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float sprintBoostBonus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float sprintBoostBase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float sprintBoostAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float sprintBoostLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		bool isSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		bool isReadyToSwitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		bool isAscending;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		bool isDescending;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		bool isFlying;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		bool isJumping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float jumpForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float defaultAirControl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float flightSpeedBonus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float flightSpeedBonusAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float flightSpeedLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float flightSpeedNormal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float savedHorizontalAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float savedVerticalAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		bool isCrouching;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		bool isSliding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float buildUpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float buildUpSpeedIncrease;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		bool isCharacterGliding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		FVector currentMomentumVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
		float currentMomentumDelta;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control", Meta = (BluePrintProtected = true))
		bool isLockingOn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control", Meta = (BluePrintProtected = true))
		FVector nearestEnemyLocation;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control", Meta = (BluePrintProtected = true))
	//UCapsuleComponent* nearestEnemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control", Meta = (BluePrintProtected = true))
		FVector startingCameraLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control", Meta = (BluePrintProtected = true))
		FVector lockOnCameraLocation;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack", Meta = (BluePrintProtected = true))
		bool isReadyToGrab;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack", Meta = (BluePrintProtected = true))
		bool isHoldingEnemy;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack", Meta = (BluePrintProtected = true))
	//ABaseEnemyCharacter * grabbedEnemy;



	UFUNCTION(BlueprintImplementableEvent, Category = "Power")
		void PowerChangeEffect();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns Collection sphere*/
	FORCEINLINE class UBoxComponent* GetGrabBox() const { return GrabBox; }

	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

private:
	/**Current power level of our character */

	UPROPERTY(VisibleAnywhere, Category = "Health/Power")
		float currentHealth;

	UPROPERTY(VisibleAnywhere, Category = "Health/Power")
		float characterPower;

	float timeToSprintBoost;
	
};
