#pragma once

// Ό³Έν :
class CoinBlock
{
public:
	// constrcuter destructer
	CoinBlock();
	~CoinBlock();

	// delete Function
	CoinBlock(const CoinBlock& _Other) = delete;
	CoinBlock(CoinBlock&& _Other) noexcept = delete;
	CoinBlock& operator=(const CoinBlock& _Other) = delete;
	CoinBlock& operator=(CoinBlock&& _Other) noexcept = delete;

protected:

private:

};

