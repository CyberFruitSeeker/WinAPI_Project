#include "Mushroom.h"
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "Mario.h"
#include <EnginePlatform/EngineSound.h>


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


	// 마리오가 머쉬룸을 먹을 수 있는가?
	{
		MushroomCollision = CreateCollision(MarioCollisionOrder::Item);
		MushroomCollision->SetTransform({ { 0,-32 }, { 64, 64 } });
		MushroomCollision->SetColType(ECollisionType::Rect);
	}

	// 아이템 박스에서 머쉬룸이 나오는 애니메이션
	{

	}



}

void Mushroom::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}


void Mushroom::StateUpdate(float _DeltaTime)
{


	MarioMushroomEat();
	CalGravity(_DeltaTime);
	CalMove(_DeltaTime);
}

void Mushroom::CalMove(float _DeltaTime)
{
	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 80;
		break;
	case EActorDir::Right:
		CheckPos.X += 80;
		break;
	default:
		break;
	}
	CheckPos.Y -= 20;

	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(CheckPos.iX(), CheckPos.iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit(255, 0, 255, 0))
	{
		MoveVector.X *= -1.0f;
	}

	AddActorLocation(MoveVector * _DeltaTime * MoveSpeed);

	/*if (MaxMoveSpeed <= MoveVector.Size2D())
	{
		MoveVector = MoveVector.Normalize2DReturn() * MaxMoveSpeed;
	}*/

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


// 버섯이 마리오한테 먹혔다.
void Mushroom::MarioMushroomEat()
{
	std::vector<UCollision*> Result;
	if (true == MushroomCollision->CollisionCheck(MarioCollisionOrder::Player, Result))
	{
		Mario* Player = dynamic_cast<Mario*>(Result[0]->GetOwner());

		Player->MarioModeChange(MarioMode::BigMario);

		MushroomEatSound = UEngineSound::SoundPlay("GainMushRoom.wav");
		MushroomEatSound.On();


		Destroy(0.002f);
	}


}

// 머쉬룸이 아이템 블럭에서 나온다.
void Mushroom::MushroomMoveUp(float _DeltaTime)
{

}
