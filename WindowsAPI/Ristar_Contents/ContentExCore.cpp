#include "ContentExCore.h"
#include "ColorTest01.h"
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>

UContentExCore::UContentExCore()
{
}

UContentExCore::~UContentExCore()
{
}

void UContentExCore::BeginPlay()
{
	// 800 / 600�� �ʹ� ����.
	// MainWindow.SetWindowScale({1280, 720});

	// �߿��Ѱ� ũ�Ⱑ �ƴ϶� ����
	MainWindow.SetWindowScale({ 1280/* * 1.5f*/, 720/* * 1.5f*/ });

	UEngineCore::BeginPlay();

	// D:\Project\GM\WIn\App
	UEngineDirectory NewDir;

	// D:\Project\GM\WIn
	NewDir.MoveParent();

	// D:\Project\GM\WIn\ContentsResources
	NewDir.Move("ContentsResources");

	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	// ���ν��� ���⼭ �ε��Ҽ��� �ִ�.

	// �츮�� �����ϴ°� Level
	CreateLevel<ColorTest01>("Title");
	ChangeLevel("Title");
}

void UContentExCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}
