// Property of Kamil Bochenski. All rights reserved.

#include "PlayerDataSave.h"

void UPlayerDataSave::SaveData(const FPlayerData& NewPlayerData)
{
	PlayerName = NewPlayerData.PlayerName;
	PlayerEssence = NewPlayerData.PlayerEssence;
	PlayerRecord = NewPlayerData.PlayerRecord;
	PremiumUser = NewPlayerData.PremiumUser;
}

void UPlayerDataSave::LoadData(FPlayerData& OutPlayerData) const
{
	OutPlayerData.PlayerName = PlayerName;
	OutPlayerData.PlayerEssence = PlayerEssence;
	OutPlayerData.PlayerRecord = PlayerRecord;
	OutPlayerData.PremiumUser = PremiumUser;
}
