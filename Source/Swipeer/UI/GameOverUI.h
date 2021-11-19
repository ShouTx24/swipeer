// Property of Kamil Bochenski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "GameOverUI.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEER_API UGameOverUI : public UUserWidget
{
	GENERATED_BODY()
		
	virtual void NativeConstruct() override;


protected:
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* PointsText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* RecordText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* RestartButton;

	UFUNCTION()
	void RestartButtonClicked();

public:
	
	UFUNCTION()
	void UpdatePoints(int newPoints);
	
	UFUNCTION()
	void UpdateRecord(int newRecord);

};
