// Property of Kamil Bochenski. All right's reserved.


#include "SwipeerGameState.h"
#include "Kismet/GameplayStatics.h"

ASwipeerGameState::ASwipeerGameState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASwipeerGameState::BeginPlay()
{
	Super::BeginPlay();

	Pawn = UGameplayStatics::GetPlayerPawn(GWorld, 0);
	Trunk = Cast<ATrunk>(UGameplayStatics::GetActorOfClass(GetWorld(), ATrunk::StaticClass()));
	GameMode = Cast<ASwipeerGameModeBase>(UGameplayStatics::GetGameMode(GWorld));

}
void ASwipeerGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GameMode->BBallReachNextElement(Pawn, Trunk);
}