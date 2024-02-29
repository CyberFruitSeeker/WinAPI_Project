#include "Goomba.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include <EngineCore/Actor.h>

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
		Renderer->SetScale({384, 384});
		Renderer->CreateAnimation("Move", "Goomba.png", 0, 1, 0.2f);
		Renderer->ChangeAnimation("Move");
	}

	
	// ���ٰ� �������� �浹 �ϴ°�?
	{
		BodyCollision = CreateCollision(MarioCollisionOrder::Monster);
		BodyCollision->SetTransform({ {0,-32},{64,64} });
		BodyCollision->SetColType(ECollisionType::Rect);
	}

	
}


void Goomba::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	CalGravity(_DeltaTime);
	
}

void Goomba::CalGravity(float _DeltaTime)
{

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

std::string Goomba::GetAnimationName(std::string _Name)
{


	return _Name;
}

void Goomba::StateUpdate(float _DeltaTime)
{
	


}





