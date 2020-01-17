#include"MazeCreate.h"
#include"RouteSearch.h"

namespace
{
	const int maze_width = 9;
	const int maze_height = 9;
}

int main()
{
	MazeCreate* maze = new MazeCreate;
	RandState* rand_state = new RandState;

	//移動量を記憶する用
	std::vector<int> move_x;
	std::vector<int> move_y;

	//迷路生成の条件が満たされていなかったら終了
	if (maze->ConditionCheck(maze_width, maze_height) == false) {
		delete(maze);
		delete(rand_state);
		return -1;
	}

	int _maze[maze_height][maze_width] = {};

	//外壁、壁伸ばし開始点を設定
	for (int y = 0; y < maze_height; y++) {
		for (int x = 0; x < maze_width; x++) {
			if (x == 0 || y == 0 || x == maze_width - 1 || y == maze_height - 1) {
				maze->Create(&_maze[y][x], MazeWall::WALL);
			}
			else if (x % 2 == 0 && y % 2 == 0) {
				maze->Create(&_maze[y][x], MazeWall::SEED);
				maze->PlusSeedCount();
			}
			else
			{
				maze->Create(&_maze[y][x], MazeWall::NO);
			}
		}
	}

	//ここで迷路生成
	maze->MazeCout(_maze);
	do {

		maze->GetRandSeed(_maze, rand_state);
		maze->Create(&_maze[rand_state->rand_y][rand_state->rand_x], MazeWall::ME_WALL);
		maze->ExtendWall(rand_state->rand_x, rand_state->rand_y, _maze, move_x, move_y);

	} while (maze->GetSeedCount() != 0);

	//スタートとゴールは決め打ち
	maze->Create(&_maze[1][1], MazeWall::START);
	maze->Create(&_maze[maze_height - 2][maze_width - 2], MazeWall::GOAL);

	maze->MazeCout(_maze);

	//ここから経路探索
	BellmanFord* search = new BellmanFord(_maze);

	search->MazeInitialize(_maze);

	search->RouteSearchBellmanFord(_maze);

	std::cout << std::endl << "最短距離は" << search->GetGool(_maze) << "です" << std::endl;

	delete(maze);
	delete(search);
	delete(rand_state);

	return 0;
}