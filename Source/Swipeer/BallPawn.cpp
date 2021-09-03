// Property of Kamil Bochenski. All right's reserved.

#include "BallPawn.h"

ABallPawn::ABallPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABallPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ABallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABallPawn::MoveForward()
{
}
