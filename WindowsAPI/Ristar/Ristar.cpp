#include <Windows.h>
#include <EngineCore\EngineCore.h>
#include <EnginePlatform\EngineWindow.h>
#include <Ristar_Contents/ContentExCore.h>

// 옛날 엔진이 유저들에게 엔진을 쉽게 기동시키기 위해 사용한 방식이다.

// 사용자가 하고싶은 일을 어떻게, 어디에 정의하게 만들 것이냐?
// 사용자가 윈도우 크기를 변경하고 싶어!

//ENGINESTART(ContentsCore);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	LeakCheck;
	UContentExCore NewUserCore = UContentExCore();
	UEngineCore::EngineStart(hInstance, &NewUserCore);
}
