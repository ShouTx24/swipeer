// Copyright Epic Games, Inc. All Rights Reserved.


#include "SwipeerGameModeBase.h"
#include "BallPawn.h"
#include "SwipeerPlayerController.h"
#include "Managment/SwipeerGameState.h"

ASwipeerGameModeBase::ASwipeerGameModeBase(const FObjectInitializer& ObjectInitializer)
{
	DefaultPawnClass = ABallPawn::StaticClass();
	PlayerControllerClass = ASwipeerPlayerController::StaticClass();
	GameStateClass = ASwipeerGameState::StaticClass();
}

bool ASwipeerGameModeBase::BBallReachNextElement(APawn* Ball, ATrunk* Trunk)
{
	if (Ball->GetActorLocation().Y >= Trunk->GetActorLocation().Y + (Trunk->GetActorScale().X * 500 * (Trunk->PartCounter - 30)))
	{
		Trunk->RemovePart();
		if (Trunk->PartCounter > 35)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString("Score!"));
		}
		return true;
	}
	else
	{
		return false;
	}

}