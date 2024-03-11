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


	void BlockMove(float _DeltaTime);





private:

};

