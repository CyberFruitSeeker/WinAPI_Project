#include "ItemBlock.h"
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include "Mario.h"
#include "BlockCommonClass.h"

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
	BlockStateUpdate(_DeltaTime);


}

void ItemBlock::BlockStateUpdate(float _DeltaTime)
{
	BlockMove(_DeltaTime);
	ItemMoveUp(_DeltaTime);

}

void ItemBlock::BlockMove(float _DeltaTime)
{
	// �ٽ� �浹���� �ʰ� �ҷ��� ���� ��ȯ���ְ�, �� �浹�� ������ ���ǹ�
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

// �����̳� ���� ������ ���´�.
void ItemBlock::ItemMoveUp(float _DeltaTime)
{

}
