// Property of Kamil Bochenski. All rights reserved.

#include "MainMenuUI.h"
#include "../SwipeerGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuUI::NativeConstruct()
{
	PlayButton->OnClicked.AddDynamic(this, &UMainMenuUI::PlayButtonClicked);
	ShopButton->OnClicked.AddDynamic(this, &UMainMenuUI::ShopButtonClicked);
	SettingsButton->OnClicked.AddDynamic(this, &UMainMenuUI::SettingsButtonClicked);
	WardrobeButton->OnClicked.AddDynamic(this, &UMainMenuUI::WardrobeButtonClicked);

	Super::NativeConstruct();
}

void UMainMenuUI::PlayButtonClicked()
{
	Cast<ASwipeerGameModeBase>(UGameplayStatics::GetGameMode(GWorld))->StartGame();
}

void UMainMenuUI::ShopButtonClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Magenta, __func__);
}

void UMainMenuUI::SettingsButtonClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Magenta, __func__);
}

void UMainMenuUI::WardrobeButtonClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Magenta, __func__);
}