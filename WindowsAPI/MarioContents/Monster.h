#pragma once
#include <EngineCore/Actor.h>

// ���� :
class AMonsterSetting : public AActor
{
public:
	// constrcuter destructer
	AMonsterSetting();
	~AMonsterSetting();

	// delete Function
	AMonsterSetting(const AMonsterSetting& _Other) = delete;
	AMonsterSetting(AMonsterSetting&& _Other) noexcept = delete;
	AMonsterSetting& operator=(const AMonsterSetting& _Other) = delete;
	AMonsterSetting& operator=(AMonsterSetting&& _Other) noexcept = delete;

	// �������� ���͸� ��Ҵ� == ���������� �ߴ�.
	virtual void MarioJumpAttack() 
	{

	}

protected:
	// ���ٿ� Ʈ���Ŀ��� ���������� �ʿ��� ���� �����ΰ�?
	//(�׷���Ƽ ����, ���� ���� ����...)




private:

};

