// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABatteryPickup();
	
	// Override the was collected function - use impelentation because its a blue native event
	void WasCollected_Implementation() override;

	// Public way to access batterys power level
	float GetPower();

protected:

	// Set the amount of power the battery gives to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
		float BatPower;

};
