// Property of Kamil Bochenski. All rights reserved.


#include "PlayerDataSave.h"

void UPlayerDataSave::SaveData(FPlayerData* NewPlayerData)
{
	playerName = NewPlayerData->playerName;
	playerEssence = NewPlayerData->playerEssence;
	playerRecord = NewPlayerData->playerRecord;
	premiumUser = NewPlayerData->premiumUser;
}

void UPlayerDataSave::LoadData(FPlayerData* OutPlayerData)
{
	OutPlayerData->playerName = playerName;
	OutPlayerData->playerEssence = playerEssence;
	OutPlayerData->playerRecord = playerRecord;
	OutPlayerData->premiumUser = premiumUser;
}
