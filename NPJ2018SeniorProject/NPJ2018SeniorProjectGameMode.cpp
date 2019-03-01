// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "NPJ2018SeniorProjectGameMode.h"
#include "NPJ2018SeniorProjectCharacter.h"
#include "PlayerHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "C++Classes/SpawnVolume.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

ANPJ2018SeniorProjectGameMode::ANPJ2018SeniorProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	decayRate = 0.01f;
	PrimaryActorTick.bCanEverTick = true;*/
	DefaultPawnClass = ANPJ2018SeniorProjectCharacter::StaticClass();
	HUDClass = APlayerHUD::StaticClass();
	
}

void ANPJ2018SeniorProjectGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogClass, Log, TEXT("Game Mode Begin Play."));
	
	/*
	//Find all spawn volume actors
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors);

	for (auto Actor : FoundActors)
	{
		ASpawnVolume* SpawnVolumeActor = Cast<ASpawnVolume>(Actor);
		if (SpawnVolumeActor)
		{
			SpawnVolumeActors.AddUnique(SpawnVolumeActor);
		}
	}

	SetCurrentState(EProjectPlayState::EPlaying);

	//Set the power to win
	ANPJ2018SeniorProjectCharacter* myCharacter = Cast<ANPJ2018SeniorProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (myCharacter)
	{
		powerToWin = (myCharacter->GetInitialPower())*1.25f;
	}*/

	/*if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}*/
	
	
}

void ANPJ2018SeniorProjectGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	//Check that we are using the battery collector character
	//UE_LOG(LogClass, Log, TEXT("Tick!"));
	ANPJ2018SeniorProjectCharacter* myCharacter = Cast<ANPJ2018SeniorProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (myCharacter)
	{
		if (myCharacter->GetCurrentPower() > powerToWin)
		{
			//SetCurrentState(EProjectPlayState::EWon);
		}
		//UE_LOG(LogClass, Log, TEXT("MY MAN"));
		else if (myCharacter->GetCurrentPower() > 0)
		{
			//UE_LOG(LogClass, Log, TEXT("Decay"));
			//myCharacter->UpdateCharacterPower(-DeltaTime*decayRate*(myCharacter->GetInitialPower()));
		}
		else
		{
			//SetCurrentState(EProjectPlayState::EGameOver);
		}
	}*/
}

float ANPJ2018SeniorProjectGameMode::GetPowerToWin() const
{
	return powerToWin;
}

EProjectPlayState ANPJ2018SeniorProjectGameMode::GetCurrentState() const
{
	return CurrentState;
}

void ANPJ2018SeniorProjectGameMode::SetCurrentState(EProjectPlayState NewState)
{
	
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void ANPJ2018SeniorProjectGameMode::HandleNewState(EProjectPlayState NewState)
{
	switch (NewState)
	{
		//If the game is playing
		case EProjectPlayState::EPlaying:
		{
			//Spawn volumes active
			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->SetSpawningActive(true);
			}
		}
		break;
		//If player is out of juice
		case EProjectPlayState::EGameOver:
		{
			//Spawn volumes inactive
			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->SetSpawningActive(false);
			}
			//Block input
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
			if (PlayerController)
			{
				PlayerController->SetCinematicMode(true, false, false, true, true);
			}
			//Ragdoll
			ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
			if (MyCharacter)
			{
				//MyCharacter->GetMesh()->SetSimulatePhysics(true);
				MyCharacter->GetMovementComponent()->MovementState.bCanJump = false;
			}
		}
		break;
		//If player has all their juice
		case EProjectPlayState::EWon:
		{
			//Spawn volumes inactive
			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->SetSpawningActive(false);
			}
		}
		break;
		default:
		case EProjectPlayState::EUnknown:
		{

		}
		break;
	}
}