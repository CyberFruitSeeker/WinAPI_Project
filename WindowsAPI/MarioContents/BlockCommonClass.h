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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UCollision* BlockCollision = nullptr;

	// �ڽ��� �ö󰡴� �ִϸ��̼Ǹ� ������ �Ǵµ� FVector�� �ʿ��Ѱ�??
	//FVector BlockMoveVector = FVector::Up;



	// �������� ���� ���̹޾Ҵٴ� �Ϳ� ��ȣ�ۿ��� �� �� �ִ� �Լ�
	void MarioBlockCol(float _DeltaTime);




private:

};

