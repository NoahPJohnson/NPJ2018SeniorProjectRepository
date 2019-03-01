// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class NPJ2018SENIORPROJECT_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	APlayerHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	UPROPERTY(EditAnywhere, Category = "Health")
	class UUserWidget* playerHUDWidget;

	//UPROPERTY(EditAnywhere, Category = "Health")
	//class UProgressBar* HealthBar;

	//UPROPERTY(EditAnywhere, Category = "Power")
	//class UProgressBar* PowerBar;

	UPROPERTY(EditAnywhere, Category = "Health")
	TSubclassOf<class UWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Health")
	class UUserWidget* CurrentWidget;
	
	
};
