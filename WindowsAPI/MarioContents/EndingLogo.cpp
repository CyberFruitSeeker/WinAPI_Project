#include "EndingLogo.h"

EndingLogo::EndingLogo()
{
}

EndingLogo::~EndingLogo()
{
}

void EndingLogo::BeginPlay()
{
	
	UImageRenderer* Renderer = CreateImageRenderer();

	Renderer->SetImage("Ending.png");
	SetActorLocation({ 500,500 });
	Renderer->SetTransform({ {0,0}, {768, 320} });
	Renderer->SetImageCuttingTransform({ {0,0}, {0, 0} });


}

void EndingLogo::Tick(float _DeltaTime)
{

	int a = 0;


}
