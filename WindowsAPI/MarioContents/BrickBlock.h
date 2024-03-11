#pragma once
#include "BlockCommonClass.h"
#include <EngineCore/Collision.h>
#include "Mario.h"

// 설명 :
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

	


	// 벽돌 블럭은 부숴지니깐, 블럭들 클래스들 중에서 이 클래스만의 함수는 BlockBreak 이다.
	void BlockStateUpdate(float _DeltaTime);

	void BlockStateChange(BrickBlockState _BlockState);

	void BlockMove(float _DeltaTime);
	void BlockBreak(float _DeltaTime);

	




private:
	float Time = 0.25f;
};

