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
#include "BrickBlockBreaking.h"
#include "Flag.h"

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
		NewActor->SetActorLocation({ 12404.f,172.f });
		//NewActor->SetActorLocation({ 185.f,827.f });
	}

	// Ending Title로 이어지는 Flag의 소환 위치 : 12704.f, 485.f
	{
		Flag* NewActor = SpawnActor<Flag>(MarioRenderOrder::FlagEnum);
		NewActor->SetName("Flag");
		NewActor->SetActorLocation({ 12704,485 });
	}


	// 실험용 굼바 다크
	//{
	//	GoombaDark* NewActor = SpawnActor<GoombaDark>(MarioRenderOrder::Monster);
	//	NewActor->SetName("GoombaDark");
	//	NewActor->SetActorLocation({ 400,550 });
	//}

	// 블럭 브레이킹
	// 하지만, 스폰액터로 나오게 하지는 않는다.
	//{
	//	BrickBlockBreaking* NewActor = SpawnActor<BrickBlockBreaking>(MarioRenderOrder::BreakingBlock);
	//	NewActor->SetName("BrickBlockBreaking");
	//	NewActor->SetActorLocation({ 612,600 });
	//}

	//{
	//	BrickBlockBreaking* NewActor = SpawnActor<BrickBlockBreaking>(MarioRenderOrder::BreakingBlock);
	//	NewActor->SetActorLocation({ 450,550 });

	//}

	// 블럭
	// 붙어있는 블럭끼리의 추천 간격 : x축 62, y축 
	// x축이 62 간격으로 있으면 너무 빽빽해서 그런지 문제가 살짝 있음
	// 
	// 벽돌 블럭
	{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 1286,550 });
	}

	{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 1162,550 });
	}


	{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 800,550 });
	}

	//{
	//	BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
	//	NewActor->SetName("BrickBlock");
	//	NewActor->SetActorLocation({ 862,550 });
	//}

	{
		BrickBlock* NewActor = SpawnActor<BrickBlock>(MarioRenderOrder::Block);
		NewActor->SetName("BrickBlock");
		NewActor->SetActorLocation({ 1100,550 });
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

	// 아이템 블럭
	{
		ItemBlock* NewActor = SpawnActor<ItemBlock>(MarioRenderOrder::Block);
		NewActor->SetName("ItemBlock");
		NewActor->SetActorLocation({ 550,600 });
	}

	{
		ItemBlock* NewActor = SpawnActor<ItemBlock>(MarioRenderOrder::Block);
		NewActor->SetName("ItemBlock");
		NewActor->SetActorLocation({ 862,550 });
	}

	{
		ItemBlock* NewActor = SpawnActor<ItemBlock>(MarioRenderOrder::Block);
		NewActor->SetName("ItemBlock");
		NewActor->SetActorLocation({ 1224,550 });
	}

	// 코인 블럭
	{
		CoinBlock* NewActor = SpawnActor<CoinBlock>(MarioRenderOrder::Block);
		NewActor->SetName("CoinBlock");
		NewActor->SetActorLocation({ 674,600 });
	}

	{
		CoinBlock* NewActor = SpawnActor<CoinBlock>(MarioRenderOrder::Block);
		NewActor->SetName("CoinBlock");
		NewActor->SetActorLocation({ 924,550 });
	}

	{
		CoinBlock* NewActor = SpawnActor<CoinBlock>(MarioRenderOrder::Block);
		NewActor->SetName("CoinBlock");
		NewActor->SetActorLocation({ 1349,550 });
	}

	// ==================== 블럭 ====================



	//// 머쉬룸
	//{
	//	Mushroom* NewActor = SpawnActor<Mushroom>(MarioRenderOrder::Item);
	//	NewActor->SetName("Mushroom");
	//	NewActor->SetActorLocation({ 600,350 });
	//}




	// 굼바
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


	// 트루파
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