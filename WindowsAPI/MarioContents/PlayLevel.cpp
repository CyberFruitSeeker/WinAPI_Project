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
	// ���ҽ��� �ε��ϰ�, ���͸� ����� ���� �켱 �־��ش�.
	int a = 0;
}

void PlayLevel::LevelEnd(ULevel* _Level)
{
	// ���ҽ��� ������, ���͸� �����ϴ� ���� �켱 �־��ش�.
	int a = 0;
}