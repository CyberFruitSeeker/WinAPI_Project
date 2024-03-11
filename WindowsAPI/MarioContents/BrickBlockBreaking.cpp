#include "BrickBlockBreaking.h"
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "Mario.h"
#include "BrickBlock.h"

BrickBlockBreaking::BrickBlockBreaking()
{

}

BrickBlockBreaking::~BrickBlockBreaking()
{

}

void BrickBlockBreaking::BeginPlay()
{
	
	SetName("BreakingBlock");
	Renderer = CreateImageRenderer(MarioRenderOrder::BreakingBlock);
	Renderer->SetImage("BrickBlockBreaking.png");
	Renderer->CreateAnimation("BreakBlock", "BrickBlockBreaking.png", 0, 14, 0.010f, false);
	Renderer->SetScale({ 600,600 });
	Renderer->ChangeAnimation("BreakBlock");

}

void BrickBlockBreaking::Tick(float _DeltaTime)
{
	if (Renderer->IsCurAnimationEnd() == true)
	{
		Destroy();
	}

}
