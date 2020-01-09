#ifndef ROUTE_SEARCH_H_
#define ROUTE_SEARCH_H_

#include"MazeCreate.h"

class Algorithm
{
protected:

	static const int width = 15;
	static const int height = 7;

	int save_gool_x;
	int save_gool_y;

	const int null = 99;

public:

	Algorithm() {}
	virtual ~Algorithm() {}
	int GetGool(int _maze[height][width]);
	void MazeInitialize(int _maze[height][width]);
};


class BellmanFord:public Algorithm
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


class Dijkstra :public Algorithm
{
private:

	enum class LoadType
	{
		DeadEnd,
		Aisle,
		Fork,
	};

	std::vector<int>save_fork_x;
	std::vector<int>save_fork_y;

public:
	Dijkstra ();
	~Dijkstra ();
	void RouteSearchDijkstra(int x, int y, int _maze[height][width]);
	//スタート用経路探索関数
	void RouteSearchDijkstraEx(int x, int y, int _maze[height][width]);
	bool IsUpdatedCost(int* _maze1, int* _maze2, int cost = 1.0);
	LoadType IsInexistentLoad(int x, int y, int _maze[height][width]);
	//スタート用分岐路記憶関数
	LoadType IsInexistentLoadEx(int x, int y, int _maze[height][width]);

};
#endif // !ROUTE_SEARCH_H_

