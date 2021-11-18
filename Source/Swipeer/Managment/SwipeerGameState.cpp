// Property of Kamil Bochenski. All right's reserved.


#include "SwipeerGameState.h"
#include "Kismet/GameplayStatics.h"
#include "SwipeerGameInstance.h"
#include "../SwipeerPlayerController.h"

ASwipeerGameState::ASwipeerGameState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASwipeerGameState::BeginPlay()
{
	Super::BeginPlay();
	if (!GWorld) return;
	Pawn = UGameplayStatics::GetPlayerPawn(GWorld, 0);
	Trunk = Cast<ATrunk>(UGameplayStatics::GetActorOfClass(GWorld, ATrunk::StaticClass()));
	GameMode = Cast<ASwipeerGameModeBase>(UGameplayStatics::GetGameMode(GWorld));

}
void ASwipeerGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GameMode->BBallReachNextElement(Pawn, Trunk))
	{
		Score++;
		Cast<ASwipeerPlayerController>(GWorld->GetFirstPlayerController())->RunTimeUI->UpdateScore(GetScore());
	}
}

void ASwipeerGameState::GameOver(APawn* Player)
{
	// Call GameOver from GameMode object.
	GameMode->GameOver(Player);
}

int ASwipeerGameState::GetScore()
{
	return Score;
}

int ASwipeerGameState::GetEssence()
{
	return Essence;
}

void ASwipeerGameState::GiveEssence()
{
	Essence++;
	Cast<ASwipeerPlayerController>(GWorld->GetFirstPlayerController())->RunTimeUI->UpdateEssence(GetGameInstance<USwipeerGameInstance>()->PlayerData.playerEssence+Essence);
}