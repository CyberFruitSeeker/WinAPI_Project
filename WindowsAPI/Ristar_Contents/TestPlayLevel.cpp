#include "TestPlayLevel.h"
#include "TestPlayer.h"

UTestPlayLevel::UTestPlayLevel()
{
}

UTestPlayLevel::~UTestPlayLevel()
{
}

void UTestPlayLevel::BeginPlay()
{
	ULevel::BeginPlay();

	ATestPlayer* Player = SpawnActor<ATestPlayer>();
	Player->SetActorLocation({ 200, 200 });
}

void UTestPlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}