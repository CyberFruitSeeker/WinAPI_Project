#pragma once
#include "BlockCommonClass.h"
#include <EngineCore/Collision.h>
#include "Mario.h"

// Ό³Έν :
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


	void BlockMove(float _DeltaTime);
	void BlockBreak(float _DeltaTime);





private:

};

