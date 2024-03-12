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
	Renderer = CreateImageRenderer(MarioRenderOrder::FlagEnum);
	Renderer->SetImage("Flag.png");
	Renderer->SetScale({ 64,688 });

	FlagUpCollision = CreateCollision(MarioCollisionOrder::FlagUp);
	FlagUpCollision->SetTransform({ { 0,0 }, { 16,688 } });
	FlagUpCollision->SetColType(ECollisionType::Rect);

	FlagDownCollision = CreateCollision(MarioCollisionOrder::FlagDown);
	FlagDownCollision->SetTransform({ { 0,312 }, { 64,64 } });
	FlagDownCollision->SetColType(ECollisionType::Rect);

}

void Flag::Tick(float _DeltaTime)
{

}

// 마리오가 Flag에 닿은 다음, 레벨 or 엔딩 타이틀로 간다.
void Flag::GoToLextLevel(float _DeltaTime)
{

}
