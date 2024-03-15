#include "ContentsCore.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include "EndingLevel.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EnginePlatform/EngineSound.h>

UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::BeginPlay()
{
	// ��Ʈ�� ������ �Ϲ����� �ػ��� 800 x 600�� ����μ��� �ʹ����� ���� �ػ��̴�.
	// ������? �׷��ٰ� �ؼ� MainWindow.SetWindowScale({1280, 720}); �� �� ���� ����.
	// �׷��Ƿ� �߿��Ѱ� �ػ��� ũ�Ⱑ �ƴ϶� '����'�̴�.
	//MainWindow.SetWindowPosition({500, 100});
	// 
	//                           1024                960
	MainWindow.SetWindowScale({ 256 * 4/* * 1.5f*/, 240 * 4/* * 1.5f*/ });
	MainWindow.SetWindowPosition({ 800/* * 1.5f*/, 0/* * 1.5f*/ });

	UEngineCore::BeginPlay();

	// ����̺�:\Project\���ϸ�\WinAPI\App
	UEngineDirectory NewDir;

	// ����̺�:\Project\���ϸ�\WinAPI
	NewDir.MoveParent();

	// ContentsResources ������ �����ϱ�
	NewDir.Move("ContentsResources");

	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	// �������� ��Ģ�� ���� ���ΰ�?
	// Engine�� ���� �Ǿ��ִ� �̱��� Ȱ���� ���ؼ� GetInst�� ����غ���.
	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("Mario_Right.png", 5, 7);
	UEngineResourcesManager::GetInst().CuttingImage("Mario_Left.png", 5, 7);

	// ���� ��� ����� ���� ��ũ
	UEngineResourcesManager::GetInst().CuttingImage("GoombaDark.png", 3, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Goomba.png", 3, 1);

	UEngineResourcesManager::GetInst().CuttingImage("Troopa_Left.png", 6, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Troopa_Right.png", 6, 1);

	UEngineResourcesManager::GetInst().CuttingImage("Item.png", 5, 2);

	UEngineResourcesManager::GetInst().CuttingImage("BrickBlock.png", 5, 1);
	UEngineResourcesManager::GetInst().CuttingImage("ItemCoinBlock.png", 5, 1);
	UEngineResourcesManager::GetInst().CuttingImage("BrickBlockBreaking.png", 5, 3);

	UEngineResourcesManager::GetInst().CuttingImage("Flag.png", 1, 1);

	UEngineResourcesManager::GetInst().CuttingImage("UIBar.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("0.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("1.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("2.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("3.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("4.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("5.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("6.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("7.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("8.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("9.png", 1, 1);
	//UEngineResourcesManager::GetInst().CuttingImage("100.png", 1, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Coin_UI.png", 6, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Number_UI.png", 10, 1);

	// UI ������ �����ؼ� �˰� ���ִ� ���, �̱��� ����̴�.
	{
		UEngineDirectory UIDir;
		UIDir.MoveParent();
		UIDir.Move("ContentsResources");
		UIDir.Move("PlayLevel/UI/Number");

		UEngineResourcesManager::GetInst().LoadFolder(UIDir.GetFullPath(), "Numbers");
	}

	// ���� �ε�
	{
		std::list<UEngineFile>NewList = NewDir.AllFile({ ".wav",".mp3" }, true);
		for (UEngineFile& File : NewList)
		{
			UEngineSound::Load(File.GetFullPath());
		}
	}


	CreateLevel<UTitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
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
