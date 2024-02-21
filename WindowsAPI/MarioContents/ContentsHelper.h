#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>

enum MarioRenderOrder
{
	Map,
	Monster,
	Player,
	Text,
};

enum class MarioCollisionOrder
{
	MarioFireBall,
	Monster,
	Player,
};

enum class EActorDir
{
	Left,
	Right,
};

enum class PlayerState
{
	None,
	CameraFreeMove,
	FreeMove,
	Idle,
	Run,
	Jump,
};

enum class MonsterState
{
	None,
	Idle,
};


// ���� :
class UContentsHelper
{
public:
	static class Mario* ItsMeMario;
	static UWindowImage* ColMapImage;
	//static FVector GetMousePos();

private:
	// constrcuter destructer
	UContentsHelper();
	~UContentsHelper();
};

