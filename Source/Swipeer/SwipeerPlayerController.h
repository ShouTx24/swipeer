// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Trunk/Trunk.h"
#include "SwipeerPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SWIPEER_API ASwipeerPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
		
	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

	void TouchStart(ETouchIndex::Type FingerIndex, FVector Location);

	FVector TouchStartLocation;

	ATrunk* Trunk;

	void GetSwipeDirection();

};
