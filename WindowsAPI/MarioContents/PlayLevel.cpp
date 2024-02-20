#include "PlayLevel.h"
#include "Mario.h"
#include "MarioMap.h"
#include <EngineCore/EngineCore.h>

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::BeginPlay()
{
	ULevel::BeginPlay();

	MarioMap* Map = SpawnActor<MarioMap>(MarioRenderOrder::Map);
	Map->SetMapImage("MarioWorld01.png");
	Map->SetColMapImage("MarioWorld01_Col.png");
	Map->SwitchDebug();


	Mario* NewActor = SpawnActor<Mario>(MarioRenderOrder::Player);
	NewActor->SetName("Player");
	NewActor->SetActorLocation({ 200,830 });


}

void PlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}

void PlayLevel::LevelStart(ULevel* _Level)
{
	// 리소스를 로드하고, 액터를 만드는 역할 우선 넣어준다.
	int a = 0;
}

void PlayLevel::LevelEnd(ULevel* _Level)
{
	// 리소스를 날리고, 액터를 삭제하는 역할 우선 넣어준다.
	int a = 0;
}