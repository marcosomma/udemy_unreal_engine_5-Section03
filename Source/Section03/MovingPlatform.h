// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class SECTION03_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float DistanceMoved = 0.0f;
	FVector UpdatedLocation;
	FVector StartLocation;
	UPROPERTY(EditAnywhere, Category="Distance");
	int32 Distance = 0;
	UPROPERTY(EditAnywhere, Category="Speed");
	float Speed = 100.0f;
	UPROPERTY(EditAnywhere, Category="Direction");
	bool MoveZPos = false;
	UPROPERTY(EditAnywhere, Category="Direction");
	bool MoveZNeg = false;
	UPROPERTY(EditAnywhere, Category="Direction");
	bool MoveXPos = false;
	UPROPERTY(EditAnywhere, Category="Direction");
	bool MoveXNeg = false;
	UPROPERTY(EditAnywhere, Category="Direction");
	bool MoveYPos = false;
	UPROPERTY(EditAnywhere, Category="Direction");
	bool MoveYNeg = false;
};
