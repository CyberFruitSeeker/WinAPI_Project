#include "MarioUI.h"
#include "MarioMap.h"
#include "ContentsHelper.h"
#include "CoinBlock.h"
#include "Mario.h"

MarioUI::MarioUI()
{
}

MarioUI::~MarioUI()
{
}

void MarioUI::BeginPlay()
{
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
		Renderer->SetImage("0.png");
		Renderer->SetTransform({ {120,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}
	
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("0.png");
		Renderer->SetTransform({ {153,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}

	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("0.png");
		Renderer->SetTransform({ {186,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}

	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("0.png");
		Renderer->SetTransform({ {219,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}

	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("0.png");
		Renderer->SetTransform({ {252,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}

	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("0.png");
		Renderer->SetTransform({ {285,120}, {32, 32} });
		Renderer->CameraEffectOff();
	}

	//std::vector<UImageRenderer*> _UIRendering;
	//if (true == )
	//{

	//}


	// Wolrd Stage UI
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("1.png");
		Renderer->SetTransform({ {635,120}, {30, 30} });
		Renderer->CameraEffectOff();
	}

	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("1.png");
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
		Renderer->SetImage("4.png");
		Renderer->SetTransform({ {860,120}, {30, 30} });
		Renderer->CameraEffectOff();
	}

	// 십의 자리 수
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("0.png");
		Renderer->SetTransform({ {893,120}, {30, 30} });
		Renderer->CameraEffectOff();
	}

	// 일의 자리 수
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("0.png");
		Renderer->SetTransform({ {926,120}, {30, 30} });
		Renderer->CameraEffectOff();
	}

}

void MarioUI::Tick(float _DeltaTime)
{
	

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