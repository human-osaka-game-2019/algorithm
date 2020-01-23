#include"RouteSearch.h"

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

int Dijkstra::RouteSearchDijkstraEx(int x, int y, int _maze[height][width])
{
	IsInexistentLoad(x, y, _maze);

	int save_x;
	int save_y;

	switch (GetRouteDirection(x, y, _maze))
	{
	case Direction::Up:
		save_x = x;
		save_y = y - 1;
		break;
	case Direction::Left:
		save_x = x - 1;
		save_y = y;
		break;
	case Direction::Down:
		save_x = x;
		save_y = y + 1;
		break;
	case Direction::Right:
		save_x = x + 1;
		save_y = y;
		break;
	default:
		return 0;
	}

	RouteSearchDijkstra(save_x, save_y, _maze);
}

int Dijkstra::RouteSearchDijkstra(int x, int y, int _maze[height][width])
{
	int save_x;
	int save_y;

	if (IsInexistentLoad(x, y, _maze) == LoadType::DeadEnd)
	{
		if (save_fork_x.empty() == false && save_fork_y.empty() == false)
		{
			save_x = save_fork_x.back();
			save_y = save_fork_y.back();

			if (GetRouteDirectionEx(save_x, save_y, _maze) == Direction::No)
			{
				save_fork_x.pop_back();
				save_fork_y.pop_back();
			}

			RouteSearchDijkstra(save_x, save_y, _maze);

		}

		return 0;
	}


	switch (GetRouteDirection(x, y, _maze))
	{
	case Direction::Up:
		save_x = x;
		save_y = y - 1;
		break;
	case Direction::Left:
		save_x = x - 1;
		save_y = y;
		break;
	case Direction::Down:
		save_x = x;
		save_y = y + 1;
		break;
	case Direction::Right:
		save_x = x + 1;
		save_y = y;
		break;
	case Direction::No:
		return -1;
	}

	RouteSearchDijkstra(save_x, save_y, _maze);
}

bool Dijkstra::IsUpdatedCost(int& _maze1, int& _maze2, int cost)
{
	if (_maze1 + cost == _maze2)
	{
		return false;
	}

	if (_maze1 < _maze2)
	{
		_maze2 = _maze1 + cost;

		return true;
	}

	return false;
}

Dijkstra::Direction  Dijkstra::GetRouteDirectionEx(int x, int y, int _maze[height][width],int cost)
{
	if (_maze[y][x - 1] != (int)MazeWall::WALL)
		if (_maze[y][x] + cost < _maze[y][x - 1])
			return Direction::Left;

	if (_maze[y][x + 1] != (int)MazeWall::WALL)
		if (_maze[y][x] + cost < _maze[y][x + 1])
			return Direction::Right;

	if (_maze[y - 1][x] != (int)MazeWall::WALL)
		if (_maze[y][x] + cost < _maze[y - 1][x])
			return Direction::Up;

	if (_maze[y + 1][x] != (int)MazeWall::WALL)
		if (_maze[y][x] + cost < _maze[y + 1][x])
			return Direction::Down;

	return Direction::No;
}

Dijkstra::Direction Dijkstra::GetRouteDirection(int x, int y, int _maze[height][width])
{
	if (_maze[y][x - 1] != (int)MazeWall::WALL)
		if (IsUpdatedCost(_maze[y][x], _maze[y][x - 1]))
			return Direction::Left;

	if (_maze[y][x + 1] != (int)MazeWall::WALL)
		if (IsUpdatedCost(_maze[y][x], _maze[y][x + 1]))
			return Direction::Right;

	if (_maze[y - 1][x] != (int)MazeWall::WALL)
		if (IsUpdatedCost(_maze[y][x], _maze[y - 1][x]))
			return Direction::Up;

	if (_maze[y + 1][x] != (int)MazeWall::WALL)
		if (IsUpdatedCost(_maze[y][x], _maze[y + 1][x]))
			return Direction::Down;

	return Direction::No;
}

Dijkstra::LoadType Dijkstra::IsInexistentLoad(int x, int y, int _maze[height][width],int cost)
{
	int route_count = 0;

	if (_maze[y][x - 1] != (int)MazeWall::WALL)
		if (_maze[y][x] + cost < _maze[y][x - 1])
			route_count++;

	if (_maze[y][x + 1] != (int)MazeWall::WALL)
		if (_maze[y][x] + cost < _maze[y][x + 1])
			route_count++;

	if (_maze[y - 1][x] != (int)MazeWall::WALL)
		if (_maze[y][x] + cost < _maze[y - 1][x])
			route_count++;

	if (_maze[y + 1][x] != (int)MazeWall::WALL)
		if (_maze[y][x] + cost < _maze[y + 1][x])
			route_count++;

	if (route_count >= 2)
	{
		save_fork_x.push_back(x);
		save_fork_y.push_back(y);

		return LoadType::Fork;
	}

	return route_count == 1 ? LoadType::Aisle : LoadType::DeadEnd;

}
