#include "StateControl.h"
#include "ContentsHelper.h"
#include <EngineCore/Actor.h>

StateControl::StateControl()
{

}

StateControl::~StateControl()
{

}

void StateControl::BeginPlay()
{
	AActor::BeginPlay();
}

void StateControl::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	CalGravity(_DeltaTime);
}

// ===== 중력 적용 및 계산 =====
void StateControl::CalGravity(float _DeltaTime)
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
