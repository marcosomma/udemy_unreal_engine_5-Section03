// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiMovingPlatform.h"

// Sets default values
AMultiMovingPlatform::AMultiMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMultiMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	UE_LOG(LogTemp, Log, TEXT("[%s] - StartLocation(X:%f Y:%f Z:%f) "), *GetName(), StartLocation.X, StartLocation.Y, StartLocation.Z);
	// UE_LOG(LogTemp, Warning, TEXT("Warning Example"));
	// UE_LOG(LogTemp, Error, TEXT("Error example"));
}

// Called every frame
void AMultiMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

bool AMultiMovingPlatform::ArrivedToDestination(FVector CurrentLocation) const
{
	float DistanceMoved = FVector::Distance(CurrentLocation, StartLocation);
	return DistanceMoved > Distance;
}

void AMultiMovingPlatform::MovePlatform(float DeltaTime) 
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (Velocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	if (ArrivedToDestination(CurrentLocation)) 
	{
		FVector MoveDirection = Velocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * Distance;

		SetActorLocation(StartLocation);
		Velocity = -Velocity;
	}
}


void AMultiMovingPlatform::RotatePlatform(float DeltaTime) 
{
	AddActorLocalRotation(RotationSpeed);
}
