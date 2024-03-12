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

// �������� Flag�� ���� ����, ���� or ���� Ÿ��Ʋ�� ����.
void Flag::GoToLextLevel(float _DeltaTime)
{

}
