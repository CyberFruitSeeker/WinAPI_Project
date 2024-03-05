#include "Mushroom.h"
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "Mario.h"


Mushroom::Mushroom()
{
}

Mushroom::~Mushroom()
{
}

void Mushroom::BeginPlay()
{
	SetName("MushRoom");
	Renderer = CreateImageRenderer(MarioRenderOrder::Item);
	Renderer->SetImage("Item.png");
	Renderer->SetScale({ 128,128 });


}

void Mushroom::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	CalGravity(_DeltaTime);
	CalMove(_DeltaTime);

}


void Mushroom::StateUpdate(float _DeltaTime)
{

}

void Mushroom::CalMove(float _DeltaTime)
{
	
	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 40;
		break;
	case EActorDir::Right:
		CheckPos.X += 40;
		break;
	default:
		break;
	}
	CheckPos.Y -= 20;

	MoveVector* _DeltaTime;
	AddActorLocation(MoveVector);
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(CheckPos.iX(), CheckPos.iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit(255, 0, 255, 0))
	{
		MoveVector = FVector::Zero;
	}


}

void Mushroom::CalGravity(float _DeltaTime)
{
	GravityVector += GravityAccel * _DeltaTime;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		GravityVector = FVector::Zero;
	}

	AddActorLocation(GravityVector);

}

void Mushroom::DirCheck()
{

}

void Mushroom::MushroomUp()
{

}
