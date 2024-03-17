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


	void BlockColOn(MarioMode _Mode)
	{
		// ���� �����̴��߿� �������� ��� �ļ� ��ġ�� ��߳��� �ϴ� ���� �����ϱ� ���� ���ǹ�
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



	// �������� � �����϶��� ��Ͽ��� �������� ��� : �ڽ��� ���� �ö󰡼� �ٽ� ���ƿ´�.
	// (������ �ڽ��� ���������̴�.)



	// �������� ���� ���̹޾Ҵٴ� �Ϳ� ��ȣ�ۿ��� �� �� �ִ� �Լ�
	void MarioBlockCol(float _DeltaTime);

	// ���� ������, �� �������� ���� �ݸ��� ������
	MarioMode Mode = MarioMode::BigMario;
	bool MarioCol = false;
	bool IsColEnd = false;

	// �ڽ��� ���� ��ġ�� ���ư��� ���ִ� ���
	FVector OriginPos;

private:

};

