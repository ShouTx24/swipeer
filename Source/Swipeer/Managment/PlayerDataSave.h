// Property of Kamil Bochenski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SwipeerGameInstance.h"

#include "PlayerDataSave.generated.h"

UCLASS()
class SWIPEER_API UPlayerDataSave : public USaveGame
{
	GENERATED_BODY()
	
	UPROPERTY()
	FName PlayerName;

	UPROPERTY()
	int PlayerRecord;

	UPROPERTY()
	int PlayerEssence;

	UPROPERTY()
	bool PremiumUser;

public:
	void SaveData(const FPlayerData& NewPlayerData);
	void LoadData(FPlayerData& OutPlayerData) const;
};
