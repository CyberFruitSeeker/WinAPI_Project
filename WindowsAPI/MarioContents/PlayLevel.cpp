#include "PlayLevel.h"
#include "Mario.h"
#include "MarioMap.h"
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

	// ī�޶� ���� ���� 1 : ���� ���� ImageScale�� �̿��� ���ΰ�
	//MarioMap* Map = SpawnActor<MarioMap>(MarioRenderOrder::Map);
	Map = SpawnActor<MarioMap>();
	Map->SetMapImage("MarioWorld01.png");
	Map->SetColMapImage("MarioWorld01_Col.png");
	Map->SwitchDebug();

	{
		Mario* NewActor = SpawnActor<Mario>(MarioRenderOrder::Player);
		NewActor->SetName("Player");
		NewActor->SetActorLocation({ 200,832 });
	}

}


void PlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	//ī�޶� ���� ���� 2 : �÷��� ���� Tick���� if���� ����� ���ΰ�

	FVector CameraPos = GetCameraPos();

	if (0.0f >= CameraPos.X)
	{
		CameraPos.X = 0.0f;
	}

	if (0.0f >= CameraPos.Y)
	{
		CameraPos.Y = 0.0f;
	}


	FVector ImageScale = Map->GetImageScale();

	// ���� �ٱ����� �������� �Ұ��ΰ�
	if (CameraPos.X >= ImageScale.X - GEngine->MainWindow.GetWindowScale().X)
	{
		CameraPos.X = ImageScale.X - GEngine->MainWindow.GetWindowScale().X;
	}

	if (true == UEngineInput::IsDown(VK_ESCAPE))
	{
		GEngine->MainWindow.Off();
	}


	SetCameraPos(CameraPos);

}

void PlayLevel::LevelStart(ULevel* _Level)
{
	// ���ҽ��� �ε��ϰ�, ���͸� ����� ���� �켱 �־��ش�.
	int a = 0;
}

void PlayLevel::LevelEnd(ULevel* _Level)
{
	// ���ҽ��� ������, ���͸� �����ϴ� ���� �켱 �־��ش�.
	int a = 0;
}