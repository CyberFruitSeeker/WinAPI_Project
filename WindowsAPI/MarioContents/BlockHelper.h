#pragma once

// Ό³Έν :
class BlockHelper
{
public:
	// constrcuter destructer
	BlockHelper();
	~BlockHelper();

	// delete Function
	BlockHelper(const BlockHelper& _Other) = delete;
	BlockHelper(BlockHelper&& _Other) noexcept = delete;
	BlockHelper& operator=(const BlockHelper& _Other) = delete;
	BlockHelper& operator=(BlockHelper&& _Other) noexcept = delete;

protected:

private:

};

