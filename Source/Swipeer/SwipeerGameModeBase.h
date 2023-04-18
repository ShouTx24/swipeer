// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "SwipeerGameModeBase.generated.h"

class ASwipeerPlayerController;
class ATrunk;

UCLASS()
class SWIPEER_API ASwipeerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ASwipeerGameModeBase(const FObjectInitializer& ObjectInitializer);
public:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DelaTime) override;
	
	bool BallHasReachedNextElement(const APawn& Ball) const;
	
	void StartGame();
	void GameOver();
	void GiveEssence();
	
public:
	UPROPERTY(Transient)
	APawn* Pawn;

	UPROPERTY(Transient)
	ATrunk* Trunk;

	UPROPERTY(Transient)
	ASwipeerPlayerController* PlayerController;

	int Score = 0;
	int Essence = 0;
};
