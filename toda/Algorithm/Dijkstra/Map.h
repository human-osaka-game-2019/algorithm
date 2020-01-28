#ifndef MAP_H
#define MAP_H

#include <iostream>

using std::cout;
using std::endl;

namespace MapSize
{
	const int Width = 11;
	const int Height = 11;
}
/**
マップの情報を持ったクラス
*/
class Map
{
public:

	Map();

	~Map();

	//1 迷路の中身の二次元配列
	int Maze[MapSize::Height][MapSize::Width] = 
	{
		{1,1,1,1,1,1,1,1,1,1,1},
	    {1,2,0,0,1,0,0,0,0,0,1},
	    {1,1,1,0,1,0,1,1,1,1,1},
	    {1,0,0,0,1,0,1,0,0,0,1},
	    {1,0,1,1,1,0,0,0,1,1,1},
	    {1,0,0,0,0,0,1,0,0,0,1},
	    {1,0,1,0,1,0,1,0,1,0,1},
	    {1,0,1,0,1,0,1,0,1,0,1},
	    {1,0,1,1,1,1,1,0,1,1,1},
	    {1,0,1,0,0,0,0,0,0,3,1},
	    {1,1,1,1,1,1,1,1,1,1,1}
	
	};

	/**
	 * 迷路の描画関数
	 */
	void Show();

	//! 迷路の二次元配列を保持しやすくするためのポインタ
	int* maze[MapSize::Height];

private:

	/**
	 * 初期化関数
	 */
	void Initialize();

	/**
	 * マップの情報を描画する関数
	 * @param int MapDate マップの情報
	 */
	void DrawMapData(int MapDate);
};

#endif
