// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Is the pickup active. true if the pickup can be picked up
	bool bIsActive;

public:	
	
	/** Return the mesh for the pickup*/
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	/** Return whether or not the pickup is active */
	UFUNCTION(BlueprintPure, Category = "Pickup")
		bool IsActive();

	/** Allows other classes to safely change whether the pickup is active or not */
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetActive(bool NewPickupState);

	// Function to call when the pickup is collected
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

private:
	/** Static mesh to represent the pickup*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PickupMesh;
	
	
};
