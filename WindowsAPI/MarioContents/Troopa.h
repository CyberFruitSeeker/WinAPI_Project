#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "Monster.h"
#include "Mario.h"

// 설명 :
class Troopa : public AMonsterSetting
{
public:
	
	// constrcuter destructer
	Troopa();
	~Troopa();

	// delete Function
	Troopa(const Troopa& _Other) = delete;
	Troopa(Troopa&& _Other) noexcept = delete;
	Troopa& operator=(const Troopa& _Other) = delete;
	Troopa& operator=(Troopa&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* Renderer = nullptr;
	UCollision* BodyCollision = nullptr;
	UCollision* UpCollision = nullptr;

	// 파이프에 닿으면 움직임의 좌우가 변경되니깐 그에 대한 함수도 필요
	FVector MoveVector = FVector::Left;
	// 하지만? : 트루파는 굼바와 달리 Left, Right가 있다.

	TroopaState State = TroopaState::None;
	EActorDir DirState = EActorDir::Left;

	FVector GravityAccel = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;
	
	float MoveSpeed = 150.0f;
	//float MaxMoveSpeed = 500.0f;



	std::string CurAnimationName = "None";

	/*float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;*/



	// 몬스터 애니메이션 : 트루파
	void StateChange(TroopaState _State);
	void StateUpdate(float _DeltaTime);

	void CalMove(float _DeltaTime);
	void CalGravity(float _DeltaTime);

	void MoveStart();
	void DeadStart();
	void DirChangeStart();

	void Move(float _DeltaTime);
	void Dead(float _DeltaTime);
	void DirChange(float _DeltaTime);

	void MarioJumpAttack() override;

	// 트루파에게 더 필요한 함수 == 기능이 무엇인가? : 우선 GetAnimation
	std::string GetAnimationName(std::string _Name);
	// 껍데기 상태가 되는 것에 필요한 것들 : FSM과 관련된 세세한 CollisionCheck 정도??

	// Dir을 체크하고, 전환하는 함수 및 기능들도 가져와야 한다.
	void DirCheck();








private:

	

	

	// 트루파의 상태가 어떠니?


};

