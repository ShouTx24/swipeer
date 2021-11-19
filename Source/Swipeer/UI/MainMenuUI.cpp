// Property of Kamil Bochenski. All rights reserved.

#include "MainMenuUI.h"
#include "../SwipeerPlayerController.h"

void UMainMenuUI::NativeConstruct()
{
	Super::NativeConstruct();
	PlayButton->OnClicked.AddDynamic(this, &UMainMenuUI::PlayButtonClicked);
	ShopButton->OnClicked.AddDynamic(this, &UMainMenuUI::ShopButtonClicked);
	SettingsButton->OnClicked.AddDynamic(this, &UMainMenuUI::SettingsButtonClicked);
	WardrobeButton->OnClicked.AddDynamic(this, &UMainMenuUI::WardrobeButtonClicked);
}

void UMainMenuUI::PlayButtonClicked()
{
	Cast<ASwipeerPlayerController>(GetOwningPlayer())->GameStarted();
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