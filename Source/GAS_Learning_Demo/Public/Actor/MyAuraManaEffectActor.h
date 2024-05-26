// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/AuraEffectActor.h"
#include "MyAuraManaEffectActor.generated.h"

/**
 * 
 */
UCLASS()
class GAS_LEARNING_DEMO_API AMyAuraManaEffectActor : public AAuraEffectActor
{
	GENERATED_BODY()
public:
	
	virtual void OnOverlap(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;


};
