// Property of Kamil Bochenski. All right's reserved.

#include "BallPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"

ABallPawn::ABallPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	
	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> NewPartMesh(TEXT("/Game/Trunk/TrunkMeshes/Part"));
	Mesh->SetStaticMesh(NewPartMesh.Object);
	Mesh->SetWorldScale3D(FVector(0.7, 0.2, 0.7));
	RootComponent = Mesh;

	UCameraComponent* MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetRelativeLocationAndRotation(FVector(-500, 0, 150), FQuat(FRotator(-10, 0, 0)));
	MainCamera->SetupAttachment(RootComponent);
}

void ABallPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ABallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForward(DeltaTime);
}

void ABallPawn::MoveForward(float DeltaTime)
{
	FHitResult Hit;
	SetActorLocation(GetActorLocation() + FVector(0, 1500 * DeltaTime, 0), true, &Hit);
	if (Hit.IsValidBlockingHit()) GEngine->AddOnScreenDebugMessage(5, 10, FColor::Red, FString("Game Over!"));
}
