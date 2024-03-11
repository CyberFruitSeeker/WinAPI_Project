#include <EngineCore/EngineCore.h>
#include "PlayLevel.h"
#include "Mario.h"
#include "MarioMap.h"
#include "Goomba.h"
#include "GoombaDark.h"
#include "Troopa.h"
#include "Mushroom.h"
#include "BrickBlock.h"
#include "ItemBlock.h"
#include "CoinBlock.h"

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
		//NewActor->SetName("Mario");
		NewActor->SetActorLocation({ 200,550 });
	}

	// ����� ���� ��ũ
	//{
	//	GoombaDark* NewActor = SpawnActor<GoombaDark>(MarioRenderOrder::Monster);
	//	NewActor->SetName("GoombaDark");
	//	NewActor->SetActorLocation({ 400,550 });
	//}


	// ��
	// ���� ��
	{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 1300,550 });
	}

	{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 800,550 });
	}

	{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 862,550 });
	}

	{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 1050,550 });
	}

	{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 612,600 });
	}

	{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 488,600 });
	}

	/*{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 950,650 });
	}*/

	// ������ ��
	{
		ItemBlock* NewActor = SpawnActor<ItemBlock>(MarioRenderOrder::Block);
		NewActor->SetName("ItemBlock");
		NewActor->SetActorLocation({ 550,600 });
	}

	// ���� ��
	{
		CoinBlock* NewActor = SpawnActor<CoinBlock>(MarioRenderOrder::Block);
		NewActor->SetName("CoinBlock");
		NewActor->SetActorLocation({ 674,600 });
	}


	
	// �ӽ���
	{
		Mushroom* NewActor = SpawnActor<Mushroom>(MarioRenderOrder::Item);
		NewActor->SetName("Mushroom");
		NewActor->SetActorLocation({ 600,350 });
	}




	// ����
	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 2650,500 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 2800,500 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 2650,500 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 2850,500 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 3000,500 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 2000,500 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 2500,500 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 3450,500 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 3500,500 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 3550,500 });
	}

	{
		Goomba* NewActor = SpawnActor<Goomba>(MarioRenderOrder::Monster);
		NewActor->SetName("Goomba");
		NewActor->SetActorLocation({ 3350,500 });
	}


	// Ʈ����
	{
		Troopa* NewActor = SpawnActor<Troopa>(MarioRenderOrder::Monster);
		//NewActor->SetName("Troopa");
		NewActor->SetActorLocation({ 500,500 });
	}

	{
		Troopa* NewActor = SpawnActor<Troopa>(MarioRenderOrder::Monster);
		NewActor->SetName("Troopa");
		NewActor->SetActorLocation({ 2200,500 });
	}
	
	{
		Troopa* NewActor = SpawnActor<Troopa>(MarioRenderOrder::Monster);
		NewActor->SetName("Troopa");
		NewActor->SetActorLocation({ 2850,500 });
	}
	
	{
		Troopa* NewActor = SpawnActor<Troopa>(MarioRenderOrder::Monster);
		NewActor->SetName("Troopa");
		NewActor->SetActorLocation({ 2700,500 });
	}
	
	{
		Troopa* NewActor = SpawnActor<Troopa>(MarioRenderOrder::Monster);
		NewActor->SetName("Troopa");
		NewActor->SetActorLocation({ 3300,500 });
	}
	
	{
		Troopa* NewActor = SpawnActor<Troopa>(MarioRenderOrder::Monster);
		NewActor->SetName("Troopa");
		NewActor->SetActorLocation({ 3400,500 });
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