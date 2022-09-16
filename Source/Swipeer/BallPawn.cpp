// Property of Kamil Bochenski. All right's reserved.

#include "BallPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Managment/SwipeerGameState.h"


ABallPawn::ABallPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> NewPartMesh(TEXT("/Game/Sphere"));
	Mesh->SetStaticMesh(NewPartMesh.Object);
	RootComponent = Mesh;

	UCameraComponent* MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
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
	SetActorLocation(GetActorLocation() + FVector(0, 1500 * DeltaTime, 0), true);
}

void ABallPawn::NotifyHit(class UPrimitiveComponent* MyComp,AActor* Other,class UPrimitiveComponent* OtherComp,bool bSelfMoved,FVector HitLocation,FVector HitNormal,FVector NormalImpulse,const FHitResult& Hit)
{
	Cast<ASwipeerGameState>(UGameplayStatics::GetGameState(GWorld))->GameOver(Cast<APawn>(MyComp->GetOwner()));
}