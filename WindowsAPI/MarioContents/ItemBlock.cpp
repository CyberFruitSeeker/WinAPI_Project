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
	// ������ ���� ���� ���� ������ �̹����� ����Ѵ�.
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

		// �ٽô� �浹���� �ʰ� �Ϸ��°�.
		IsColEnd = true;
	}
}

void ItemBlock::BlockMove(float _DeltaTime)
{
}
