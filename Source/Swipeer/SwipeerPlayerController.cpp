// Property of Kamil Bochenski. All right's reserved.

#include "SwipeerPlayerController.h"
#include "Kismet/GameplayStatics.h"

void ASwipeerPlayerController::BeginPlay()
{
	Trunk = Cast<ATrunk>(UGameplayStatics::GetActorOfClass(GetWorld(), ATrunk::StaticClass()));
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