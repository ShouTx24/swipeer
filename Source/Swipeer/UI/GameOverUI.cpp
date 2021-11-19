// Property of Kamil Bochenski. All rights reserved.


#include "GameOverUI.h"

void UGameOverUI::NativeConstruct()
{
	Super::NativeConstruct();
	RestartButton->OnClicked.AddDynamic(this, &UGameOverUI::RestartButtonClicked);
}

void UGameOverUI::RestartButtonClicked()
{
	GetOwningPlayer()->RestartLevel();
}

void UGameOverUI::UpdatePoints(int newPoints)
{
	PointsText->SetText(FText::AsNumber(newPoints));
}
void UGameOverUI::UpdateRecord(int newRecord)
{
	RecordText->SetText(FText::AsNumber(newRecord));
}