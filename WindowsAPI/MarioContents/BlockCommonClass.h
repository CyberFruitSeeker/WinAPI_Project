#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "Mario.h"

// ���� :
class BlockCommonClass : public AActor
{
public:
	// constrcuter destructer
	BlockCommonClass();
	~BlockCommonClass();

	// delete Function
	BlockCommonClass(const BlockCommonClass& _Other) = delete;
	BlockCommonClass(BlockCommonClass&& _Other) noexcept = delete;
	BlockCommonClass& operator=(const BlockCommonClass& _Other) = delete;
	BlockCommonClass& operator=(BlockCommonClass&& _Other) noexcept = delete;


	void BlockColOn()
	{
		MarioCol = true;
	}



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UCollision* BlockCollision = nullptr;


	// �������� � �����϶��� ��Ͽ��� �������� ��� : �ڽ��� ���� �ö󰡼� �ٽ� ���ƿ´�.
	// (������ �ڽ��� ���������̴�.)
	// �ڽ��� �ö󰡴� �ִϸ��̼Ǹ� ������ �Ǵµ� FVector�� �ʿ��Ѱ�??
	//FVector BlockMoveVector = FVector::None;



	// �������� ���� ���̹޾Ҵٴ� �Ϳ� ��ȣ�ۿ��� �� �� �ִ� �Լ�
	void MarioBlockCol(float _DeltaTime);


	bool MarioCol = false;
	bool IsColEnd = false;

private:

};

