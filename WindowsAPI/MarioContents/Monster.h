#pragma once
#include <EngineCore/Actor.h>

// 설명 :
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

	// 마리오가 몬스터를 밟았다 == 점프어택을 했다.
	virtual void MarioJumpAttack() 
	{

	}

protected:

private:

};

