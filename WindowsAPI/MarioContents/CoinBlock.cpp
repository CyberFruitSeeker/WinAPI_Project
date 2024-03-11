#include "CoinBlock.h"
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include "Mario.h"

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
	if (true == PlayerCol)
	{
		int a = 0;
	}
}

void CoinBlock::BlockMove(float _DeltaTime)
{

}
