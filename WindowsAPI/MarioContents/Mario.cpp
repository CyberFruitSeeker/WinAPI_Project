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

	// 충돌(Collision)이라는 시점을 따로둔다.
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



void Mario::AddMoveVector(const FVector& _DirDelta)
{

}

void Mario::SetState(PlayerState _State)
{

}


void Mario::StateUpdate(float _DeltaTime)
{

}



void Mario::CalMoveVector(float _DeltaTime)
{
	
}

void Mario::CalJumpVector(float _DeltaTime)
{

}

void Mario::CalGravityVector(float _DeltaTime)
{

}


void Mario::CalLastMoveVector(float _DeltaTime)
{

}


void Mario::MoveUpdate(float _DeltaTime)
{
	// 이동을 하다가 마리오가 땅이나 오브젝트에 처박힐 수 있는 것을 방지하기 위한 것
	CalMoveVector(_DeltaTime);
	CalGravityVector(_DeltaTime);
	CalLastMoveVector(_DeltaTime);
	MoveLastCamera();
}

/// ============== 이동에서 중력, 가속도 관련 기능 ==============


/// ========= 마리오 이미지 셋, 애니메이션, 스테이트 =========




void Mario::DirCheck()
{
	
}



// ====== 카메라 ======

void Mario::MoveLastCamera()
{
	// 카메라는 x축으로만 움직이게 해본다.

	// 
	// 맵에서 원점(0, 0) 이하(마이너스)로 못나가게 하는 코드가
	// Map 클래스 혹은 PlayLevel에 구현되어있지만 주석처리
}


//void Mario::MoveLastCameraVector(float _DeltaTime)
//{
//	// 카메라는 x축으로만 움직이게 해본다.
//	GetWorld()->AddCameraPos(MoveVector * _DeltaTime);
//	AddActorLocation(LastMoveVector * _DeltaTime);
//	// 맵에서 원점(0, 0) 이하(마이너스)로 못나가게 하는 코드가
//	// Map 클래스 혹은 PlayLevel에 구현되어있다.
//}





// ===== 카메라? ======


// ====== 키 입력으로 인한 마리오의 움직임 =======


void Mario::IdleStart()
{

}

void Mario::RunStart()
{

}

void Mario::JumpStart()
{

}


