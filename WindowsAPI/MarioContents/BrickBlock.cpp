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

void BrickBlock::BlockMove(float _DeltaTime)
{
	// 블럭이 위로 갔다가, 다시 아래로 가서 돌아오게 하는 조건문
	
	if (IsColEnd == true)
	{
		return;
	}

	if (Time < 0.0f)
	{
		IsColEnd = true;
		return;
	}

	if (true == MarioCol)
	{
		Time -= _DeltaTime;
		if (Time >= 0.2f)
		{
			AddActorLocation(FVector::Up * _DeltaTime * BlockMoveSpeed);
		}
		else
		{
			AddActorLocation(FVector::Down * _DeltaTime * BlockMoveSpeed);
		}
	}


}

void BrickBlock::BlockBreak(float _DeltaTime)
{



}




