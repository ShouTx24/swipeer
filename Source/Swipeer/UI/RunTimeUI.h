// Property of Kamil Bochenski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "RunTimeUI.generated.h"

class UTextBlock;

UCLASS()
class SWIPEER_API URunTimeUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateScore(int NewScore);
	void UpdateRecord(int NewRecord);
	void UpdateEssence(int NewEssence);
	
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* Score;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* Record;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* Essence;

};
