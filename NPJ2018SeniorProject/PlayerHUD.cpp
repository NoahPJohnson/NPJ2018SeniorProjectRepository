// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "PlayerHUDWidget.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"


APlayerHUD::APlayerHUD()
{
	// Set the crosshair texture
	/*static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;*/

	static ConstructorHelpers::FClassFinder<UUserWidget> HUDObject(TEXT("/Game/BluePrints/PlayerHUD"));
	HUDWidgetClass = HUDObject.Class;
}


void APlayerHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition((Center.X-120.0f),(Center.Y + 120.0f));

	// draw the crosshair
	/*FCanvasTileItem TileItem(CrosshairDrawPosition, HealthBar, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);*/
}

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogClass, Log, TEXT("HUD Begin Play."));
	if (HUDWidgetClass != nullptr)
	{
		//UE_LOG(LogClass, Log, TEXT("HUD Widget Class Exists."));
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
			//UE_LOG(LogClass, Log, TEXT("HUD is calling add to view port."));
		}
		else
		{
			//UE_LOG(LogClass, Log, TEXT("Create Widget failed?"));
		}
	}
	else
	{
		//UE_LOG(LogClass, Log, TEXT("HUD Widget Class doesn't Exist."));
	}
}



