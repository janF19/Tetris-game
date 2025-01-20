#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "Colors.h"


class Block

{

public:
	Block();
	int id;
	void Draw(int offsetX, int offsetY);
	void Move(int rows, int columns);
	std::vector<Position> GetCellPositions();
	void Rotate();
	void UndoRotation();


	//std::vector<Block> GetAllBlocks;

	//key is rotation state and value is vector containing positions of occupied cells
	std::map<int, std::vector<Position>> cells;
	


private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int rowOffset;
	int columnOffset;


};

