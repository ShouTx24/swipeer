// Copyright Epic Games, Inc. All Rights Reserved.


#include "SwipeerGameModeBase.h"
#include "Managment/SwipeerGameState.h"

ASwipeerGameModeBase::ASwipeerGameModeBase(const FObjectInitializer& ObjectInitializer)
{
	DefaultPawnClass = ABallPawn::StaticClass();
	PlayerControllerClass = ASwipeerPlayerController::StaticClass();
	GameStateClass = ASwipeerGameState::StaticClass();
}

bool ASwipeerGameModeBase::BBallReachNextElement(APawn* Ball, ATrunk* Trunk)
{
	if (Ball->GetActorLocation().Y >= Trunk->GetActorLocation().Y + (Trunk->GetActorScale().X * 500 * (Trunk->PartCounter - 29)))
	{
		Trunk->RemovePart();
		if (Trunk->PartCounter > 34) return true;
		else return false;
	}
	else return false;
}

void ASwipeerGameModeBase::StartGame()
{
	UGameplayStatics::GetPlayerPawn(GWorld, 0)->SetActorTickEnabled(true);
}

void ASwipeerGameModeBase::GameOver(APawn* Player)
{
	//Stops pawn form moving and creating additional GameOver event executions.
	Cast<ABallPawn>(Player)->SetActorTickEnabled(false);

	// Check if player beats it's former record.
	int currentRecord = GetGameInstance<USwipeerGameInstance>()->PlayerData.playerRecord;
	int currentScore = GetGameState<ASwipeerGameState>()->GetScore();
	if (currentScore > currentRecord)
	{
		currentRecord = GetGameInstance<USwipeerGameInstance>()->PlayerData.playerRecord = currentScore;
	}

	// Adding new Essence to general account
	GetGameInstance<USwipeerGameInstance>()->PlayerData.playerEssence += GetGameState<ASwipeerGameState>()->GetEssence();

	// User Interface
	Cast<ASwipeerPlayerController>(Player->GetController())->GameOver(currentScore, currentRecord);

	// Save Game
	UPlayerDataSave* Save = Cast<UPlayerDataSave>(UGameplayStatics::CreateSaveGameObject(UPlayerDataSave::StaticClass()));
	Save->SaveData(&GetGameInstance<USwipeerGameInstance>()->PlayerData);
	UGameplayStatics::SaveGameToSlot(Save, FString("Save"), 0);
}

