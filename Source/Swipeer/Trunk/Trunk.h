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
	// Sets default values for this actor's properties
	ATrunk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<UTrunkMainPart*>TrunkParts;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(CallInEditor)
	void NewPart();

	UFUNCTION(CallInEditor)
	void RemovePart();

	UPROPERTY(EditAnywhere)
	UStaticMesh* TrunkMainPartModel;

	UPROPERTY(EditAnywhere)
	UStaticMesh* TrunkWallModel;

	UPROPERTY()
	int PartCounter;

	UFUNCTION()
	UStaticMesh* GetStaticMesh(int id);
	
	UFUNCTION()
	void Turn(int Direction);

	UPROPERTY(EditAnywhere)
	TArray<UMaterial*>Materials;
	
	bool bIsMoving;
	float turnValue;
	float turnProgress;

	UPROPERTY(EditAnywhere)
	float turnSpeed;

};
