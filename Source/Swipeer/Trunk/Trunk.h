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

	UPROPERTY(VisibleAnywhere)
	int PartCounter = 1;

	UStaticMesh* GetStaticMesh(int id);
	
	void Turn(int Direction);

	bool bIsMoving{ false };
	float turnValue{ 0 };
	float turnProgress{ 0 };

	UPROPERTY(EditAnywhere)
	float turnSpeed{ 1.f };

	UFUNCTION(CallInEditor)
	void R();
	UFUNCTION(CallInEditor)
	void L();
};
