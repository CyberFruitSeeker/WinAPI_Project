#include "Mario.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include <EngineCore/Collision.h>
#include <string>
#include <vector>
#include <list>
#include "Physics.h"
#include "ContentsHelper.h"

FVector Mario::MarioLocation = {};

Mario::Mario()
{
}

Mario::~Mario()
{
}

void Mario::BeginPlay()
{
	AActor::BeginPlay();
	//ItsMeMario = this;
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::Player);
		SetName("Mario");
		Renderer->SetImage("Player_Right.png");
		Renderer->SetTransform({ {0,0}, {256, 256} });

		//Renderer->CreateAnimation("Idle_Right", "Player_Right.png", 0, 0, 0.45f, true);
		//Renderer->CreateAnimation("Idle_Left", "Player_Left.png", 0, 0, 0.45f, true);

		//Renderer->CreateAnimation("Run_Right", "Player_Right.png", { 1, 2, 3 }, 0.1f, true);
		//Renderer->CreateAnimation("Run_Left", "Player_Left.png", { 1, 2, 3 }, 0.1f, true);

		//Renderer->CreateAnimation("Jump_Right", "Player_Right.png", 5, 5, 0.1f, true);
		//Renderer->CreateAnimation("Jump_Left", "Player_Left.png", 5, 5, 0.1f, true);

		//Renderer->ChangeAnimation("Idle_Right");
	}

	// �浹(Collision)�̶�� ������ ���εд�.
	{
		//BodyCollision = CreateCollision(MarioCollisionOrder::Player);
		//BodyCollision->SetScale({ 10, 100 });
		//BodyCollision->SetColType(ECollisionType::CirCle);
	}


	//SetState(PlayerState::Idle);
}


void Mario::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);


}

// ====== �������� �����ӿ� ���� ī�޶� �̵� ======

void Mario::MoveLastCamera()
{
	// ī�޶�� x�����θ� �����̰� �غ���.

}
 // =============================================


void Mario::SetState(PlayerState _State)
{

}


void Mario::StateUpdate(float _DeltaTime)
{

}

void Mario::IncreaseSpeed(float _DeltaTime, FVector _Fvector)
{
}

void Mario::DecreaseSpeed(float _DeltaTime, FVector _Fvector)
{
}





/// ============== �̵����� �߷�, ���ӵ� ���� ��� ==============


/// ========= ������ �̹��� ��, �ִϸ��̼�, ������Ʈ =========




void Mario::DirCheck()
{
	
}

void Mario::MarioColEffect(float _DeltaTime)
{
}

void Mario::MoveResult(float _DeltaTime)
{
}

void Mario::SetAnimation(std::string _Name)
{
}



//void Mario::MoveLastCameraVector(float _DeltaTime)
//{
//	// ī�޶�� x�����θ� �����̰� �غ���.
//	GetWorld()->AddCameraPos(MoveVector * _DeltaTime);
//	AddActorLocation(LastMoveVector * _DeltaTime);
//	// �ʿ��� ����(0, 0) ����(���̳ʽ�)�� �������� �ϴ� �ڵ尡
//	// Map Ŭ���� Ȥ�� PlayLevel�� �����Ǿ��ִ�.
//}





void Mario::Idle(float _DeltaTime)
{
}

void Mario::Jump(float _DeltaTime)
{
}

void Mario::Run(float _DeltaTime)
{
}

void Mario::IdleStart()
{

}

void Mario::RunStart()
{

}

void Mario::JumpStart()
{

}

void Mario::DieStart()
{
}

void Mario::Die(float _DeltaTime)
{
}

void Mario::Interactive(float _DeltaTime)
{
}

void Mario::MoveFun(float _DeltaTime, FVector Accel)
{
}


