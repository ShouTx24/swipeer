// Property of Kamil Bochenski. All right's reserved.

#include "SwipeerGameModeBase.h"
#include "DrawDebugHelpers.h"

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

	PlayerController = Cast<ASwipeerPlayerController>(UGameplayStatics::GetPlayerController(GWorld, 0));
}
void ASwipeerGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, __func__);

	if (bBallHasReachedNextElement(Pawn))
	{
		Score++;
		PlayerController->UpdateRuntimeUIData(Score);
	}
}
bool ASwipeerGameModeBase::bBallHasReachedNextElement(APawn* Ball)
{
	DrawDebugLine(GWorld, Ball->GetActorLocation(), Ball->GetActorLocation() - Trunk->GetLastPart()->GetComponentLocation(), FColor::Red, false, 15);

	if ((Ball->GetActorLocation() - Trunk->GetLastPart()->GetComponentLocation()).Size() < -100)
	{
		Trunk->RemovePart();
		if (Trunk->PartCounter > 34)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void ASwipeerGameModeBase::StartGame()
{
	USwipeerGameInstance* SGI = GetGameInstance<USwipeerGameInstance>();
	
	PlayerController->ShowStartGameUI();
	PlayerController->UpdateRuntimeUIData(0, SGI->PlayerData.PlayerEssence, SGI->PlayerData.PlayerRecord);
	UGameplayStatics::GetPlayerPawn(GWorld, 0)->SetActorTickEnabled(true);
}

void ASwipeerGameModeBase::GameOver(APawn* Player)
{
	//Stops pawn form moving and creating additional GameOver event executions.
	Cast<ABallPawn>(Player)->SetActorTickEnabled(false);

	// Check if player beats it's former record.
	int currentRecord = GetGameInstance<USwipeerGameInstance>()->PlayerData.PlayerRecord;
	int currentScore = Score;
	if (currentScore > currentRecord)
	{
		currentRecord = GetGameInstance<USwipeerGameInstance>()->PlayerData.PlayerRecord = currentScore;
	}

	// Adding new Essence to general account
	GetGameInstance<USwipeerGameInstance>()->PlayerData.PlayerEssence += Essence;

	// User Interface
	PlayerController->ShowGameOverUI(Score, currentRecord);

	// Save Game
	UPlayerDataSave* Save = Cast<UPlayerDataSave>(UGameplayStatics::CreateSaveGameObject(UPlayerDataSave::StaticClass()));
	Save->SaveData(GetGameInstance<USwipeerGameInstance>()->PlayerData);
	UGameplayStatics::SaveGameToSlot(Save, FString("Save"), 0);
}

void ASwipeerGameModeBase::GiveEssence()
{
	Essence++;
	PlayerController->UpdateRuntimeUIData(Score, Essence);
}
