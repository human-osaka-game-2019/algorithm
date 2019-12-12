#ifndef ROUTE_SEARCH_H_
#define ROUTE_SEARCH_H_

#include"MazeHeader.h"

class RouteSearch
{
private:

	int save_gool_x;
	int save_gool_y;

	bool is_updated = false;

	static const int width = 9;
	static const int height = 9;

public:
	RouteSearch() {};
	~RouteSearch() {};
	int GetGool(int _maze[height][width]);
	void MazeInitialize(int _maze[height][width]);
	void RouteSearchBellman(int _maze[height][width]);
	bool IsUpdatedCost(int* _maze1, int* _maze2);
	bool IsInexistentWALL(int _maze1, int _maze2);
};

#endif // !ROUTE_SEARCH_H_
