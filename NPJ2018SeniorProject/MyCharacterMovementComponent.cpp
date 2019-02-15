// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacterMovementComponent.h"


UMyCharacterMovementComponent::UMyCharacterMovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}
/*
void UMyCharacterMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();
	//~~~~~~~~~~~~~~~~~

	//UE_LOG //comp Init!
}

//Tick Comp
void UMyCharacterMovementComponent::TickComponent(float DeltaTime,enum ELevelTick TickType,FActorComponentTickFunction *ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//UE_LOG //custom comp is ticking!!!

}*/

void UMyCharacterMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
	UE_LOG(LogClass, Log, TEXT("YAY! My Function is being called!"));
	if (deltaTime < MIN_TICK_TIME)
	{
		return;
	}

	//RestorePreAdditiveRootMotionVelocity();

	/*if (!HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
	{
		if (bCheatFlying && Acceleration.IsZero())
		{
			Velocity = FVector::ZeroVector;
		}
		const float Friction = 0.5f * GetPhysicsVolume()->FluidFriction;
		CalcVelocity(deltaTime, Friction, true, GetMaxBrakingDeceleration());
	}*/

	//ApplyRootMotionToVelocity(deltaTime);

	Iterations++;
	bJustTeleported = false;

	FVector OldLocation = UpdatedComponent->GetComponentLocation();
	const FVector Adjusted = Velocity * deltaTime;
	FHitResult Hit(1.f);

	float remainingTime = deltaTime;
	const float timeTick = GetSimulationTimeStep(remainingTime, Iterations);
	const FVector FlyVector = FVector(Velocity.X, Velocity.Y, 0.f) * timeTick;
	//-----------------------Delta-----NewRotation---------------------------sweep
	SafeMoveUpdatedComponent(FlyVector, UpdatedComponent->GetComponentQuat(), true, Hit);



	if (Hit.Time < 1.f)
	{
		const FVector GravDir = FVector(0.f, 0.f, -1.f);
		const FVector VelDir = Velocity.GetSafeNormal();
		const float UpDown = GravDir | VelDir;

		bool bSteppedUp = false;
		if ((FMath::Abs(Hit.ImpactNormal.Z) < 0.2f) && (UpDown < 0.5f) && (UpDown > -0.2f) && CanStepUp(Hit))
		{
			float stepZ = UpdatedComponent->GetComponentLocation().Z;
			bSteppedUp = StepUp(GravDir, Adjusted * (1.f - Hit.Time), Hit);
			if (bSteppedUp)
			{
				OldLocation.Z = UpdatedComponent->GetComponentLocation().Z + (OldLocation.Z - stepZ);
			}
		}

		if (!bSteppedUp)
		{
			//adjust and try again
			HandleImpact(Hit, deltaTime, Adjusted);
			SlideAlongSurface(Adjusted, (1.f - Hit.Time), Hit.Normal, Hit, true);
		}
	}

	if (!bJustTeleported && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
	{
		Velocity = (UpdatedComponent->GetComponentLocation() - OldLocation) / deltaTime;
	}
}

void UMyCharacterMovementComponent::SetMovementMode(EMovementMode NewMovementMode, uint8 NewCustomMode)
{
	UE_LOG(LogClass, Log, TEXT("Well, at least my SetMovementMode is being called..."));
	Super::SetMovementMode(NewMovementMode,NewCustomMode);
}