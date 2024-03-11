#include "BrickBlockBreaking.h"
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "Mario.h"

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
	Renderer->SetScale({ 500,500 });


}

void BrickBlockBreaking::Tick(float _DeltaTime)
{

}

// Big Mario와 상호작용이 일어난 후 Break Animation을 실행시킨다.
void BrickBlockBreaking::BreakAnimation(float _DeltaTime)
{

}

// Big Mario와 상호작용이 일어났다.
void BrickBlockBreaking::BlockMarioCol(float _DeltaTime)
{

}
