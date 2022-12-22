// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"
#include "Trunk.generated.h"

class UTrunkMainPart;

UCLASS()
class SWIPEER_API ATrunk : public AActor
{
	GENERATED_BODY()
	
public:	
	ATrunk();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(CallInEditor)
	void NewPart();

	UFUNCTION(CallInEditor)
	void RemovePart();

	UStaticMeshComponent* GetLastPart();
	UStaticMeshComponent* GetTopPart();

	UFUNCTION()
	UStaticMesh* GetStaticMesh(int id);
	
	UFUNCTION()
	void Turn(int Direction);

	UPROPERTY(EditAnywhere)
	UStaticMesh* TrunkMainPartModel;

	UPROPERTY(EditAnywhere)
	UStaticMesh* TrunkWallModel;

	UPROPERTY()
	int PartCounter;

	UPROPERTY(EditAnywhere)
	TArray<UMaterial*>Materials;
	
	bool bIsMoving;
	float turnValue;
	float turnProgress;

	UPROPERTY(EditAnywhere)
	float turnSpeed;

protected:
	virtual void BeginPlay() override;

	TArray<UTrunkMainPart*>TrunkParts;

};
