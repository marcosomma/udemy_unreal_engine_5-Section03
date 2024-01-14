// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	UpdatedLocation = GetActorLocation();
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float Acceleration = Speed * DeltaTime;	// Calculate Acceleration
	if(MoveYPos) {	// UP
		if (UpdatedLocation.Y <= StartLocation.Y) DistanceMoved = 0.0f;	// Reset MeasuredDistance if object is in the start Position
		if ((DistanceMoved + Acceleration) < Distance)
		{
			DistanceMoved += FVector::Dist(StartLocation, UpdatedLocation) * DeltaTime;
			UpdatedLocation.Y += Acceleration;	// Moving to the chosen direction
		} else
		{
			UpdatedLocation.Y -= Acceleration;	// Moving to opposite direction
		}
	}
	if(MoveYNeg) {	// DOWN
		if (UpdatedLocation.Y >= StartLocation.Y) DistanceMoved = 0.0f;	// Reset MeasuredDistance if object is in the start Position
		if ((DistanceMoved + Acceleration) < Distance)
		{
			DistanceMoved += FVector::Dist(StartLocation, UpdatedLocation) * DeltaTime;
			UpdatedLocation.Y -= Acceleration;	// Moving to the chosen direction
		} else
		{
			UpdatedLocation.Y += Acceleration;	// Moving to opposite direction
		}
	}
	if(MoveXPos) {	// FORWARD
		if (UpdatedLocation.X <= StartLocation.X) DistanceMoved = 0.0f;	// Reset MeasuredDistance if object is in the start Position
		if ((DistanceMoved + Acceleration) < Distance)
		{
			DistanceMoved += FVector::Dist(StartLocation, UpdatedLocation) * DeltaTime;
			UpdatedLocation.X += Acceleration;	// Moving to the chosen direction
		} else
		{
			UpdatedLocation.X -= Acceleration;	// Moving to opposite direction
		}
	}
	if(MoveXNeg) {	// BACKWARD
		if (UpdatedLocation.X >= StartLocation.X) DistanceMoved = 0.0f;	// Reset MeasuredDistance if object is in the start Position
		if ((DistanceMoved + Acceleration) < Distance)
		{
			DistanceMoved += FVector::Dist(StartLocation, UpdatedLocation) * DeltaTime;
			UpdatedLocation.X -= Acceleration;	// Moving to the chosen direction
		} else
		{
			UpdatedLocation.X += Acceleration;	// Moving to opposite direction
		}
	}
	if(MoveZPos) {	// RIGHT
		if (UpdatedLocation.Z <= StartLocation.Z) DistanceMoved = 0.0f;	// Reset MeasuredDistance if object is in the start Position
		if ((DistanceMoved + Acceleration) < Distance)
		{
			DistanceMoved += FVector::Dist(StartLocation, UpdatedLocation) * DeltaTime;
			UpdatedLocation.Z += Acceleration;	// Moving to the chosen direction
		} else
		{
			UpdatedLocation.Z -= Acceleration;	// Moving to opposite direction
		}
	}
	if(MoveZNeg) {	// LEFT
		if (UpdatedLocation.Z >= StartLocation.Z) DistanceMoved = 0.0f;	// Reset MeasuredDistance if object is in the start Position
		if ((DistanceMoved + Acceleration) < Distance)
		{
			DistanceMoved += FVector::Dist(StartLocation, UpdatedLocation) * DeltaTime;
			UpdatedLocation.Z -= Acceleration;	// Moving to the chosen direction
		} else
		{
			UpdatedLocation.Z += Acceleration;	// Moving to opposite direction
		}
	}
	
	// Set Movement
	SetActorLocation(UpdatedLocation);
}

