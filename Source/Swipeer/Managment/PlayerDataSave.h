// Property of Kamil Bochenski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SwipeerGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerDataSave.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEER_API UPlayerDataSave : public USaveGame
{
	GENERATED_BODY()
	
	UPROPERTY()
	FName playerName;

	UPROPERTY()
	int playerRecord;

	UPROPERTY()
	int playerEssence;

	UPROPERTY()
	bool premiumUser;

public:
	void SaveData(FPlayerData* NewPlayerData);
	void LoadData(FPlayerData* OutPlayerData);
};
