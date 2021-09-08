// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "../SwipeerGameModeBase.h"
#include "SwipeerGameState.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEER_API ASwipeerGameState : public AGameStateBase
{
	GENERATED_BODY()

	ASwipeerGameState();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	APawn* Pawn;
	ATrunk* Trunk;
	ASwipeerGameModeBase* GameMode;
	int Score{ 0 };
};
