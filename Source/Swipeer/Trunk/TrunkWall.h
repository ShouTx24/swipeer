// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "TrunkMainPart.h"
#include "TrunkWall.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEER_API UTrunkWall : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

protected:
	virtual void BeginPlay() override;
};
