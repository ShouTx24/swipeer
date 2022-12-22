// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "SwipeerGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FPlayerData
{
	GENERATED_BODY(BlueprintType)

	UPROPERTY(BlueprintReadOnly)
	FName PlayerName;
	
	UPROPERTY(BlueprintReadOnly)
	int PlayerRecord;
	
	UPROPERTY(BlueprintReadOnly)
	int PlayerEssence;
	
	UPROPERTY(BlueprintReadWrite)
	bool PremiumUser;
};

UCLASS()
class SWIPEER_API USwipeerGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite)
	FPlayerData PlayerData;

	virtual void Init();
};
