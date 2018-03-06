// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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

	/** Collection Sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* CollectionSphere;
public:
	ANPJ2018SeniorProjectCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/**Accessor for initial power */
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetInitialPower();
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetCurrentPower();
	/**
	Function to update the character's power
	* @param powerChange This is the amount to change the power by, positive or negative
	*/
	UFUNCTION(BlueprintCallable, Category = "Power")
	void UpdateCharacterPower(float powerChange);

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

	/**Called when we press a key to collect any pickups inside the CollectionSphere*/
	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void CollectPickups();

	/**The starting power level of our character*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BluePrintProtected = true))
	float initialPower;

	/**Multiplier for  character speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BluePrintProtected = true))
	float speedFactor;

	/**Speed when power level = 0 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BluePrintProtected = true))
	float baseSpeed;

	UFUNCTION(BlueprintImplementableEvent, Category = "Power")
	void PowerChangeEffect();

private:
	/**Current power level of our character */
	UPROPERTY(VisibleAnywhere, Category = "Power")
	float characterPower;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class USphereComponent* GetCollectionSphere() const { return CollectionSphere; }
	/** Returns Collection sphere*/

};

