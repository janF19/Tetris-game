#pragma once

#include "grid.h"
#include "blocks.cpp"




class Game


{

public:
	Game();
	void Draw();
	void HandleInput();
	
	void MoveBlockDown();
	bool gameOver;
	int score;



private: 
	Grid grid;
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void MoveBlockLeft();
	void MoveBlockRight();
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;

};

