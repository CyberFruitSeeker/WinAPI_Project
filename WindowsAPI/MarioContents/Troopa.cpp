#include "Troopa.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include <vector>

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
		SetName("Troopa");
		Renderer = CreateImageRenderer(MarioRenderOrder::Monster);
		Renderer->SetImage("Troopa_Left.png");
		Renderer->SetTransform({ {0,0},{512,384} });
	}

	// 트루파가 마리오랑 충돌하는가?

}



void Troopa::Tick(float _DeltaTime)
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
