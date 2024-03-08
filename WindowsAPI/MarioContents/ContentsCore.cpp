#include "ContentsCore.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>

UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::BeginPlay()
{
	// 레트로 게임의 일반적인 해상도인 800 x 600은 현재로서는 너무나도 작은 해상도이다.
	// 하지만? 그렇다고 해서 MainWindow.SetWindowScale({1280, 720}); 로 할 수는 없다.
	// 그러므로 중요한건 해상도의 크기가 아니라 '비율'이다.
	//MainWindow.SetWindowPosition({500, 100});
	// 
	//                           1024                960
	MainWindow.SetWindowScale({ 256 * 4/* * 1.5f*/, 240 * 4/* * 1.5f*/ });
	MainWindow.SetWindowPosition({ 800/* * 1.5f*/, 0/* * 1.5f*/ });

	UEngineCore::BeginPlay();

	// 드라이브:\Project\파일명\WinAPI\App
	UEngineDirectory NewDir;

	// 드라이브:\Project\파일명\WinAPI
	NewDir.MoveParent();

	// ContentsResources 폴더로 접근하기
	NewDir.Move("ContentsResources");

	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	// 엔진만의 규칙을 정할 것인가?
	// Engine에 구현 되어있는 싱글톤 활용을 위해서 GetInst를 사용해본다.
	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("Mario_Right.png", 5, 7);
	UEngineResourcesManager::GetInst().CuttingImage("Mario_Left.png", 5, 7);

	// 몬스터 기능 실험용 굼바 다크
	UEngineResourcesManager::GetInst().CuttingImage("GoombaDark.png", 3, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Goomba.png", 3, 1);

	UEngineResourcesManager::GetInst().CuttingImage("Troopa_Left.png", 6, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Troopa_Right.png", 6, 1);

	UEngineResourcesManager::GetInst().CuttingImage("Item.png", 5, 2);




	CreateLevel<UTitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Title");
	
}

void UContentsCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown(VK_F2))
	{
		GEngine->EngineDebugSwitch();
	}
}
