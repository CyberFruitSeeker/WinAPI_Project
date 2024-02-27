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

	// ī�޶� ���� ���� 1 : �� Ŭ�������� ImageScale�� �̿��� ���ΰ�
	// �浹 ���� ������ �켱 ��� ����
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

	//ī�޶� ���� ���� 2 : �÷��� ���� Tick���� if���� ����� ���ΰ�
	// �浹 ���� ������ �켱 �ּ�ó��

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

	// X���� �������� �������� ���� �ٱ����� �������� �Ұ��ΰ�
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
	// ���ҽ��� �ε��ϰ�, ���͸� ����� ����(�켱 ���� �־��ش�.)
	int a = 0;
}

void PlayLevel::LevelEnd(ULevel* _Level)
{
	// ���ҽ��� ������, ���͸� �����ϴ� ����(�켱 �����־��ش�.)
	int a = 0;
}