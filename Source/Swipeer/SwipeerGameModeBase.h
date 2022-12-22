// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "BallPawn.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Managment/PlayerDataSave.h"
#include "Managment/SwipeerGameState.h"
#include "Managment/SwipeerGameInstance.h"
#include "SwipeerPlayerController.h"
#include "Trunk/Trunk.h"

#include "SwipeerGameModeBase.generated.h"

UCLASS()
class SWIPEER_API ASwipeerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ASwipeerGameModeBase(const FObjectInitializer& ObjectInitializer);
public:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DelaTime) override;
	
	bool bBallHasReachedNextElement(APawn* Ball);
	
	void StartGame();
	void GameOver(APawn* Player);
	
	void GiveEssence();

	APawn* Pawn;
	ATrunk* Trunk;
	ASwipeerPlayerController* PlayerController;
	int Score = 0;
	int Essence = 0;

};
