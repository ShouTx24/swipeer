// Property of Kamil Bochenski. All right's reserved.

#include "Trunk.h"
#include "TrunkMainPart.h"

ATrunk::ATrunk()
{
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	UTrunkMainPart* NewPart = CreateDefaultSubobject<UTrunkMainPart>(TEXT("DefaultPartComponent"));
	NewPart->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	NewPart->RegisterComponent();
	
	ConstructorHelpers::FObjectFinder<UStaticMesh> NewPartMesh(TEXT("/Game/Trunk/TrunkMeshes/Part"));
	if (!NewPartMesh.Succeeded()) return;
	
	TrunkMainPartModel = NewPartMesh.Object;
	NewPart->SetStaticMesh(NewPartMesh.Object);
	TrunkParts.Add(NewPart);
}

void ATrunk::BeginPlay()
{
	Super::BeginPlay();
	if (!TrunkMainPartModel || !TrunkWallModel) return;
	
	turnSpeed *= 60;
	while(PartCounter < 30) NewPart();
}

void ATrunk::NewPart()
{
	UTrunkMainPart* NewPart = NewObject<UTrunkMainPart>(this);
	NewPart->SetRelativeLocation(FVector(0, TrunkParts.Top()->GetRelativeLocation().Y + (TrunkMainPartModel->GetBounds().BoxExtent.Y * 2), 0));
	NewPart->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	NewPart->RegisterComponent();
	NewPart->SetMaterial(0, Materials[0]);
	TrunkParts.Add(NewPart);
	PartCounter++;
}

void ATrunk::RemovePart()
{
	TArray<USceneComponent*> ChildrenComponents;
	TrunkParts[0]->GetChildrenComponents(true, ChildrenComponents);
	while (ChildrenComponents.IsValidIndex(0))
	{
		ChildrenComponents[0]->DestroyComponent();
		ChildrenComponents.RemoveAt(0);
	}
	TrunkParts[0]->DestroyComponent(false);
	TrunkParts.RemoveAt(0); 
	NewPart();
}

void ATrunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (turnProgress >= turnSpeed) bIsMoving = false;
	if (bIsMoving)
	{
		AddActorLocalRotation(FQuat(FRotator(turnValue, 0, 0)));
		turnProgress++;
	}
}

UStaticMesh* ATrunk::GetStaticMesh(int type)
{
	if (!TrunkMainPartModel || !TrunkWallModel) return nullptr;
	if (type == 1) return TrunkMainPartModel;
	else return TrunkWallModel;
}

void ATrunk::Turn(int Direction)
{
	if (bIsMoving) return;
	bIsMoving = true;
	turnValue = 45 / turnSpeed * Direction;
	turnProgress = 0;
}