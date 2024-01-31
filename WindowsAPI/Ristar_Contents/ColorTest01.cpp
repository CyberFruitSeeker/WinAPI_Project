#include "ColorTest01.h"

ColorTest01::ColorTest01()
{
}

ColorTest01::~ColorTest01()
{
}

void ColorTest01::BeginPlay()
{
	AActor::BeginPlay();

	UImageRenderer* Renderer = CreateImageRenderer();

	Renderer->SetImage("Title.png");
	// 이미지가 나올 위치
	SetActorLocation({ 50, 50 });
	Renderer->SetTransform({ {0,0}, {100, 100} });
	Renderer->SetImageCuttingTransform({ {0,0}, {200, 200} });

	// Renderer->SetImageToScale("Title.png");
}

void ColorTest01::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	int a = 0;
}