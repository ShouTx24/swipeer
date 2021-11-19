// Property of Kamil Bochenski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "RunTimeUI.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEER_API URunTimeUI : public UUserWidget
{
	GENERATED_BODY()
protected:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* Score;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* Record;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* Essence;
public:
	void UpdateScore(int newScore);
	void UpdateRecord(int newRecord);
	void UpdateEssence(int newEssence);
};
