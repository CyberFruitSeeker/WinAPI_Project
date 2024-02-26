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

void Goomba::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);


}

void Goomba::Idle(float _DeltaTime)
{
	GravityCheck(_DeltaTime);
}
