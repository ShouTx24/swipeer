// Property of Kamil Bochenski. All right's reserved.

#include "SwipeerPlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Managment/SwipeerGameState.h"
#include "Managment/SwipeerGameInstance.h"

ASwipeerPlayerController::ASwipeerPlayerController()
{
	ConstructorHelpers::FClassFinder<UUserWidget> RunTimeUIClassBP(TEXT("/Game/UI/RunTimeUI"));
	RunTimeUIClass = RunTimeUIClassBP.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> GameOverUIClassBP(TEXT("/Game/UI/GameOverUI"));
	GameOverUIClass = GameOverUIClassBP.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuUIClassBP(TEXT("/Game/UI/Menu/MainMenuUI"));
	MainMenuUIClass = MainMenuUIClassBP.Class;
}

void ASwipeerPlayerController::BeginPlay()
{
	Trunk = Cast<ATrunk>(UGameplayStatics::GetActorOfClass(GetWorld(), ATrunk::StaticClass()));
	
	if (!MainMenuUIClass) return;
	MainMenuUI = Cast<UMainMenuUI>(CreateWidget<UUserWidget>(this, MainMenuUIClass));
	MainMenuUI->AddToViewport();

	if (!RunTimeUIClass) return;
	RunTimeUI = Cast<URunTimeUI>(CreateWidget<UUserWidget>(this, RunTimeUIClass));

	if (!GameOverUIClass) return;
	GameOverUI = Cast<UGameOverUI>(CreateWidget<UUserWidget>(this, GameOverUIClass));
}

void ASwipeerPlayerController::GameStarted()
{
	MainMenuUI->RemoveFromParent();
	RunTimeUI->UpdateRecord(GetGameInstance<USwipeerGameInstance>()->PlayerData.playerRecord);
	RunTimeUI->UpdateEssence(GetGameInstance<USwipeerGameInstance>()->PlayerData.playerEssence);
	RunTimeUI->AddToViewport();
	Cast<ASwipeerGameState>(GWorld->GetGameState())->StartGame();
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

void ASwipeerPlayerController::GameOver(int Score, int Record, bool bNewRecord)
{
	if(RunTimeUI->IsInViewport()) RunTimeUI->RemoveFromParent();
	
	GameOverUI->AddToViewport();
	GameOverUI->UpdatePoints(Score);
	GameOverUI->UpdateRecord(Record);
}