#include "Map.h"
#include "Algorithm.h"

int main()
{
	Map map;
	Algorithm algo;

	map.Show();

	for (int a = 0; a < MapSize::Height; a++)
	{
		for (int b = 0; b < MapSize::Width; b++)
		{
			if (map.Maze[a][b] == 0)
			{
				algo.NodeCheck(map.maze, a, b);
			}
		}
	}
	
	map.Show();

}
