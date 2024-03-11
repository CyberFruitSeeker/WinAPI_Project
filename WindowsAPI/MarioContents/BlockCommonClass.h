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


	void BlockColOn()
	{
		MarioCol = true;
	}



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UCollision* BlockCollision = nullptr;


	// 마리오가 어떤 상태일때도 블록에서 공통적인 요소 : 박스가 위로 올라가서 다시 돌아온다.
	// (아이템 박스도 마찬가지이다.)
	// 박스가 올라가는 애니메이션만 있으면 되는데 FVector가 필요한가??
	//FVector BlockMoveVector = FVector::None;



	// 마리오가 블럭을 들이받았다는 것에 상호작용을 할 수 있는 함수
	void MarioBlockCol(float _DeltaTime);


	bool MarioCol = false;
	bool IsColEnd = false;

private:

};

