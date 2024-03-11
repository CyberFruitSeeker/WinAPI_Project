#include "CoinBlock.h"
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include "Mario.h"
#include "BlockCommonClass.h"

CoinBlock::CoinBlock()
{
}

CoinBlock::~CoinBlock()
{
}

void CoinBlock::BeginPlay()
{
	// 코인 블럭과 아이템 블럭은 동일한 이미지를 사용한다.
	{
		SetName("CoinBlock");
		Renderer = CreateImageRenderer(MarioRenderOrder::Block);
		Renderer->SetImage("ItemCoinBlock.png");
		Renderer->SetScale({ 500,500 });
	}

	{
		BlockCollision = CreateCollision(MarioCollisionOrder::Block);
		BlockCollision->SetTransform({ {0,0},{64,64} });
		BlockCollision->SetColType(ECollisionType::Rect);
	}
}

void CoinBlock::Tick(float _DeltaTime)
{
	BlockStateUpdate(_DeltaTime);
}

void CoinBlock::BlockStateUpdate(float _DeltaTime)
{
	BlockMove(_DeltaTime);
	MarioGetCoin(_DeltaTime);
}

void CoinBlock::BlockMove(float _DeltaTime)
{
	// 다시 충돌하지 않게 할려고 값을 반환해주고, 블럭 충돌을 끝내는 조건문
	if (IsColEnd == true)
	{
		return;
	}

	if (Time < 0.0f)
	{
		SetActorLocation(OriginPos);

		if (Mode == MarioMode::BigMario)
		{
			//Destroy(0.0001f);
			IsColEnd = true;
			return;
		}

		if (Mode == MarioMode::SmallMario)
		{
			IsColEnd = true;
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

void CoinBlock::MarioGetCoin(float _DeltaTime)
{

}
