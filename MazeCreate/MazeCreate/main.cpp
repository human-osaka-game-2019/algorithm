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

	//�ړ��ʂ��L������p
	std::vector<int> move_x;
	std::vector<int> move_y;

	//���H�����̏�������������Ă��Ȃ�������I��
	if (maze->ConditionCheck(maze_width, maze_height) == false) {
		delete(maze);
		delete(rand_state);
		return -1;
	}

	int _maze[maze_height][maze_width] = {};

	//�O�ǁA�ǐL�΂��J�n�_��ݒ�
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

	//�����Ŗ��H����
	maze->MazeCout(_maze);
	do {

		maze->GetRandSeed(_maze, rand_state);
		maze->Create(&_maze[rand_state->rand_y][rand_state->rand_x], MazeWall::ME_WALL);
		maze->ExtendWall(rand_state->rand_x, rand_state->rand_y, _maze, move_x, move_y);

	} while (maze->GetSeedCount() != 0);

	//�X�^�[�g�ƃS�[���͌��ߑł�
	maze->Create(&_maze[1][1], MazeWall::START);
	maze->Create(&_maze[maze_height - 2][maze_width - 2], MazeWall::GOAL);

	maze->MazeCout(_maze);

	//��������o�H�T��
	BellmanFord* search = new BellmanFord(_maze);

	search->MazeInitialize(_maze);

	search->RouteSearchBellmanFord(_maze);

	std::cout << std::endl << "�ŒZ������" << search->GetGool(_maze) << "�ł�" << std::endl;

	delete(maze);
	delete(search);
	delete(rand_state);

	return 0;
}