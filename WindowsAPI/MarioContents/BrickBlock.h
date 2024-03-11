#pragma once
#include "BlockCommonClass.h"
#include <EngineCore/Collision.h>
#include "Mario.h"

// ���� :
class BrickBlock : public BlockCommonClass
{
public:
	// constrcuter destructer
	BrickBlock();
	~BrickBlock();

	// delete Function
	BrickBlock(const BrickBlock& _Other) = delete;
	BrickBlock(BrickBlock&& _Other) noexcept = delete;
	BrickBlock& operator=(const BrickBlock& _Other) = delete;
	BrickBlock& operator=(BrickBlock&& _Other) noexcept = delete;




protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* Renderer = nullptr;
	UCollision* BlockCollision = nullptr;


	//FVector BlockMoveVector = FVector::Up;
	float BlockMoveSpeed = 300.0f;

	


	// ���� ���� �ν����ϱ�, ���� Ŭ������ �߿��� �� Ŭ�������� �Լ��� BlockBreak �̴�.
	void BlockStateUpdate(float _DeltaTime);

	void BlockStateChange(BrickBlockState _BlockState);

	void BlockMove(float _DeltaTime);
	void BlockBreak(float _DeltaTime);

	




private:
	float Time = 0.25f;
};

