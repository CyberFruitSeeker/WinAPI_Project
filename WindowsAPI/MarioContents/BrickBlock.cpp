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


	// block �ݸ���
	{
		BlockCollision = CreateCollision(MarioCollisionOrder::Block);
		BlockCollision->SetTransform({ {0,0},{64,64} });
		BlockCollision->SetColType(ECollisionType::Rect);
	}

	// Brick Block���� �ִ� Brick Block Break �ִϸ��̼�
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

// �극��ũ �ִϸ��̼��� ���⼭ ������ �ʰ�, Ŭ������ ���� �ֺ���.
void BrickBlock::BlockStateChange(BrickBlockState _BlockState)
{

}

void BrickBlock::BlockMove(float _DeltaTime)
{
	// �ٽô� �浹���� �ʰ� �ҷ��� ��ȯ���ְ�, �� �浹�� ������ ���ǹ�
	if (IsColEnd == true)
	{
		return;
	}

	// �򸶸����� �μ���, ������������ ��� �����̰� �Ѵ�.
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

// Big �������� ���� BrickBlock�� ��������.
void BrickBlock::BlockBreak(float _DeltaTime)
{
	

	
}




