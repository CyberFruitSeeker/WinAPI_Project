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


	void BlockColOn(MarioMode _Mode)
	{
		// 블럭이 움직이는중에 마리오가 계속 쳐서 위치가 어긋나게 하는 것을 방지하기 위한 조건문
		if (true == MarioCol)
		{
			return;
		}

		OriginPos = GetActorLocation();
		Mode = _Mode;
		MarioCol = true;
	}

	
	UCollision* BlockCollision = nullptr;
	UCollision* BlockUpCollision = nullptr;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



	// 마리오가 어떤 상태일때도 블록에서 공통적인 요소 : 박스가 위로 올라가서 다시 돌아온다.
	// (아이템 박스도 마찬가지이다.)



	// 마리오가 블럭을 들이받았다는 것에 상호작용을 할 수 있는 함수
	void MarioBlockCol(float _DeltaTime);

	// 스몰 마리오, 빅 마리오에 따른 콜리전 나누기
	MarioMode Mode = MarioMode::BigMario;
	bool MarioCol = false;
	bool IsColEnd = false;

	// 박스의 원래 위치로 돌아가게 해주는 기능
	FVector OriginPos;

private:

};

