// Property of Kamil Bochenski. All right's reserved.

#include "BallPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Managment/SwipeerGameState.h"

ABallPawn::ABallPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = StaticMeshComponent;
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetRelativeLocationAndRotation(FVector(-500, 0, 150), FQuat(FRotator(-10, 0, 0)));
	MainCamera->SetupAttachment(RootComponent);
}

void ABallPawn::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(false);
}

void ABallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MoveForward(DeltaTime);
}

void ABallPawn::MoveForward(float DeltaTime)
{
	const FVector ForwardSpeed = GetActorForwardVector() * DeltaTime * Speed;
	const FVector CurrentLocation = GetActorLocation();
	SetActorLocation(CurrentLocation + ForwardSpeed, true);
}

void ABallPawn::NotifyHit(class UPrimitiveComponent* MyComp,AActor* Other,class UPrimitiveComponent* OtherComp,bool bSelfMoved,FVector HitLocation,FVector HitNormal,FVector NormalImpulse,const FHitResult& Hit)
{
	Cast<ASwipeerGameModeBase>(UGameplayStatics::GetGameMode(GWorld))->GameOver();
}