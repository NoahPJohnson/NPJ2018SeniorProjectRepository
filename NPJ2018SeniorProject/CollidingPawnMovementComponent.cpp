// Fill out your copyright notice in the Description page of Project Settings.

#include "CollidingPawnMovementComponent.h"


void UCollidingPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	

	// Make sure that everything is still valid, and that we are allowed to move.
	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		//UE_LOG(LogClass, Log, TEXT("Something is missing!"));
		return;
	}

	// Get (and then clear) the movement vector that we set in ACollidingPawn::Tick
	FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * currentSpeed;
	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		FHitResult Hit;
		if (DesiredMovementThisFrame.X == 0 && DesiredMovementThisFrame.Y == 0 && DesiredMovementThisFrame.Z != 0)
		{
			//desiredRotation = FVector(lastDesiredMove).ToOrientationRotator();
			SafeMoveUpdatedComponent(DesiredMovementThisFrame, /*desiredRotation*/UpdatedComponent->GetComponentRotation(), true, Hit);
		}
		else
		{
			desiredRotation = FVector(DesiredMovementThisFrame.X, DesiredMovementThisFrame.Y, 0.0).ToOrientationRotator();
			//lastDesiredMove = FVector(DesiredMovementThisFrame.X, DesiredMovementThisFrame.Y, 0.0);
			
			SafeMoveUpdatedComponent(DesiredMovementThisFrame, desiredRotation/*UpdatedComponent->GetComponentRotation()*/, true, Hit);
		}
		//UE_LOG(LogClass, Log, TEXT("turn to ROLL = %f"), desiredRotation.Roll);
		//UE_LOG(LogClass, Log, TEXT("turn to PITCH = %f"), desiredRotation.Pitch);
		//UE_LOG(LogClass, Log, TEXT("turn to YAW = %f"), desiredRotation.Yaw);
		
		//UE_LOG(LogClass, Log, TEXT("There is a vector, execute move."));
		// If we bumped into something, try to slide along it
		if (Hit.IsValidBlockingHit())
		{
			SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
		}
	}
	//UE_LOG(LogClass, Log, TEXT("Movement Component is ticking."));
};

void UCollidingPawnMovementComponent::SetCurrentSpeed(float newSpeed)
{
	currentSpeed = newSpeed;
	UE_LOG(LogClass, Log, TEXT("current speed = %f"), currentSpeed);
}

