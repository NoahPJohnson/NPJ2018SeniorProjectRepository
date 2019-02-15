// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C++Classes/BaseEnemy.h"
#include "C++Classes/BaseEnemyPawn.h"
#include "C++Classes/BaseEnemyCharacter.h"
#include "NPJ2018SeniorProjectCharacter.generated.h"

UCLASS(config=Game)
class ANPJ2018SeniorProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCharacterMovementComponent* MyCharacterMovement;

	/** Collection Sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* CollectionSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* GrabBox;

public:
	ANPJ2018SeniorProjectCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/**Accessor for initial power */
	/**Accessor for initial power */
	UFUNCTION(BlueprintPure, Category = "Health/Power")
	float GetInitialHealth() { return initialHealth; }
	UFUNCTION(BlueprintPure, Category = "Health/Power")
	float GetCurrentHealth() { return currentHealth;  }
	
	UFUNCTION(BlueprintPure, Category = "Health/Power")
	float GetInitialPower();
	UFUNCTION(BlueprintPure, Category = "Health/Power")
	float GetCurrentPower();

	UFUNCTION(BlueprintCallable, Category = "CameraControl")
	void CameraLockOn();

	//static FName MyCharacterMovementComponentName;

	//class UCharacterMovementComponent* GetCharacterMovement() const override;

	/**
	Function to update the character's power
	* @param powerChange This is the amount to change the power by, positive or negative
	*/
	UFUNCTION(BlueprintCallable, Category = "Power")
	void UpdateCharacterPower(float powerChange);

	UFUNCTION(BlueprintCallable, Category = "Attacking")
	void SetHoldingEnemy(bool holding);

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

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

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	void SwitchCharacter();

	/**Called when we press a key to collect any pickups inside the CollectionSphere*/
	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void CollectPickups();


	//UFUNCTION(BlueprintCallable, Category = "Health/Power")
	//void DrainPower();
	

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void Sprint();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void Ascend();

	UFUNCTION(BlueprintCallable, Category = "Special Movement")
	void StopAscend();

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



	/**Multiplier for  character speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
	float baseSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
	float baseMinSpeed;

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
	bool isAscending;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Special Movement", Meta = (BluePrintProtected = true))
	bool isFlying;

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
	bool isGliding;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control", Meta = (BluePrintProtected = true))
	bool isLockingOn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control", Meta = (BluePrintProtected = true))
	FVector nearestEnemyLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control", Meta = (BluePrintProtected = true))
	UCapsuleComponent* nearestEnemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control", Meta = (BluePrintProtected = true))
	FVector startingCameraLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control", Meta = (BluePrintProtected = true))
	FVector lockOnCameraLocation;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack", Meta = (BluePrintProtected = true))
	bool isReadyToGrab;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack", Meta = (BluePrintProtected = true))
	bool isHoldingEnemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack", Meta = (BluePrintProtected = true))
	ABaseEnemyCharacter * grabbedEnemy;



	UFUNCTION(BlueprintImplementableEvent, Category = "Power")
	void PowerChangeEffect();

private:
	/**Current power level of our character */
	
	UPROPERTY(VisibleAnywhere, Category = "Health/Power")
	float currentHealth;
	
	UPROPERTY(VisibleAnywhere, Category = "Health/Power")
	float characterPower;

	float timeToSprintBoost;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class USphereComponent* GetCollectionSphere() const { return CollectionSphere; }
	/** Returns Collection sphere*/
	FORCEINLINE class UBoxComponent* GetGrabBox() const { return GrabBox; }

	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

