#include "Map.h"
#include "Search.h"

int main()
{
	Map map;
	Search search;

	map.Show();

	for (int a = 0; a < MapSize::Height; a++)
	{
		for (int b = 0; b < MapSize::Width; b++)
		{
			if (map.Maze[a][b] == 0)
			{
				search.NodeCheck(map.maze, a, b);
			}
		}
	}
	
	map.Show();

	search.flow(map.maze,1,1);

}
