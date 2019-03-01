// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHUDWidget.h"
#include "WidgetTree.h"
#include "ProgressBar.h"


UPlayerHUDWidget::UPlayerHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	/*

	if (RootWidget != nullptr)
	{
		RootWidget->AddChild(HealthBar);

	}
	else
	{
		UE_LOG(LogClass, Log, TEXT("Root widget is null."));
	}*/
}


void UPlayerHUDWidget::NativeConstruct()
{
	// Do some custom setup

	// Call the Blueprint "Event Construct" node
	Super::NativeConstruct();

	//checkRoot = false;

}


void UPlayerHUDWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	// Make sure to call the base class's NativeTick function
	Super::NativeTick(MyGeometry, InDeltaTime);
	/*if (checkRoot == false)
	{
		checkRoot = true;
		UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());

		if (RootWidget != nullptr)
		{
			RootWidget->AddChild(HealthBar);

		}
		else
		{
			UE_LOG(LogClass, Log, TEXT("Root widget is null."));
		}
	}*/
	// Do your custom tick stuff here
}

TSharedRef<SWidget> UPlayerHUDWidget::RebuildWidget()
{
	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	/*if (WidgetTree)
	{
		UPanelWidget* RootWidget = WidgetTree->ConstructWidget<UPanelWidget>(UPanelWidget::StaticClass(), TEXT("RootWidget"));
		// If GetRootWidget() is still null
		WidgetTree->RootWidget = RootWidget;
	}*/

	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());	
				
	UE_LOG(LogClass, Log, TEXT("Rebuild is called."));

	if (RootWidget != nullptr)
	{
		HealthBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("PlayerHealthBar")); 
		RootWidget->AddChild(HealthBar);
	}
	else
	{
		UE_LOG(LogClass, Log, TEXT("GetRootWidget is null."));
	}

	return Widget;
}

