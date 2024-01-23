#pragma once

// Ό³Έν :
class App
{
public:
	// constrcuter destructer
	App();
	~App();

	// delete Function
	App(const App& _Other) = delete;
	App(App&& _Other) noexcept = delete;
	App& operator=(const App& _Other) = delete;
	App& operator=(App&& _Other) noexcept = delete;

protected:

private:

};

