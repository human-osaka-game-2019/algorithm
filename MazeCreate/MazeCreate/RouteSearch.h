#ifndef ROUTE_SEARCH_H_
#define ROUTE_SEARCH_H_

#include"MazeCreate.h"

class RouteSearch
{
private:

	int save_gool_x;
	int save_gool_y;

	int max_loop = 0;
	int crrent_loop = 0;

	const int null = 99;

	static const int width = 15;
	static const int height = 5;

public:
	RouteSearch(int _maze[height][width]);
	~RouteSearch() {};
	int GetGool(int _maze[height][width]);
	int GetMaxLoop() { return max_loop; }
	void MazeInitialize(int _maze[height][width]);
	void RouteSearchBellman(int _maze[height][width]);
	bool IsUpdatedCost(int *_maze1, int *_maze2);
	bool IsInexistentWALL(int _maze);
};

#endif // !ROUTE_SEARCH_H_

