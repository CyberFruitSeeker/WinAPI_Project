#include "GoombaDark.h"
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include <EngineBase/EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"


GoombaDark::GoombaDark()
{
}

GoombaDark::~GoombaDark()
{
}

void GoombaDark::BeginPlay()
{
	AActor::BeginPlay();
	{
		SetName("GoombaDark");
		Renderer = CreateImageRenderer(MarioRenderOrder::Monster);
		Renderer->SetImage("GoombaDark.png");
		Renderer->SetTransform({ {0,0},{424,424} });



	}

	// 굼바가 마리오랑 충돌 하는가?
	{
		BodyCollision = CreateCollision(MarioCollisionOrder::Monster);
		BodyCollision->SetTransform({ {0,-32},{64,64} });
		BodyCollision->SetColType(ECollisionType::Rect);
	}


}

void GoombaDark::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	CalGravity(_DeltaTime);


}

void GoombaDark::CalGravity(float _DeltaTime)
{

	{
		GravityVector += GravityAccel * _DeltaTime;
		Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
		if (Color == Color8Bit(255, 0, 255, 0))
		{
			GravityVector = FVector::Zero;
		}

		AddActorLocation(GravityVector);
	}

}

