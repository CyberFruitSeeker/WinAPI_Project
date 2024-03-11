#include "ItemBlock.h"
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include "Mario.h"

ItemBlock::ItemBlock()
{
}

ItemBlock::~ItemBlock()
{
}

void ItemBlock::BeginPlay()
{
	// 아이템 블럭과 코인 블럭은 동일한 이미지를 사용한다.
	{
		SetName("ItemBlock");
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

void ItemBlock::Tick(float _DeltaTime)
{
	if (IsColEnd == true)
	{
		return;
	}

	if (true == PlayerCol)
	{
		int a = 0;

		// 다시는 충돌하지 않게 하려는것.
		IsColEnd = true;
	}
}

void ItemBlock::BlockMove(float _DeltaTime)
{
}
