#ifndef BELLMANFORD_H_
#define BELLMANFORD_H_

#include "Maze.h"

struct Edge
{
	int start;
	int end;
	int cost = {1};

	int edge_starting_point_number_updated_distance;
};

struct Node
{
	int reach_cost;
};

class Bellmanford
{
public:

	Bellmanford()
	{
		InitEdges();
	}

	static const int horizontal_edges = (Maze::width - 1) * Maze::height;

	static const int vertical_edges = (Maze::height - 1) * Maze::width;

	static const int edges_num = horizontal_edges + vertical_edges;

	Node nodes[Maze::width * Maze::height];

	Edge edges[edges_num];

	void InitEdges();

};

#endif // !BELLMANFORD_H_


