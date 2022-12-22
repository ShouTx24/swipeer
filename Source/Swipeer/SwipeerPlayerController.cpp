// Property of Kamil Bochenski. All right's reserved.

#include "SwipeerPlayerController.h"
#include "UI/GameOverUI.h"
#include "UI/MainMenuUI.h"
#include "UI/RuntimeUI.h"

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
	GetSwipeDirection();
}

void ASwipeerPlayerController::TouchStart(ETouchIndex::Type FingerIndex, FVector Location)
{
	TouchStartLocation = Location;
}

void ASwipeerPlayerController::UpdateRuntimeUIData(float Points, float Essence, float Record)
{
	RunTimeUI->UpdateScore(Points);
	
	if (Essence != NULL)
	{
		RunTimeUI->UpdateEssence(Essence);
	}

	if (Record != NULL)
	{
		RunTimeUI->UpdateRecord(Record);
	}
}

void ASwipeerPlayerController::ReplaceUI(UUserWidget* Show, UUserWidget* Hide)
{
	if (Hide)
	{
		if (Hide->IsInViewport())
		{
			Hide->RemoveFromViewport();
		}
	}
	if (Show)
	{
		if (Show->IsInViewport())
		{
			return;
		}
		Show->AddToViewport();
	}
}

void ASwipeerPlayerController::ShowStartGameUI()
{
	ReplaceUI(RunTimeUI, MainMenuUI);
}

void ASwipeerPlayerController::ShowGameOverUI(float Score, float Record)
{
	ReplaceUI(GameOverUI, RunTimeUI);
	GameOverUI->UpdatePoints(Score);
	GameOverUI->UpdateRecord(Record);
}

void ASwipeerPlayerController::GetSwipeDirection()
{
	FVector CurrentLocation;
	bool bTouchActive;
	GetInputTouchState(ETouchIndex::Touch1, CurrentLocation.X, CurrentLocation.Y, bTouchActive);
	if (!bTouchActive) return;

	if (TouchStartLocation.X - 40 >= CurrentLocation.X)
	{
		Trunk->Turn(-1);
	}
	else if (TouchStartLocation.X + 40 <= CurrentLocation.X)
	{
		Trunk->Turn(1);
	}
}

