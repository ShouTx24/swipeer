// Property of Kamil Bochenski. All rights reserved.


#include "RunTimeUI.h"
void URunTimeUI::UpdateScore(int newScore)
{
	Score->SetText(FText::AsNumber(newScore));
}

void URunTimeUI::UpdateRecord(int newRecord)
{
	Record->SetText(FText::AsNumber(newRecord));
}

void URunTimeUI::UpdateEssence(int newEssence)
{
	Essence->SetText(FText::AsNumber(newEssence));
}