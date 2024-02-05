#include "TestPlayLevel.h"
#include "TestPlayer.h"
#include "BackGroundMap.h"
#include <EngineCore\EngineCore.h>

UTestPlayLevel::UTestPlayLevel()
{
}

UTestPlayLevel::~UTestPlayLevel()
{
}

void UTestPlayLevel::BeginPlay()
{
	ULevel::BeginPlay();

	ABackGroundMap* Map = SpawnActor<ABackGroundMap>();
	Map->SetMapImage("Stage1Map.png");
	Map->SetColMapImage("Stage1Map_Col.png");
	Map->SwitchDebug();


	ATestPlayer* Player = SpawnActor<ATestPlayer>();
	Player->SetActorLocation({ 200, 200 });



}

void UTestPlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}

void UTestPlayLevel::LevelStart(ULevel* _Level)
{
	// 여기서 리소스를 로드하고
	// 액터도 여기서 만들고
	int a = 0;
}
void UTestPlayLevel::LevelEnd(ULevel* _Level)
{
	// 리소스도 날려요.
	// 액터를 삭제한다.
	int a = 0;
}