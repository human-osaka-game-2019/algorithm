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

void BellmanFord::RouteSearchBellmanFord(int _maze[height][width])
{
	bool is_update = false;

	for (int y = 1; y < (height - 1); y++)
	{

		for (int x = 1; x < (width - 1); x++)
		{
			if (IsInexistentWall(_maze[y][x]))
			{
				if (IsInexistentWall(_maze[y][(x + 1)]))
				{
					if (IsUpdatedCost(&_maze[y][x], &_maze[y][(x + 1)]))
						is_update = true;
				}

				if (IsInexistentWall(_maze[(y + 1)][x]))
				{
					if (IsUpdatedCost(&_maze[y][x], &_maze[(y + 1)][x]))
						is_update = true;
				}
			}
		}
	}
	if (is_update)
		RouteSearchBellmanFord(_maze);

}

bool BellmanFord::IsUpdatedCost(int *_maze1, int *_maze2,int cost)
{
	if (*_maze1 == 99 && *_maze2 == 99)
	{
		return false;
	}

	if (*_maze1 + cost != *_maze2 && *_maze2 + cost != *_maze1)
	{
		if (*_maze1 < *_maze2)
		{
			*_maze2 = *_maze1 + cost;
			return true;
		}
		else if (*_maze1 > * _maze2)
		{
			*_maze1 = *_maze2 + cost;
			return true;
		}
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
