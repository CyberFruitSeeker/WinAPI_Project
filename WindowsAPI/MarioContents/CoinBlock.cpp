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
	// ���� ���� ������ ���� ������ �̹����� ����Ѵ�.
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

void CoinBlock::MarioGetCoin(float _DeltaTime)
{

}
