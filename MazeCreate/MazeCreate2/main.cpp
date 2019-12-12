#include"MazeHeader.h"
#include"RouteSearch.h"

int main() {

	const int maze_width = 9;
	const int maze_height = 9;

	MazeCreate* maze = new MazeCreate;
	RouteSearch* search = new RouteSearch;
	RandState rand_state;

	std::vector<int> move_x;
	std::vector<int> move_y;


	if (maze->ConditionCheck(maze_width, maze_height) == false) {
		delete(maze);
		return -1;
	}

	int _maze[maze_height][maze_width] = {};


	//外壁、壁伸ばし開始点を設定
	for (int y = 0; y < maze_height; y++)
	{
		for (int x = 0; x < maze_width; x++)
		{
			if (x == 0 || y == 0 || x == maze_width - 1 || y == maze_height - 1) {
				maze->Create(&_maze[y][x], MazeWall::LOAD);
				continue;
			}
			maze->Create(&_maze[y][x], MazeWall::WALL);
		}
	}

	maze->MazeCout(_maze);

	maze->GetRandLoad(_maze, &rand_state);
	maze->ExtendLoad(rand_state.rand_x, rand_state.rand_y, _maze, move_x, move_y);

	for (int y = 0; y < maze_height; y++)
	{
		for (int x = 0; x < maze_width; x++)
		{
			if (x == 0 || y == 0 || x == maze_width -1|| y == maze_height -1)
				maze->Create(&_maze[y][x], MazeWall::WALL);

		}
	}

	maze->Create(&_maze[1][1], MazeWall::START);
	maze->Create(&_maze[maze_height - 2][maze_width - 2], MazeWall::GOAL);

	maze->MazeCout(_maze);

	search->MazeInitialize(_maze);

	search->RouteSearchBellman(_maze);

	std::cout << search->GetGool(_maze) << std::endl;

	delete(maze);
	delete(search);

	return 0;
}