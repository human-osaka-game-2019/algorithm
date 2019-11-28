#include "Dijkstra.h"


int main()
{
	Maze maze;

	maze.InitWall();

	int savedirection = 0;


	while (true)
	{


		maze.RandomDirection();

		if (maze.pillar[maze.start] == Expanded)
		{
			maze.RandomStart();
			continue;
		}

		maze.ExpandWall();


		if (maze.pillar[maze.start] == Expanding)
		{
			maze.ExpandComplete();
		}



		//終了
		if (maze.Finish() == true)
		{
			break;
		}



		//画面クリア
		std::system("cls");
		//描画
		maze.DrawMap(maze.map);

	}

	maze.MakeStart();
	maze.MakeGoal();
	std::system("cls");

	maze.DrawMap(maze.map);

}




