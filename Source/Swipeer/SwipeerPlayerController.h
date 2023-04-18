// Property of Kamil Bochenski. All right's reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "SwipeerPlayerController.generated.h"

class UUserWidget;
class URunTimeUI;
class UGameOverUI;
class UMainMenuUI;
class ATrunk;

UCLASS()
class SWIPEER_API ASwipeerPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Standard Epic's interface
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaTime) override;

	// Main input events
	void TouchStart(ETouchIndex::Type FingerIndex, FVector Location);
	void GetSwipeDirectionAndTurnTrunk();

	// User Interface
	void ShowStartGameUI();
	void UpdateRuntimeUIData(float Points, float Essence = 0, float Record = 0);
	void ShowGameOverUI(float Score, float Record);
	void ReplaceUI(UUserWidget* Show, UUserWidget* Hide = nullptr);
	
protected:
	FVector TouchStartLocation;
	
	UPROPERTY(Transient)
	ATrunk* Trunk;

	/// User Interface
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> MainMenuUIClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> RunTimeUIClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> GameOverUIClass;
	
private:
	UPROPERTY(Transient)
	URunTimeUI* RunTimeUI;
	
	UPROPERTY(Transient)
	UGameOverUI* GameOverUI;
	
	UPROPERTY(Transient)
	UMainMenuUI* MainMenuUI;
};
