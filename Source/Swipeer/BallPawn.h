// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BallPawn.generated.h"

UCLASS()
class SWIPEER_API ABallPawn : public APawn
{
	GENERATED_BODY()

public:

	ABallPawn();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void MoveForward(float DeltaTime);
	int score{ 0 };

};
