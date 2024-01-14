// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MultiMovingPlatform.generated.h"

UCLASS()
class SECTION03_API AMultiMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMultiMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	FVector StartLocation;
	UPROPERTY(EditAnywhere, Category="Distance");
	int32 Distance = 0;
	UPROPERTY(EditAnywhere, Category="Speed");
	FVector Velocity = FVector(100.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere, Category="Rotation");
	FRotator RotationSpeed;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	bool ArrivedToDestination(FVector CurrentLocation) const;
};
