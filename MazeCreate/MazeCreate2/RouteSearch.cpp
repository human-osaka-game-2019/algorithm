#include"RouteSearch.h"

void RouteSearch::MazeInitialize(int _maze[height][width])
{
	for (int y = 1; y < height - 1; y++) 
	{
		for (int x = 1; x < width - 1; x++) 
		{
			if (_maze[y][x] == (int)MazeWall::LOAD) 
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

void RouteSearch::RouteSearchBellman(int _maze[height][width])
{

	is_updated = false;

	for (int x = 1; x < width - 1; x++)
	{

		for (int y = 1; y < height - 1; y++)
		{
			if (IsInexistentWALL(_maze[y][x], _maze[y][x++]))
				is_updated = IsUpdatedCost(&_maze[y][x], &_maze[y][x++]);

			if (IsInexistentWALL(_maze[y][x], _maze[y++][x]))
				is_updated = IsUpdatedCost(&_maze[y][x], &_maze[y++][x]);
		}
	}

	if (is_updated)
		RouteSearchBellman(_maze);

}

bool RouteSearch::IsUpdatedCost(int* _maze1, int* _maze2)
{
	if (_maze1 > _maze2)
	{
		_maze1 = _maze2++;
		return true;
	}

	if (_maze1 < _maze2)
	{
		_maze2 = _maze1++;
		return true;
	}

	return false;
}

bool RouteSearch::IsInexistentWALL(int _maze1, int _maze2)
{
	if (_maze1 == (int)MazeWall::WALL || _maze2 == (int)MazeWall::WALL)
	{
		return false;
	}

	return true;
}

int RouteSearch::GetGool(int _maze[height][width])
{
	return _maze[save_gool_y][save_gool_x];
}
