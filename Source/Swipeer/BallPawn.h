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
	
	UPROPERTY(EditAnywhere)
	double Speed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void MoveForward(float DeltaTime);
	virtual void NotifyHit(class UPrimitiveComponent* MyComp,AActor* Other,class UPrimitiveComponent* OtherComp,bool bSelfMoved,FVector HitLocation,FVector HitNormal, FVector NormalImpulse,const FHitResult& Hit) override;
};
