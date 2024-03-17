#include "MarioUI.h"
#include "MarioMap.h"
#include "ContentsHelper.h"
#include "CoinBlock.h"
#include "Mario.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineCore/EngineCore.h>
#include <EngineBase/EnginePath.h>

MarioUI::MarioUI()
{
}

MarioUI::~MarioUI()
{
}

void MarioUI::BeginPlay()
{
	// 이곳에다가 싱글톤 방식인 GetInst를 하면 렌더링이 중복되서 실행이 되지 않으므로
	// ContentsCore.cpp의 BeginPlay 에다가 구현한다.

	
	// UIBar
	{
		
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("UIBar.png");
		Renderer->SetTransform({ {510,68}, {1045, 136} });
		Renderer->CameraEffectOff();
	}


	// Scroe UI
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 0);
		Renderer->SetTransform({ {120,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}
	
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 0);
		Renderer->SetTransform({ {153,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}

	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 0);
		Renderer->SetTransform({ {186,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}

	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 0);
		Renderer->SetTransform({ {219,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}

	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 0);
		Renderer->SetTransform({ {252,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}

	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 0);
		Renderer->SetTransform({ {285,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}


	// Wolrd Stage UI
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 1);
		Renderer->SetTransform({ {635,120}, {30, 30} });
		Renderer->CameraEffectOff();
	}

	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 1);
		Renderer->SetTransform({ {715,120}, {30, 30} });
		Renderer->CameraEffectOff();
	}

	// Coin UI(Twinkle Animation)
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Coin_UI.png");
		Renderer->SetTransform({ {375,120}, {140, 140} });
		Renderer->CreateAnimation("Twninkle", "Coin_Ui.png", { 3,4 }, 3.0f, true);
		Renderer->CameraEffectOff();
	}

	// Coin Score UI
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("0.png");
		Renderer->SetTransform({ {453,120}, {30, 30} });
		Renderer->CameraEffectOff();
	}

	// World Time UI
	// 백의 자리 수
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 4);
		Renderer->SetTransform({ {860,120}, {30, 30} });
		Renderer->CameraEffectOff();
		NumberRenderer.push_back(Renderer);
	}

	// 십의 자리 수
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 0);
		Renderer->SetTransform({ {893,120}, {30, 30} });
		Renderer->CameraEffectOff();
		NumberRenderer.push_back(Renderer);
	}

	// 일의 자리 수
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("Numbers", 0);
		Renderer->SetTransform({ {926,120}, {30, 30} });
		Renderer->CameraEffectOff();
		NumberRenderer.push_back(Renderer);
	}

}

void MarioUI::Tick(float _DeltaTime)
{
	// Time을 흐르게 하기 위한 기능들
	TimeFlow -= _DeltaTime * 0.4f;
	int TimeFlowInt = TimeFlow;

	std::string Text = std::to_string(TimeFlowInt);

	int N100 = Text[0] - '1';
	int N10 = Text[1] - '0';
	int N1 = Text[2] - '0';

	NumberRenderer[0]->SetImage("Numbers", N100);
	NumberRenderer[1]->SetImage("Numbers", N10);
	NumberRenderer[2]->SetImage("Numbers", N1);

}

void MarioUI::SetUIBar(std::string_view _UIImageName)
{
	Renderer->SetImage(_UIImageName);
	UWindowImage* UIImage = Renderer->GetImage();
	UIScale = UIImage->GetScale();
}

void MarioUI::SetMarioScroeUI(std::string_view _UIImageName)
{
	Renderer->SetImage(_UIImageName);
	UWindowImage* UIImage = Renderer->GetImage();
	UIScale = UIImage->GetScale();
}

void MarioUI::SetCoinScoreUI(std::string_view _UIImageName)
{
	Renderer->SetImage(_UIImageName);
	UWindowImage* UIImage = Renderer->GetImage();
	UIScale = UIImage->GetScale();
}

void MarioUI::SetCoinUI(std::string_view _UIImageName)
{
	Renderer->SetImage(_UIImageName);
	UWindowImage* UIImage = Renderer->GetImage();
	UIScale = UIImage->GetScale();
}

void MarioUI::CoinTwinkleAnimation()
{
	Renderer->ChangeAnimation("Twinkle");

}

void MarioUI::SetWolrdStageUI(std::string_view _UIImageName)
{
	Renderer->SetImage(_UIImageName);
	UWindowImage* UIImage = Renderer->GetImage();
	UIScale = UIImage->GetScale();
}

void MarioUI::SetMarioTimeUI(std::string_view _UIImageName)
{
	Renderer->SetImage(_UIImageName);
	UWindowImage* UIImage = Renderer->GetImage();
	UIScale = UIImage->GetScale();
}