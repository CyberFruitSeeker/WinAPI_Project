#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>
#include <EnginePlatform/EngineSound.h>

// ���� :
class Mario : public AActor
{
public:
	static Mario* GetItsMeMario();
	static Mario* ItsMeMario;

	// constrcuter destructer
	Mario();
	~Mario();

	// delete Function
	Mario(const Mario& _Other) = delete;
	Mario(Mario&& _Other) noexcept = delete;
	Mario& operator=(const Mario& _Other) = delete;
	Mario& operator=(Mario&& _Other) noexcept = delete;

	// �������� small, big, fire(flower)���
	// Mushroom Ŭ�������� �˱� ���ؼ� public���� �ص� ����
	void MarioModeChange(MarioMode _MarioMode);


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	// �������� Flag�� ��ȣ�ۿ��ϴ� �Լ���
	void MarioFlagInteractive(float _DeltaTime);
	void MarioFlagCollision(float _DeltaTime);
	void MarioFlagAnimation(float _DeltaTime);


	void DirCheck();


	void StateChange(MarioState _State);
	void StateUpdate(float _DeltaTime);


	void CameraFreeMove(float _DeltaTime);
	void FreeMove(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);
	//void JumpDown(float _DeltaTime);
	void Run(float _DeltaTime);
	void FlagStop(float _DeltaTime);
	void FlagAutoMove(float _DeltaTime);

	// ���� ������ ����� ��� �Լ����̴�.
	void IdleStart();
	void RunStart();
	void JumpStart();
	void FlagStopStart();
	void FlagAutoMoveStart();

	FVector MarioFlagStopVector = FVector::Zero;
	FVector MarioFlagDown = FVector::Down;

	float MarioFlagDownSpeed = 300.0f;
	float AutoMoveSpeed = 1.0f;

	std::string GetAnimationName(std::string _Name);

	MarioState State = MarioState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";


	// ������ �Ѵ��� �������� �ִٴ� ���� �߷°� �������� ���ÿ� �ۿ��ϰ��ִ� �����̴�.
	bool IsJumpDown()
	{
		FVector JPos = (GravityVector + JumpVector);
		return 0 < JPos.Y;
	}


	// ������ ���
	MarioMode Mode = MarioMode::SmallMario;
	
	void SmallMario();
	void BigMario();
	void FireMario();


	// ���� ���� ��ɵ��� �켱 ���⿡
	UEngineSoundPlayer BGMPlay;

	float BGMVolume = 1.0f;
	float JumpAttackSound = 1.0f;
	float FlagDownSound = 1.0f;
	float StageClearMusic = 1.0f;
	float TroopaShellMoveSound = 1.0f;
	float BlockBreakingSound = 1.0f;





private:
	
	float ChangeLevelTime = 6.0f;
	
	UCollision* BodyCollision = nullptr;
	UCollision* DownCollision = nullptr;
	UImageRenderer* Renderer = nullptr;

	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

	// ������ �⺻ �ӵ� & ���ӵ�
	float FreeMoveSpeed = 700.0f;
	float MoveMaxSpeed = 600.0f;
	FVector MoveVector = FVector::Zero;
	FVector MoveAccel = FVector::Right * 450.0f;
	void AddMoveVector(const FVector& _DeltaTime);

	// ���������� ����Ǵ� �߷� ���ӵ�, �߷� �ʱ�ȭ
	FVector GravityAccel = FVector::Down * 1523.0f;
	FVector GravityVector = FVector::Zero;

	// ����, ���ư� ��� ������ ���� �հ� �ʱ�ȭ
	FVector JumpPower = FVector::Up * 932.0f;
	FVector JumpVector = FVector::Zero;
	FVector LastMoveVector = FVector::Zero;


	// �̵� ���� �߷� ����
	void CalLastMoveVector(float _DeltaTime);
	void CalMoveVector(float _DeltaTime);
	//void CalJumpVector(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);

	// ī�޶� ���� ������
	void MarioVectorMoveCameraPos(float _DeltaTime);
	void MoveCameraMarioPos(float _DeltaTime);

	void MoveUpdate(float _DeltaTime);


	// � ����� �� �߰��� ���ΰ�?
	// moveresult?  
	
	//MarioMap* Map;

	// �������� �������� ���� ������ ���� �����ϱ� ���� �¿�Ʒ��� �ִ� ������ �ø���





};
