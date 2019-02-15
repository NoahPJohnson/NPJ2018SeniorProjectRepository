// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NPJ2018SeniorProjectGameMode.generated.h"


//enum to store the current state of gameplay
UENUM(BlueprintType)
enum class EProjectPlayState : uint8
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ANPJ2018SeniorProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANPJ2018SeniorProjectGameMode();

	virtual void Tick(float DeltaTime) override;

	/**Returns power needed to win for the hud*/
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerToWin() const;

	/**Call get power to win after everything, including the player has been constructed*/
	virtual void BeginPlay() override;

	/**Returns the current state*/
	UFUNCTION(BlueprintPure, Category = "Power")
	EProjectPlayState GetCurrentState() const;

	/**Set a new playing state*/
	//UFUNCTION
	void SetCurrentState(EProjectPlayState NewState);

protected:
	/**Rate at which character loses power*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float decayRate;

	/**The power needed to win the game*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float powerToWin;
	/**The widget class to use for the hud screen*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	/**The instance of the hud */
	UPROPERTY()
	class UUserWidget* CurrentWidget;

private:
	/**Keeps track of the current play state*/
	EProjectPlayState CurrentState;

	TArray<class ASpawnVolume*> SpawnVolumeActors;

	void HandleNewState(EProjectPlayState NewState);
};



