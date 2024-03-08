#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "Mario.h"

// 설명 :
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

	// 박스가 올라가는 애니메이션만 있으면 되는데 FVector가 필요한가??
	//FVector BlockMoveVector = FVector::Up;



	// 마리오가 블럭을 들이받았다는 것에 상호작용을 할 수 있는 함수
	void MarioBlockCol(float _DeltaTime);




private:

};

