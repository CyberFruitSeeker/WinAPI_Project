#pragma once
#include "BlockCommonClass.h"
#include <EngineCore/Collision.h>
#include "Mario.h"

// Ό³Έν :
class CoinBlock : public BlockCommonClass
{
public:
	// constrcuter destructer
	CoinBlock();
	~CoinBlock();

	// delete Function
	CoinBlock(const CoinBlock& _Other) = delete;
	CoinBlock(CoinBlock&& _Other) noexcept = delete;
	CoinBlock& operator=(const CoinBlock& _Other) = delete;
	CoinBlock& operator=(CoinBlock&& _Other) noexcept = delete;




protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	UImageRenderer* Renderer = nullptr;
	UCollision* BlockCollision = nullptr;

	float BlockMoveSpeed = 300.0f;

	void BlockStateUpdate(float _DeltaTime);

	void BlockMove(float _DeltaTime);

	void MarioGetCoin(float _DeltaTime);




private:
	float Time = 0.25f;
};

