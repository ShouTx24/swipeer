// Property of Kamil Bochenski. All right's reserved.

#include "SwipeerPlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "UI/GameOverUI.h"
#include "UI/MainMenuUI.h"
#include "UI/RuntimeUI.h"
#include "Trunk/Trunk.h"

void ASwipeerPlayerController::BeginPlay()
{
	Trunk = Cast<ATrunk>(UGameplayStatics::GetActorOfClass(GetWorld(), ATrunk::StaticClass()));
	
	if (!MainMenuUIClass)
	{
		return;
	}
	MainMenuUI = CreateWidget<UMainMenuUI>(this, MainMenuUIClass);
	MainMenuUI->AddToViewport();

	if (!RunTimeUIClass)
	{
		return;
	}
	RunTimeUI = CreateWidget<URunTimeUI>(this, RunTimeUIClass);

	if (!GameOverUIClass)
	{
		return;
	}
	GameOverUI = CreateWidget<UGameOverUI>(this, GameOverUIClass);
}

void ASwipeerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindTouch(IE_Pressed, this, &ASwipeerPlayerController::TouchStart);
}

void ASwipeerPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetSwipeDirectionAndTurnTrunk();
}

void ASwipeerPlayerController::TouchStart(ETouchIndex::Type FingerIndex, FVector Location)
{
	TouchStartLocation = Location;
}

void ASwipeerPlayerController::GetSwipeDirectionAndTurnTrunk()
{
	FVector2D CurrentLocation;
	bool bTouchActive;
	GetInputTouchState(ETouchIndex::Touch1, CurrentLocation.X, CurrentLocation.Y, bTouchActive);

	if (!bTouchActive)
	{
		return;
	}

	if (TouchStartLocation.X - 40 >= CurrentLocation.X)
	{
		// Turn right
		Trunk->Turn(-1);
	}
	else if (TouchStartLocation.X + 40 <= CurrentLocation.X)
	{
		// Turn left
		Trunk->Turn(1);
	}
}

void ASwipeerPlayerController::UpdateRuntimeUIData(float Points, float Essence /*= 0*/, float Record /*= 0*/)
{
	RunTimeUI->UpdateScore(Points);
	if (Essence != 0)
	{
		RunTimeUI->UpdateEssence(Essence);
	}
	if (Record != 0)
	{
		RunTimeUI->UpdateRecord(Record);
	}
}

void ASwipeerPlayerController::ReplaceUI(UUserWidget* Show, UUserWidget* Hide)
{
	if (Hide && Hide->IsInViewport())
	{
		Hide->RemoveFromViewport();
	}
	if (Show && !Show->IsInViewport())
	{
		Show->AddToViewport();
	}
}

void ASwipeerPlayerController::ShowStartGameUI()
{
	ReplaceUI(RunTimeUI, MainMenuUI);
}

void ASwipeerPlayerController::ShowGameOverUI(float Score, float Record)
{
	GameOverUI->UpdatePoints(Score);
	GameOverUI->UpdateRecord(Record);
	ReplaceUI(GameOverUI, RunTimeUI);
}

