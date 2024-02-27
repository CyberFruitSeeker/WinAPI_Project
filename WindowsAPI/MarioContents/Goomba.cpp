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
		Renderer->SetTransform({ {0,0},{384,384} });
	}

	
	// 굼바가 마리오랑 충돌 하는가?
	{
		GoombaCollision = CreateCollision(MonsterCollisionOreder::ColToMario);
		GoombaCollision->SetTransform({ {0,-32},{64,64} });
		GoombaCollision->SetColType(ECollisionType::Rect);
	}

	
}



void Goomba::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	{
		GravityVector += GravityAcc * _DeltaTime;
		Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
		if (Color == Color8Bit(255, 0, 255, 0))
		{
			GravityVector = FVector::Zero;
		}

		AddActorLocation(GravityVector);
	}


	
}






