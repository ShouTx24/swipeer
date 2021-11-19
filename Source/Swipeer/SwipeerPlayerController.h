// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Trunk/Trunk.h"

#include "Blueprint/UserWidget.h"
#include "UI/RunTimeUI.h"
#include "UI/GameOverUI.h"
#include "UI/MainMenuUI.h"

#include "SwipeerPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEER_API ASwipeerPlayerController : public APlayerController
{
	GENERATED_BODY()

	ASwipeerPlayerController();

	virtual void BeginPlay() override;
		
	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

	void TouchStart(ETouchIndex::Type FingerIndex, FVector Location);

	FVector TouchStartLocation;

	ATrunk* Trunk;

	void GetSwipeDirection();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> RunTimeUIClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> GameOverUIClass;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> MainMenuUIClass;
public:
	
	UPROPERTY(EditDefaultsOnly)
	URunTimeUI* RunTimeUI;

	UPROPERTY(EditDefaultsOnly)
	UGameOverUI* GameOverUI;

	UPROPERTY(EditDefaultsOnly)
	UMainMenuUI* MainMenuUI;

	UFUNCTION()
	void GameStarted();
	
	UFUNCTION()
	void GameOver(int Score, int Record, bool bNewRecord = false);
};
