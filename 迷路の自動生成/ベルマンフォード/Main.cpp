#include "Main.h"

#include "Maze.h"

int main()
{
	Maze maze;
	//迷路の初期化
	maze.InitWall();
	//迷路生成
	maze.Create();
}


