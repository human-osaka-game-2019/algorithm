
#include "Header.h"



//使わない場合はコメントアウトして

//再帰を使うかどうか
//#define RECURSION
//閉じ領域ができるかどうか
#define CLOSED_AREA
//ゴールまでが一本道かどうか
#define A_GOAL_PATH

//mapの中身
//0が道
//1が立っている壁
//2が拡張中の壁

//nodeの中身
//-1が柱が立っている
//柱の番号が柱が立っていない
//-2が拡張中の柱


int main()
{
	Maze maze;

	maze.InitWall();





#ifdef CLOSED_AREA
	maze.ClosedArea();
#endif // !CLOSED_AREA

#ifdef A_GOAL_PATH

#endif // !A_GOAL_PATH


#ifdef RECURSION

#else

	int savedirection = 0;



	while (true)
	{


		maze.RandomDirection();

		if (maze.pillar[maze.start] == maze.Expanded)
		{
			maze.RandomStart();
			continue;
		}

		maze.ExpandWall();

				
		if (maze.pillar[maze.start] == maze.Expanding)
		{
			maze.ExpandComplete();
		}

		

		//終了
		if (maze.Finish() == true)
		{
			break;
		}

#endif // RECURSION

		//画面クリア
		std::system("cls");

		//描画
		maze.DrawMap(maze.map);
	}

}