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
	// �̹����� ���� ��ġ
	SetActorLocation({ 50, 50 });
	Renderer->SetTransform({ {50,50}, {100, 100} });
	Renderer->SetImageCuttingTransform({ {0,0}, {200, 200} });

	// Renderer->SetImageToScale("Title.png");
}

void ATitleLogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	int a = 0;
}