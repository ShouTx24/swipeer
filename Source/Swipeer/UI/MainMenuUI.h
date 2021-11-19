// Property of Kamil Bochenski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainMenuUI.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEER_API UMainMenuUI : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

protected:
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* PlayButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ShopButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* SettingsButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* WardrobeButton;

	UFUNCTION()
	void PlayButtonClicked();

	UFUNCTION()
	void ShopButtonClicked();

	UFUNCTION()
	void SettingsButtonClicked();

	UFUNCTION()
	void WardrobeButtonClicked();
};
