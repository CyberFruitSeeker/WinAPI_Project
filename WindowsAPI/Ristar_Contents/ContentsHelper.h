#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>

enum MarioRenderOrder
{
	Map,
	Monster,
	Player
};

// ���� :
class UContentsHelper
{
public:
	static UWindowImage* ColMapImage;
	static FVector GetMousePos();

private:
	// constrcuter destructer
	UContentsHelper();
	~UContentsHelper();
};

