#include "MarioUI.h"
#include "MarioMap.h"
#include "ContentsHelper.h"

MarioUI::MarioUI()
{
}

MarioUI::~MarioUI()
{
}

void MarioUI::BeginPlay()
{
	// UIBar 렌더링 테스트
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::UI);
		Renderer->SetImage("UIBar.png");
		Renderer->SetTransform({ {512,64}, {1040, 135} });
		Renderer->CameraEffectOff();
	}




}

void MarioUI::Tick(float _DeltaTime)
{




}

void MarioUI::SetMarioWorldUI(std::string_view _UIImageName)
{
	Renderer->SetImage(_UIImageName);
	UWindowImage* UIImage = Renderer->GetImage();
	UIScale = UIImage->GetScale();

}

void MarioUI::SetMarioTimeUI(std::string_view _UIImageName)
{

}

void MarioUI::SetMarioCoinUI(std::string_view _UIImageName)
{

}
