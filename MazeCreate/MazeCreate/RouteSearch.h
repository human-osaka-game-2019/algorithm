#ifndef ROUTE_SEARCH_H_
#define ROUTE_SEARCH_H_

#include"MazeCreate.h"

class Algorithm
{
protected:

	static const int width = 9;
	static const int height = 9;

	int save_gool_x;
	int save_gool_y;

	const int null = 99;

public:

	Algorithm() {}
	virtual ~Algorithm() {}
	int GetGool(int _maze[height][width]);
	void MazeInitialize(int _maze[height][width]);
};

class BellmanFord :public Algorithm
{
private:

	int max_loop = 0;
	int crrent_loop = 0;

public:
	BellmanFord(int _maze[height][width]);
	~BellmanFord() {};
	int GetMaxLoop() { return max_loop; }
	void RouteSearchBellmanFord(int _maze[height][width]);
	bool IsUpdatedCost(int* _maze1, int* _maze2, int cost = 1.0);
	bool IsInexistentWall(int _maze);
};

#endif
