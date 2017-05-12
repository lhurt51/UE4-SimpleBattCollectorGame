// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVol.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVol : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVol();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// returns the where to spawn subobject
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	// Find a random point in the box component
	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPointInVol();

	// This function toggles whether or not the spawning is active
	UFUNCTION(BlueprintCallable, Category = "Spawning")
		void SetSpawningActive(bool bShouldSpawn);

protected:
	/** The pickup to spawn */
	UPROPERTY(EditAnywhere, Category = "Spawing")
		TSubclassOf<class APickup> WhatToSpawn;

	FTimerHandle SpawnTimer;

	// Minimum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawing")
		float SpawnDelayRangeLow;

	// Max spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayRangeHigh;

private:
	// Box component to specify where pickups should be spawned
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WhereToSpawn;

	// Handle spawning a new pickup
	void SpawnPickup();

	// Current spawn delay
	float SpawnDelay;

	
};
