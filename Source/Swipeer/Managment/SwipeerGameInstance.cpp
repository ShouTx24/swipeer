// Property of Kamil Bochenski. All right's reserved.


#include "SwipeerGameInstance.h"
#include "PlayerDataSave.h"
#include "Kismet/GameplayStatics.h"

void USwipeerGameInstance::Init()
{
	Super::Init();
	UPlayerDataSave* Save = Cast<UPlayerDataSave>(UGameplayStatics::LoadGameFromSlot(FString("Save"), 0));
	if (Save) Save->LoadData(&PlayerData);
	
}
