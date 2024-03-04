#pragma once
#include <EngineCore/Actor.h>

// 설명 :
class AMonster : public AActor
{
public:
	// constrcuter destructer
	AMonster();
	~AMonster();

	// delete Function
	AMonster(const AMonster& _Other) = delete;
	AMonster(AMonster&& _Other) noexcept = delete;
	AMonster& operator=(const AMonster& _Other) = delete;
	AMonster& operator=(AMonster&& _Other) noexcept = delete;

	// 마리오가 몬스터를 밟았다.
	virtual void MarioJumpAttack() 
	{

	}

protected:

private:

};

