#include"RouteSearch.h"

/////////////////////////////////////////////////////////////////////////

void Algorithm::MazeInitialize(int _maze[height][width])
{
	for (int y = 1; y < height - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			//大きな値で初期化
			if (_maze[y][x] == (int)MazeWall::NO)
			{
				_maze[y][x] = 99;
			}

			if (_maze[y][x] == (int)MazeWall::GOAL)
			{
				save_gool_x = x;
				save_gool_y = y;
				_maze[y][x] = 99;
			}
		}
	}
}

int Algorithm::GetGool(int _maze[height][width])
{
	return _maze[save_gool_y][save_gool_x];
}

/////////////////////////////////////////////////////////////////////////

BellmanFord::BellmanFord(int _maze[height][width])
{
	for (int y = 1; y < (height - 1); y++)
	{
		for (int x = 1; x < (width - 1); x++)
		{
			//ベルマンフォード法は 頂点の数 - 1 回のループで最短距離を求めることができる
			if (_maze[y][x] == (int)MazeWall::NO ||
				_maze[y][x] == (int)MazeWall::START ||
				_maze[y][x] == (int)MazeWall::GOAL)
				max_loop++;
		}
	}
}

void BellmanFord::RouteSearchBellmanFord(int _maze[height][width])
{
	for (int y = 1; y < (height - 1); y++)
	{

		for (int x = 1; x < (width - 1); x++)
		{
			if (IsInexistentWall(_maze[y][x]))
			{
				if (IsInexistentWall(_maze[y][(x + 1)]))
				{
					IsUpdatedCost(&_maze[y][x], &_maze[y][(x + 1)]);
				}

				if (IsInexistentWall(_maze[(y + 1)][x]))
				{
					IsUpdatedCost(&_maze[y][x], &_maze[(y + 1)][x]);
				}
			}
		}
	}

		crrent_loop++;
	
	if (max_loop > crrent_loop)
		RouteSearchBellmanFord(_maze);

}

bool BellmanFord::IsUpdatedCost(int *_maze1, int *_maze2,int cost)
{
	if (*_maze1 == 99 && *_maze2 == 99)
	{
		return false;
	}
		if (*_maze1 < *_maze2)
		{
			*_maze2 = *_maze1 + cost;
			return true;
		}
		else if (*_maze1 > *_maze2)
		{
			*_maze1 = *_maze2 + cost;
			return true;
		}
	
		return false;
}

bool BellmanFord::IsInexistentWall(int _maze)
{
	if (_maze == (int)MazeWall::WALL)
	{
		return false;
	}

	return true;
}

