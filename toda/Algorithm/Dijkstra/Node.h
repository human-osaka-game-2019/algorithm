#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

#include "Direction.h"

/**
 メッシュのレンダリング用構造体
 */
class Node
{
public:

	Node(int y, int x)
	{
		Position[0] = y;
		Position[1] = x;
		cost = 0;
	}

	/**
	 * nodeの位置を代入する関数
	 * @param int height Y 座標 
	 * @param int width　X 座標
	 */ 
	void InputPosition(int height, int width);

	void DeleteRoadDirection(Direction deleteDirection);

	//! 進める方向
	std::vector<Direction> SearchDirection;

	//! このnodeの次のnodeを保持する配列
	std::vector<int> NextNodes;

	//! nodeのCost
	int cost;
	
	//! nodeの(x,y)座標の配列
	int Position[2];

	//TODO : テスト用関数
	void Show();



};

#endif
