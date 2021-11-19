// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Trunk/Trunk.h"
#include "BallPawn.h"
#include "Kismet/GameplayStatics.h"
#include "SwipeerPlayerController.h"
#include "Managment/PlayerDataSave.h"
#include "Managment/SwipeerGameInstance.h"
#include "SwipeerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEER_API ASwipeerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ASwipeerGameModeBase(const FObjectInitializer& ObjectInitializer);
public:
	bool BBallReachNextElement(APawn* Ball, ATrunk* Trunk);
	
	void StartGame();
	void GameOver(APawn* Player);

};
