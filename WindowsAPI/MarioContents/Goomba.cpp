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

void Goomba::BeginPlay()
{
	AActor::BeginPlay();
	{
		SetName("Goomba");
		Renderer = CreateImageRenderer(MarioRenderOrder::Monster);
		Renderer->SetImage("Goomba.png");
		Renderer->SetTransform({ {0,0},{256,256} });
	}

	StateChange = MonsterState::Idle;
}

Goomba* Goomba::ItsGoomba = nullptr;

Goomba* Goomba::JustGoomba()
{
	return ItsGoomba;
}



void Goomba::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);


}

void Goomba::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAcc * _DeltaTime;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color==Color8Bit(255, 0, 255, 0))
	{
		GravityVector = FVector::Zero;
	}

}

void Goomba::CalLastMoveVector(float _DeltaTime)
{

}

