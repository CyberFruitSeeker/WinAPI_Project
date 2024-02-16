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
	FVector ImageScale = Image->GetScale();
	Renderer->SetTransform({ ImageScale.Half2D(), ImageScale });
}

void MarioMap::SetColMapImage(std::string_view _MapImageName)
{
	ColRenderer->SetImage(_MapImageName);
	UWindowImage* Image = ColRenderer->GetImage();
	UContentsHelper::ColMapImage = Image;
	FVector ImageScale = Image->GetScale();
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
		Renderer->SetActive(false);
		ColRenderer->SetActive(true);
	}
	else
	{
		Renderer->SetActive(true);
		ColRenderer->SetActive(false);
	}
}

void MarioMap::BeginPlay()
{
	Renderer = CreateImageRenderer(MarioRenderOrder::Map);
	ColRenderer = CreateImageRenderer(MarioRenderOrder::Map);
	ColRenderer->SetActive(false);
}