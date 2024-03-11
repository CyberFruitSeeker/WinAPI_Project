#include "BrickBlock.h"
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include "Mario.h"
#include "BlockCommonClass.h"


BrickBlock::BrickBlock()
{
}

BrickBlock::~BrickBlock()
{
}

void BrickBlock::BeginPlay()
{
	{
		SetName("BrickBlock");
		Renderer = CreateImageRenderer(MarioRenderOrder::Block);
		Renderer->SetImage("BrickBlock.png");
		Renderer->SetScale({ 500,500 });

	}


	// block 콜리전
	{
		BlockCollision = CreateCollision(MarioCollisionOrder::Block);
		BlockCollision->SetTransform({ {0,0},{64,64} });
		BlockCollision->SetColType(ECollisionType::Rect);
	}

	// Brick Block에만 있는 Brick Block Break 애니메이션
	{

	}





}

void BrickBlock::Tick(float _DeltaTime)
{
	BlockStateUpdate(_DeltaTime);


}

void BrickBlock::BlockStateUpdate(float _DeltaTime)
{

	BlockMove(_DeltaTime);
	BlockBreak(_DeltaTime);
}

// 브레이크 애니메이션은 여기서 만들지 않고, 클래스를 따로 둬본다.
void BrickBlock::BlockStateChange(BrickBlockState _BlockState)
{

}

void BrickBlock::BlockMove(float _DeltaTime)
{
	// 다시는 충돌하지 않게 할려고 반환해주고, 블럭 충돌을 끝내는 조건문
	if (IsColEnd == true)
	{
		return;
	}

	// 빅마리오는 부수고, 스몰마리오는 계속 움직이게 한다.
	if (Time < 0.0f)
	{
		SetActorLocation(OriginPos);

		if (Mode == MarioMode::BigMario)
		{
			Destroy(0.0001f);
			//IsColEnd = true;
			//return;
		}

		if (Mode == MarioMode::SmallMario)
		{
			MarioCol = false;
			Time = 0.25f;
			return;
		}

	}

	if (true == MarioCol)
	{
		Time -= _DeltaTime;
		if (Time >= 0.125f)
		{
			AddActorLocation(FVector::Up * _DeltaTime * BlockMoveSpeed);
		}
		else
		{
			AddActorLocation(FVector::Down * _DeltaTime * BlockMoveSpeed);
		}
	}


}

// Big 마리오와 닿은 BrickBlock은 지워진다.
void BrickBlock::BlockBreak(float _DeltaTime)
{
	

	
}




