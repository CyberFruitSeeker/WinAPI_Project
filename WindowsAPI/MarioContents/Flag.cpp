#include "Flag.h"
#include <EngineCore/EngineCore.h>
#include <EngineCore/Actor.h>
#include "Mario.h"

Flag::Flag()
{
}

Flag::~Flag()
{
}

void Flag::BeginPlay()
{

	SetName("Flag");
	Renderer = CreateImageRenderer(MarioRenderOrder::Item);
	Renderer->SetImage("Flag.png");
	Renderer->SetScale({ 64,688 });

	FlagCollision = CreateCollision(MarioCollisionOrder::Item);
	FlagCollision->SetTransform({ { 0,0 }, { 16,688 } });
	FlagCollision->SetColType(ECollisionType::Rect);

	DownFlagCollision = CreateCollision(MarioCollisionOrder::Item);
	DownFlagCollision->SetTransform({ { 0,312 }, { 64,64 } });
	DownFlagCollision->SetColType(ECollisionType::Rect);

}

void Flag::Tick(float _DeltaTime)
{

}

// 마리오가 Flag에 닿은 다음, 레벨 or 엔딩 타이틀로 간다.
void Flag::GoToLextLevel(float _DeltaTime)
{

}
