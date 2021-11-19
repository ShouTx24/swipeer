// Property of Kamil Bochenski. All right's reserved.


#include "SwipeerGameState.h"


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
	PlayerController = Cast<ASwipeerPlayerController>(GWorld->GetFirstPlayerController());

}
void ASwipeerGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GameMode->BBallReachNextElement(Pawn, Trunk))
	{
		Score++;
		PlayerController->RunTimeUI->UpdateScore(GetScore());
	}
}

void ASwipeerGameState::StartGame()
{
	GameMode->StartGame();
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
	PlayerController->RunTimeUI->UpdateEssence(GetGameInstance<USwipeerGameInstance>()->PlayerData.playerEssence + GetEssence());
}