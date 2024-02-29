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
	AActor::BeginPlay();
	{
		// 트루파 셋트랜스폼 크기 : 512, 384
		SetName("Troopa");
		Renderer = CreateImageRenderer(MarioRenderOrder::Monster);
		Renderer->SetImage("Troopa_Left.png");
		Renderer->CreateAnimation("Go", "Troopa_Left.png", 0, 1, 0.2f);
		Renderer->ChangeAnimation("Go");
		//Renderer->SetScale({ 512,384 });
		Renderer->SetTransform({ {0,0},{512,384} });
	}

	// 트루파가 마리오랑 충돌하는가?
	{
		BodyCollision = CreateCollision(MarioCollisionOrder::Monster);
		BodyCollision->SetTransform({ { 0,-32 }, { 64, 64 } });
		BodyCollision->SetColType(ECollisionType::Rect);
	}
}



void Troopa::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	CalGravity(_DeltaTime);
}

void Troopa::CalGravity(float _DeltaTime)
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
