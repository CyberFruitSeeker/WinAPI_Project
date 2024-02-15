#include "MarioMap.h"
#include "ContentsHelper.h"
#include <EngineCore/EngineResourcesManager.h>

MarioMap::MarioMap()
{
}

MarioMap::~MarioMap()
{
}

void MarioMap::SetMapImage(std::string_view _MarioMapImageName)
{

}

void MarioMap::SetColMapImage(std::string_view _MarioMapImageName)
{

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
		ColRenderer->SetActive(true);
	}
}

void MarioMap::BeginPlay()
{
	Renderer = CreateImageRenderer(MarioRenderOrder::Map);
	ColRenderer = CreateImageRenderer(MarioRenderOrder::Map);
	ColRenderer->SetActive(false);
}