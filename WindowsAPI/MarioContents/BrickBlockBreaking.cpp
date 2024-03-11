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

// Big Mario�� ��ȣ�ۿ��� �Ͼ �� Break Animation�� �����Ų��.
void BrickBlockBreaking::BreakAnimation(float _DeltaTime)
{

}

// Big Mario�� ��ȣ�ۿ��� �Ͼ��.
void BrickBlockBreaking::BlockMarioCol(float _DeltaTime)
{

}
