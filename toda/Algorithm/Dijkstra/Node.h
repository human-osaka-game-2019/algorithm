#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

#include "Direction.h"

class Node
{
public:

	Node(int y, int x)
	{
		Position[0] = y;
		Position[1] = x;
		cost = 0;
	}

	void InputPosition(int height, int width);


	//! 進める方向
	std::vector<Direction> SearchDirection;
	std::vector<Direction> SearchedDirection;

	std::vector<int> NextNodes;

	int cost;
	int Position[2];
	//TODO : テスト用関数
	void Show();



};

#endif
