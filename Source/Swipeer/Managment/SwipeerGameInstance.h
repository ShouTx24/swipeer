// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "SwipeerGameInstance.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerData
{
	GENERATED_BODY(BlueprintType)

	UPROPERTY(BlueprintReadOnly)
	FName playerName;
	
	UPROPERTY(BlueprintReadOnly)
	int playerRecord;
	
	UPROPERTY(BlueprintReadOnly)
	int playerEssence;
	
	UPROPERTY(BlueprintReadWrite)
	bool premiumUser;

	FPlayerData()
	{
		playerName = FName("Player");
		playerRecord = 0;
		playerEssence = 0;
		premiumUser = false;
	}

	//UPROPERTY()
	//X selectedSkin;
	//
	//UPROPERTY()
	//Y unlockedSkins;
};

UCLASS()
class SWIPEER_API USwipeerGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite)
	FPlayerData PlayerData = FPlayerData();

	virtual void Init();
};
