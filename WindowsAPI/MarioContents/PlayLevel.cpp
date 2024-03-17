#include <EngineCore/EngineCore.h>
#include <EngineBase/EngineFile.h>
#include <EngineBase/EngineSerializer.h>
#include <EnginePlatform/EngineSound.h>
#include "PlayLevel.h"
#include "Mario.h"
#include "MarioMap.h"
#include "Goomba.h"
#include "Troopa.h"
#include "Mushroom.h"
#include "BrickBlock.h"
#include "ItemBlock.h"
#include "CoinBlock.h"
#include "BrickBlockBreaking.h"
#include "Flag.h"
#include "MarioUI.h" 
#include <EngineCore/Collision.h>

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::BeginPlay()
{
	//ULevel::BeginPlay();

	// BGM
	BGMPlayer = UEngineSound::SoundPlay("Level1.mp3");
	BGMPlayer.Loop();

	// UI
	MarioUI* UI = SpawnActor<MarioUI>(MarioRenderOrder::UI);
	UI = SpawnActor<MarioUI>();
	//UI->SetUIBar("UIBar.png");
	//UI->SetMarioScroeUI("0.png");
	//UI->SetMarioScroeUI("1.png");
	//UI->SetMarioScroeUI("2.png");
	//UI->SetMarioScroeUI("3.png");
	//UI->SetMarioScroeUI("4.png");
	//UI->SetMarioScroeUI("5.png");
	//UI->SetMarioScroeUI("6.png");
	//UI->SetMarioScroeUI("7.png");
	//UI->SetMarioScroeUI("8.png");
	//UI->SetMarioScroeUI("9.png");
	//UI->SetCoinScoreUI("0.png");
	//UI->SetCoinUI("Coin_UI.png");
	//UI->SetMarioTimeUI("1.png");



	MarioMap* Map = SpawnActor<MarioMap>(MarioRenderOrder::Map);
	Map = SpawnActor<MarioMap>();
	Map->SetMapImage("MarioWorld01.png");
	Map->SetColMapImage("MarioWorld01_Col.png");
	Map->SwitchDebug();

	{
		Mario* NewActor = SpawnActor<Mario>(MarioRenderOrder::Player);
		NewActor->SetName("Mario");
		//NewActor->SetActorLocation({ 12404.f,172.f });
		NewActor->SetActorLocation({ 185.f,827.f });
		//NewActor->SetActorLocation({ 13090.f,827.f });
	}

	// �ӽ���
	/*{
		Mushroom* NewActor = SpawnActor<Mushroom>(MarioRenderOrder::Item);
		NewActor->SetName("Mushroom");
		NewActor->SetActorLocation({ 12350,560 });
	}*/

	// Ending Title�� �̾����� Flag�� ��ȯ ��ġ : 12704.f, 485.f
	{
		Flag* NewActor = SpawnActor<Flag>(MarioRenderOrder::FlagEnum);
		NewActor->SetName("Flag");
		NewActor->SetActorLocation({ 12704,485 });
	}

	// �� �극��ŷ
	// ������, �������ͷ� ������ ������ �ʴ´�.
	//{
	//	BrickBlockBreaking* NewActor = SpawnActor<BrickBlockBreaking>(MarioRenderOrder::BreakingBlock);
	//	NewActor->SetName("BrickBlockBreaking");
	//	NewActor->SetActorLocation({ 612,600 });
	//}

	//{
	//	BrickBlockBreaking* NewActor = SpawnActor<BrickBlockBreaking>(MarioRenderOrder::BreakingBlock);
	//	NewActor->SetActorLocation({ 450,550 });

	//}

	// ��
	// �ٷ� ������ �پ��ִ� �������� ��õ ���� : x�� 62
	// 
	// ���� ��
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

	// ������ ��
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

	// ���� ��
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

	// ==================== �� ====================



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

void PlayLevel::BGMSoundControl()
{

	//std::vector<UCollision*> FlagCollision;
	//if (true == FlagColCheck->CollisionCheck(MarioCollisionOrder::FlagUp, FlagCollision))
	//{
	//	
	//	BGMPlayer.Off();
	//}
}
