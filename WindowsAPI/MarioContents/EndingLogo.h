#pragma once

// Ό³Έν :
class EndingLogo
{
public:
	// constrcuter destructer
	EndingLogo();
	~EndingLogo();

	// delete Function
	EndingLogo(const EndingLogo& _Other) = delete;
	EndingLogo(EndingLogo&& _Other) noexcept = delete;
	EndingLogo& operator=(const EndingLogo& _Other) = delete;
	EndingLogo& operator=(EndingLogo&& _Other) noexcept = delete;

protected:

private:

};

