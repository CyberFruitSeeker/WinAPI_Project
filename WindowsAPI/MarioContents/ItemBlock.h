#pragma once
#include "BlockCommonClass.h"
#include <EngineCore/Collision.h>
#include "Mario.h"
#include <EnginePlatform/EngineSound.h>

// Ό³Έν :
class ItemBlock : public BlockCommonClass
{
public:
	// constrcuter destructer
	ItemBlock();
	~ItemBlock();

	// delete Function
	ItemBlock(const ItemBlock& _Other) = delete;
	ItemBlock(ItemBlock&& _Other) noexcept = delete;
	ItemBlock& operator=(const ItemBlock& _Other) = delete;
	ItemBlock& operator=(ItemBlock&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	UImageRenderer* Renderer = nullptr;
	UCollision* BlockCollision = nullptr;

	FVector BlockMoveVector = FVector::Zero;
	float BlockMoveSpeed = 300.0f;

	void BlockStateUpdate(float _DeltaTime);

	void BlockMove(float _DeltaTime);

	void ItemMoveUp(float _DeltaTime);

	UEngineSoundPlayer BlockMoveSound;



private:
	float Time = 0.25f;
};

