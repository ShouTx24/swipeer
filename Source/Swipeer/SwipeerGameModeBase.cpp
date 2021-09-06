// Copyright Epic Games, Inc. All Rights Reserved.


#include "SwipeerGameModeBase.h"
#include "BallPawn.h"
#include "SwipeerPlayerController.h"

ASwipeerGameModeBase::ASwipeerGameModeBase(const FObjectInitializer& ObjectInitializer)
{
	DefaultPawnClass = ABallPawn::StaticClass();
	PlayerControllerClass = ASwipeerPlayerController::StaticClass();
}