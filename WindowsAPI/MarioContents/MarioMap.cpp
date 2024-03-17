#include "MarioMap.h"
#include "ContentsHelper.h"
#include <EngineCore/EngineResourcesManager.h>

MarioMap::MarioMap()
{
}

MarioMap::~MarioMap()
{
}

void MarioMap::SetMapImage(std::string_view _MapImageName)
{
	Renderer->SetImage(_MapImageName);
	UWindowImage* Image = Renderer->GetImage();
	//FVector ImageScale = Image->GetScale();
	ImageScale = Image->GetScale();
	Renderer->SetTransform({ ImageScale.Half2D(), ImageScale });
}

void MarioMap::SetColMapImage(std::string_view _MapImageName)
{
	ColRenderer->SetImage(_MapImageName);
	UWindowImage* Image = ColRenderer->GetImage();
	ContentsHelper::ColMapImage = Image;
	//FVector ImageScale = Image->GetScale();
	ImageScale = Image->GetScale();
	ColRenderer->SetTransform({ ImageScale.Half2D(),ImageScale });
}

void MarioMap::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsDown('O'))
	{
		SwitchDebug();
	}
}

void MarioMap::SwitchDebug()
{
	if (true == Renderer->IsActive())
	{
		Renderer->SetActive(true);
		ColRenderer->SetActive(false);
	}
	else
	{
		Renderer->SetActive(true);
		ColRenderer->SetActive(true);
	}
}

void MarioMap::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(MarioRenderOrder::Map);
	Renderer->SetImage("MarioWorld01.png");
	ColRenderer = CreateImageRenderer(MarioRenderOrder::Map);
	ColRenderer->SetActive(false);
}