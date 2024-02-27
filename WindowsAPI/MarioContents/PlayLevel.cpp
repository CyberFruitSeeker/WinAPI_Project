#include "PlayLevel.h"
#include "Mario.h"
#include "MarioMap.h"
#include "Goomba.h"
#include "Troopa.h"
#include <EngineCore/EngineCore.h>

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::BeginPlay()
{
	ULevel::BeginPlay();

	// 카메라 범위 제한 1 : 맵 클래스에서 ImageScale을 이용할 것인가
	// 충돌 위험 때문에 우선 사용 안함
	//MarioMap* Map = SpawnActor<MarioMap>(MarioRenderOrder::Map);
	Map = SpawnActor<MarioMap>();
	Map->SetMapImage("MarioWorld01.png");
	Map->SetColMapImage("MarioWorld01_Col.png");
	Map->SwitchDebug();

	{
		Mario* NewActor = SpawnActor<Mario>(MarioRenderOrder::Player);
		NewActor->SetName("Mario");
		NewActor->SetActorLocation({ 200,300 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 650,300 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 500,300 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 2200,300 });
	}


	{
		Troopa* NewActor = SpawnActor<Troopa>(MarioRenderOrder::Monster);
		NewActor->SetName("Troopa");
		NewActor->SetActorLocation({ 900,300 });
	}

	{
		Troopa* NewActor = SpawnActor<Troopa>(MarioRenderOrder::Monster);
		NewActor->SetName("Troopa");
		NewActor->SetActorLocation({ 1600,300 });
	}




}


void PlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	//카메라 범위 제한 2 : 플레이 레벨 Tick에다 if문을 사용할 것인가
	// 충돌 위험 때문에 우선 주석처리

	//FVector CameraPos = GetCameraPos();

	//if (0.0f >= CameraPos.X)
	//{
	//	CameraPos.X = 0.0f;
	//}

	//if (0.0f >= CameraPos.Y)
	//{
	//	CameraPos.Y = 0.0f;
	//}


	//FVector ImageScale = Map->GetImageScale();

	// X축의 움직임을 기준으로 맵의 바깥으로 못나가게 할것인가
	//if (CameraPos.X >= ImageScale.X - GEngine->MainWindow.GetWindowScale().X)
	//{
	//	CameraPos.X = ImageScale.X - GEngine->MainWindow.GetWindowScale().X;
	//}

	//if (true == UEngineInput::IsDown(VK_ESCAPE))
	//{
	//	GEngine->MainWindow.Off();
	//}


	//SetCameraPos(CameraPos);

}


void PlayLevel::LevelStart(ULevel* _Level)
{
	// 리소스를 로드하고, 액터를 만드는 역할(우선 값을 넣어준다.)
	int a = 0;
}

void PlayLevel::LevelEnd(ULevel* _Level)
{
	// 리소스를 날리고, 액터를 삭제하는 역할(우선 값을넣어준다.)
	int a = 0;
}