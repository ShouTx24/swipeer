// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "BallPawn.generated.h"

class UCameraComponent;

UCLASS()
class SWIPEER_API ABallPawn : public APawn
{
	GENERATED_BODY()
	
public:
	ABallPawn();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyHit(class UPrimitiveComponent* MyComp,AActor* Other,class UPrimitiveComponent* OtherComp,bool bSelfMoved,FVector HitLocation,FVector HitNormal, FVector NormalImpulse,const FHitResult& Hit) override;

	void MoveForward(float DeltaTime);
	
public:
	// Centimeters per second
	UPROPERTY(EditAnywhere)
	double Speed = 1500;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditAnywhere)
	UCameraComponent* MainCamera;
};
