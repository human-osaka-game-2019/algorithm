#include "Bellmanford.h"



void Bellmanford::InitEdges()
{
	for (int i = 0; i < edges_num; i)
	{
		//横
		for (int j = 0; j < horizontal_edges; j++)
		{
			if ((j + 1) % Maze::height)
			{
				continue;
			}
			edges[i].start = j;
			edges[i].end = j + 1;
			i++;
		}
		//縦
		for (int j = 0; j < vertical_edges; j++)
		{

			if ((j + Maze::height) > Maze::width * Maze::height - 1)
			{
				//入ることないけど一応
				continue;
			}
			edges[i].start = j;
			edges[i].end = j + Maze::height;
			i++;
		}
	}

}



