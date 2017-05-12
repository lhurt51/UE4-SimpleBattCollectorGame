// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"

// Set Default values
ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);

	//The base power level of the battery
	BatPower = 150.f;
}

void ABatteryPickup::WasCollected_Implementation()
{
	// Use the base pickup behavior
	Super::WasCollected_Implementation();

	// Destroy the battery
	Destroy();
}

// Returns battery power
float ABatteryPickup::GetPower()
{
	return BatPower;
}
