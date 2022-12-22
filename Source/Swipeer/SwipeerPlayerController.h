// Property of Kamil Bochenski. All right's reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Trunk/Trunk.h"
#include "Kismet/GameplayStatics.h"

#include "SwipeerPlayerController.generated.h"

UCLASS()
class SWIPEER_API ASwipeerPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;	
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaTime) override;

	void TouchStart(ETouchIndex::Type FingerIndex, FVector Location);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> MainMenuUIClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> RunTimeUIClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> GameOverUIClass;

	class URunTimeUI* RunTimeUI;
	class UGameOverUI* GameOverUI;
	class UMainMenuUI* MainMenuUI;

	void UpdateRuntimeUIData(float Points, float Essence = NULL, float Record = NULL);
	void ReplaceUI(UUserWidget* Show, UUserWidget* Hide = nullptr);
	void ShowStartGameUI();
	void ShowGameOverUI(float Score, float Record);
	
	FVector TouchStartLocation;
	ATrunk* Trunk;

	void GetSwipeDirection();

};
