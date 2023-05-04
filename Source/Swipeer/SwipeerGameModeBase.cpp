// Property of Kamil Bochenski. All right's reserved.
#include "SwipeerGameModeBase.h"

#include "BallPawn.h"
#include "Managment/PlayerDataSave.h"
#include "Managment/SwipeerGameInstance.h"
#include "Managment/SwipeerGameState.h"
#include "SwipeerPlayerController.h"
#include "Trunk/Trunk.h"
#include "Trunk/TrunkCore.h"

ASwipeerGameModeBase::ASwipeerGameModeBase(const FObjectInitializer& ObjectInitializer)
{
	DefaultPawnClass = ABallPawn::StaticClass();
	PlayerControllerClass = ASwipeerPlayerController::StaticClass();
	GameStateClass = ASwipeerGameState::StaticClass();
	
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
}

void ASwipeerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	Trunk = Cast<ATrunk>(UGameplayStatics::GetActorOfClass(GetWorld(), ATrunk::StaticClass()));
	PlayerController = Cast<ASwipeerPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	Pawn = Cast<ABallPawn>(PlayerController->GetPawn());
}
void ASwipeerGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (Pawn && BallHasReachedNextElement(*Pawn))
	{
		Score++;
		PlayerController->UpdateRuntimeUIData(Score);
		Trunk->RemovePart();
	}
}
bool ASwipeerGameModeBase::BallHasReachedNextElement(const APawn& Ball) const
{
	if (!Trunk)
	{
		return false;
	}
	const float Distance = (Ball.GetActorLocation() - Trunk->GetHead()->GetComponentLocation()).Size();
	const float CoreLength = Trunk->GetActorScale().Y * Trunk->TrunkCoreMesh->GetBounds().BoxExtent.Y * 2;
	const uint8 TrunkLenght = Trunk->TrunkLenght - 3;
	return Distance <  CoreLength * TrunkLenght;
}

void ASwipeerGameModeBase::StartGame()
{
	// Fetch PlayerData from Game Instance
	USwipeerGameInstance* SwipeerGameInstance = GetGameInstance<USwipeerGameInstance>();
	checkf(SwipeerGameInstance, TEXT("GameInstance is null!"));

	// Update UI
	checkf(PlayerController, TEXT("PlayerController is null!"));
	PlayerController->ShowStartGameUI();
	PlayerController->UpdateRuntimeUIData(0, SwipeerGameInstance->PlayerData.PlayerEssence, SwipeerGameInstance->PlayerData.PlayerRecord);

	// Start Moving
	Pawn->SetActorTickEnabled(true);
}

void ASwipeerGameModeBase::GameOver()
{
	// Stops pawn form moving and creating additional GameOver event executions.
	Pawn->SetActorTickEnabled(false);

	// Check if player beats it's former record.
	USwipeerGameInstance* SwipeerGameInstance = GetGameInstance<USwipeerGameInstance>();
	int CurrentRecord = SwipeerGameInstance->PlayerData.PlayerRecord;
	const int CurrentScore = Score;
	if (CurrentScore > CurrentRecord)
	{
		CurrentRecord = SwipeerGameInstance->PlayerData.PlayerRecord = CurrentScore;
	}

	// Adding new Essence to general account
	SwipeerGameInstance->PlayerData.PlayerEssence += Essence;

	// Update UI
	PlayerController->ShowGameOverUI(Score, CurrentRecord);

	// Save Game
	UPlayerDataSave* Save = Cast<UPlayerDataSave>(UGameplayStatics::CreateSaveGameObject(UPlayerDataSave::StaticClass()));
	Save->SaveData(SwipeerGameInstance->PlayerData);
	UGameplayStatics::SaveGameToSlot(Save, TEXT("Save"), 0);
}

void ASwipeerGameModeBase::GiveEssence()
{
	Essence++;
	PlayerController->UpdateRuntimeUIData(Score, Essence);
}
