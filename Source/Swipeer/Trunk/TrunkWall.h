// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "TrunkWall.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEER_API UTrunkWall : public UInstancedStaticMeshComponent
{
	GENERATED_BODY()
	
public:

protected:
	virtual void BeginPlay() override;
};
