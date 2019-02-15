// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicTaskCode.h"
#include "NPJ2018SeniorProjectCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "BaseEnemyController.h"
#include "BaseEnemyCharacter.h"
#include "Engine.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

UBasicTaskCode::UBasicTaskCode()
{

}

EBTNodeResult::Type UBasicTaskCode::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* NodeMemory)
{
	ABaseEnemyController* CharacterController = Cast<ABaseEnemyController>(ownerComponent.GetAIOwner());
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "Task Execute");
	if (CharacterController != nullptr)
	{
		ACharacter* player = Cast<ACharacter>(ownerComponent.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharacterController->enemyKeyID));
		if (player != nullptr)
		{
			ANPJ2018SeniorProjectCharacter* playerCharacter = Cast<ANPJ2018SeniorProjectCharacter>(player);
			if (playerCharacter != nullptr)
			{
				FVector playerDirection = playerCharacter->GetActorForwardVector();
				FVector playerVelocity = playerCharacter->GetVelocity();
				FVector playerLocation = playerCharacter->GetActorLocation();
				FVector offsetLocation;


				if ((CharacterController->GetPawn()->GetActorLocation() - (playerLocation + (playerCharacter->GetActorRightVector() * 500))).Size() < (CharacterController->GetPawn()->GetActorLocation() - (playerLocation - (playerCharacter->GetActorRightVector()*500))).Size())
				{
					offsetLocation = (playerCharacter->GetActorRightVector()*500);
				}
				else
				{
					offsetLocation = -(playerCharacter->GetActorRightVector()*500);
				}
				//FVector cameraDirection = playerCharacter->GetFollowCamera()->GetForwardVector();
				
				CharacterController->MoveToLocation((playerLocation + ((playerDirection * 600)+offsetLocation)) * FVector(1.0, 1.0, 0.0), 7.0, true, true, true, true, 0, true);
				//CharacterController->MoveToActor(player, 5.0f, true, true, true, 0, true);
				//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "Task Execute For REAL");
				FVector debugLocation = (playerLocation + ((playerDirection*600)+offsetLocation)) * FVector(1.0, 1.0, 0.0);
				UE_LOG(LogClass, Log, TEXT("Going to: %f , %f , %f"), debugLocation.X, debugLocation.Y, debugLocation.Z);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	else
	{
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Failed;
}



