// Property of Kamil Bochenski. All right's reserved.

#include "SwipeerPlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Managment/SwipeerGameInstance.h"

ASwipeerPlayerController::ASwipeerPlayerController()
{
	ConstructorHelpers::FClassFinder<UUserWidget> RunTimeUIClassBP(TEXT("/Game/UI/RunTimeUI"));
	RunTimeUIClass = RunTimeUIClassBP.Class;
}

void ASwipeerPlayerController::BeginPlay()
{
	Trunk = Cast<ATrunk>(UGameplayStatics::GetActorOfClass(GetWorld(), ATrunk::StaticClass()));
	if (!RunTimeUIClass) return;
	RunTimeUI = Cast<URunTimeUI>(CreateWidget<UUserWidget>(this, RunTimeUIClass));
	RunTimeUI->AddToViewport();
	RunTimeUI->SetRecord(GetGameInstance<USwipeerGameInstance>()->PlayerData.playerRecord);
	RunTimeUI->UpdateEssence(GetGameInstance<USwipeerGameInstance>()->PlayerData.playerEssence);
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