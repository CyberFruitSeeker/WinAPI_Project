@echo off 
xcopy C:\GitHubFiles\GM\WIn\EngineBase\*.h C:\GitHubFiles\GitHubPullTest\WinAPI_Project\WindowsAPI\EngineBase\ /e /h /k /y
xcopy C:\GitHubFiles\GM\WIn\EngineCore\*.h C:\GitHubFiles\GitHubPullTest\WinAPI_Project\WindowsAPI\EngineCore\ /e /h /k /y
xcopy C:\GitHubFiles\GM\WIn\EnginePlatform\*.h C:\GitHubFiles\GitHubPullTest\WinAPI_Project\WindowsAPI\EnginePlatform\ /e /h /k /y

@echo off 
xcopy C:\GitHubFiles\GM\WIn\EngineBase\*.cpp C:\GitHubFiles\GitHubPullTest\WinAPI_Project\WindowsAPI\EngineBase\ /e /h /k /y
xcopy C:\GitHubFiles\GM\WIn\EngineCore\*.cpp C:\GitHubFiles\GitHubPullTest\WinAPI_Project\WindowsAPI\EngineCore\ /e /h /k /y
xcopy C:\GitHubFiles\GM\WIn\EnginePlatform\*.cpp C:\GitHubFiles\GitHubPullTest\WinAPI_Project\WindowsAPI\EnginePlatform\ /e /h /k /y
