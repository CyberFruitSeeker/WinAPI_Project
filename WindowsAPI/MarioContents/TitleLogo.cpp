#include "TitleLogo.h"

ATitleLogo::ATitleLogo()
{
}

ATitleLogo::~ATitleLogo()
{
}

void ATitleLogo::BeginPlay()
{
	AActor::BeginPlay();

	UImageRenderer* Renderer = CreateImageRenderer();

	Renderer->SetImage("Title.png");
	// 이미지가 나올 위치
	SetActorLocation({ 100, 100 });
	Renderer->SetTransform({ {0,0}, {800, 600} });
	Renderer->SetImageCuttingTransform({ {0,0}, {0, 0} });

	//Renderer->SetImageToScale("Title.png");
}

void ATitleLogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	int a = 0;
}