// Property of Kamil Bochenski. All rights reserved.

#include "RunTimeUI.h"

#include "Components/TextBlock.h"

void URunTimeUI::UpdateScore(int NewScore)
{
	Score->SetText(FText::AsNumber(NewScore));
}

void URunTimeUI::UpdateRecord(int NewRecord)
{
	Record->SetText(FText::AsNumber(NewRecord));
}

void URunTimeUI::UpdateEssence(int NewEssence)
{
	Essence->SetText(FText::AsNumber(NewEssence));
}