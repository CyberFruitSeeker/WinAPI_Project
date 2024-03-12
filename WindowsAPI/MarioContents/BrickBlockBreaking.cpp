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
	Renderer->CreateAnimation("BreakBlock", "BrickBlockBreaking.png", 0, 14, 0.009f, false);
	Renderer->SetScale({ 625,625 });
	Renderer->ChangeAnimation("BreakBlock");

}

void BrickBlockBreaking::Tick(float _DeltaTime)
{
	if (Renderer->IsCurAnimationEnd() == true)
	{
		Destroy();
	}

}
