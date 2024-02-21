#include "Goomba.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include <vector>

Goomba::Goomba()
{
}

Goomba::~Goomba()
{
}

Goomba* Goomba::JustGoomba = nullptr;

Goomba* Goomba::GetJustGoomba()
{
	return JustGoomba;
}

void Goomba::BeginPlay()
{
	AActor::BeginPlay();
	JustGoomba = this;
	{
		SetName("Goomba");
		Renderer = CreateImageRenderer(MarioRenderOrder::Monster);
		Renderer->SetImage("Goomba.png");
		Renderer->SetTransform({ {0,0},{256,256} });
	}

	StateChange = MonsterState::Idle;
}

void Goomba::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}


void Goomba::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		GravityVector = FVector::Zero;
	}
}

void Goomba::MoveLastMoveVector(float _DeltaTime)
{
	LastMoveVector = LastMoveVector + GravityVector;
}

void Goomba::MoveUpdate(float _DeltaTime)
{
	CalGravityVector(_DeltaTime);
}



