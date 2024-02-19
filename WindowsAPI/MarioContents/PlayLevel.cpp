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
	{
		MarioMap* Map = SpawnActor<MarioMap>(MarioRenderOrder::Map);
		Map->SetMapImage("MarioWorld01.png");
		Map->SetColMapImage("MarioWorld01_Col.png");
		Map->SwitchDebug();

	}

	{
		Mario* NewActor = SpawnActor<Mario>();
		NewActor->SetName("Player");
		NewActor->SetActorLocation({ 200,200 });
	}

}

void PlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}

void PlayLevel::LevelStart(ULevel* _Level)
{
	// ���ҽ��� �ε��ϰ�, ���͸� ����� ����
	int a = 0;
}

void PlayLevel::LevelEnd(ULevel* _Level)
{
	// ���ҽ��� ������, ���͸� �����ϴ� ����
	int a = 0;
}