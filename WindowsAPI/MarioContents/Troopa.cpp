#include "Troopa.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>
#include "StateControl.h"

Troopa::Troopa()
{
}

Troopa::~Troopa()
{
}

void Troopa::BeginPlay()
{
	StateControl::BeginPlay();
	{
		SetName("Troopa");
		Renderer = CreateImageRenderer(MarioRenderOrder::Monster);
		Renderer->SetImage("Troopa_Left.png");
		Renderer->SetTransform({ {0,0},{512,384} });
	}

	// 트루파가 마리오랑 충돌하는가?
	{
		BodyCollision = CreateCollision(MarioCollisionOrder::Monster);
		BodyCollision->SetTransform({ { -32,-32 }, { 64, 64 } });
		BodyCollision->SetColType(ECollisionType::Rect);
	}
}



void Troopa::Tick(float _DeltaTime)
{
	StateControl::Tick(_DeltaTime);

}
