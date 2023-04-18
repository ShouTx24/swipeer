// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Trunk.generated.h"

USTRUCT(BlueprintType)
struct SWIPEER_API FMotive
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName MotiveName;
	
	UPROPERTY(EditAnywhere)
	UMaterialInstance* CoreMeshMaterial;
	
	UPROPERTY(EditAnywhere)
	TArray<UStaticMesh*> Walls;
};

class UTrunkCore;

UCLASS()
class SWIPEER_API ATrunk : public AActor
{
	GENERATED_BODY()
	
public:	
	ATrunk();
	virtual void BeginPlay() override;
	
	void NewPart();
	void RemovePart();

	UTrunkCore* GetHead() const;
	UTrunkCore* GetTail() const;
	
	UFUNCTION(BlueprintNativeEvent)
	void Turn(const int Direction);
	
	FMotive GetActiveMotive() const;
	
protected:
	void ChangeToNextMotive();
	
public:
	UPROPERTY(EditAnywhere);
	TArray<FMotive> Motives;

	UPROPERTY(EditAnywhere)
	int MotiveChangeThreshold = 50;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TurnSpeed = 1.f;

	UPROPERTY(EditAnywhere)
	UStaticMesh* TrunkCoreMesh;

	UPROPERTY(EditAnywhere)
	int TrunkLenght = 30;
	
	int PartCounter = 0;
	
private:
	FMotive ActiveMotive;
	uint8 ActiveMotiveID = 0;
	TDoubleLinkedList<UTrunkCore*> TrunkParts;
};
