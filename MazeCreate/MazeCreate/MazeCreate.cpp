#include"MazeCreate.h"

int main() {
	const int maze_width = 15;
	const int maze_height = 15;

	MazeCreate* maze = new MazeCreate;
	RandState* rand_state = new RandState;

	std::vector<int> move_x;
	std::vector<int> move_y;

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
		}
	}

	maze->MazeCout(_maze);
	do {
		maze->GetRandSeed(_maze, rand_state);
		maze->Create(&_maze[rand_state->rand_y][rand_state->rand_x], MazeWall::ME_WALL);
		maze->ExtendWall(rand_state->rand_x, rand_state->rand_y, _maze, move_x, move_y);
	} while (maze->GetSeedCount() != 0);

	maze->MazeCout(_maze);

	delete(maze);
	delete(rand_state);

	move_x.clear();
	move_y.clear();

	return 0;
}

int MazeCreate::GetSeedCount() {
	return m_seed_count;
}

int MazeCreate::GetCreateCount() {
	return m_create_count;
}

void MazeCreate::GetRandSeed(int _maze[height][width], RandState* rand_state) {
	do {
		std::mt19937 mt;
		std::random_device rnd;
		mt.seed(rnd());

		rand_state->rand_y = mt() % (height - 3) + 2;
		rand_state->rand_x = mt() % (width - 3) + 2;
		if (rand_state->rand_y % 2 != 0)
			rand_state->rand_y++;
		if (rand_state->rand_x % 2 != 0)
			rand_state->rand_x++;
	} while (_maze[rand_state->rand_y][rand_state->rand_x] != (int)MazeWall::SEED);
}

void MazeCreate::PlusSeedCount() {
	m_seed_count++;
}

void MazeCreate::MinusSeedCount() {
	if (GetSeedCount() > 0)
		m_seed_count--;
}

void MazeCreate::MinusCreateCount() {
	if (GetCreateCount() > 0)
		m_create_count--;
}

void MazeCreate::Create(int* _maze, MazeWall maze_wall) {
	switch (maze_wall)
	{
	case MazeWall::NO:
		*_maze = (int)MazeWall::NO;
		break;
	case MazeWall::WALL:
		if (*_maze == (int)MazeWall::SEED)
			MinusSeedCount();
		*_maze = (int)MazeWall::WALL;
		break;
	case MazeWall::ME_WALL:
		if (*_maze == (int)MazeWall::SEED)
			MinusSeedCount();
		*_maze = (int)MazeWall::ME_WALL;
		break;
	case MazeWall::SEED:
		*_maze = (int)MazeWall::SEED;
		break;
	default:
		break;
	}
}

int MazeCreate::ExtendWall(int x, int y, int _maze[height][width], std::vector<int>& move_x, std::vector<int>& move_y)
{
	std::vector<Direction>direction;

	if (MeWallCheck(x, y, _maze, direction))
	{

		if (WallCheck(x, y, _maze))
		{

			std::mt19937 mt;
			std::random_device rnd;
			mt.seed(rnd());

			int rand_d = mt() % direction.size();

			switch (direction[rand_d])
			{
			case Direction::UP:
				Create(&_maze[y - 1][x], MazeWall::ME_WALL);
				Create(&_maze[y - 2][x], MazeWall::ME_WALL);
				y -= 2;
				move_x.push_back(0);
				move_y.push_back(-2);
				std::vector<Direction>().swap(direction);
				ExtendWall(x, y, _maze, move_x, move_y);
				break;
			case Direction::RIGHT:
				Create(&_maze[y][x + 1], MazeWall::ME_WALL);
				Create(&_maze[y][x + 2], MazeWall::ME_WALL);
				x += 2;
				move_x.push_back(2);
				move_y.push_back(0);
				std::vector<Direction>().swap(direction);
				ExtendWall(x, y, _maze, move_x, move_y);
				break;
			case Direction::LEFT:
				Create(&_maze[y][x - 1], MazeWall::ME_WALL);
				Create(&_maze[y][x - 2], MazeWall::ME_WALL);
				x -= 2;
				move_x.push_back(-2);
				move_y.push_back(0);
				std::vector<Direction>().swap(direction);
				ExtendWall(x, y, _maze, move_x, move_y);
				break;
			case Direction::DOWN:
				Create(&_maze[y + 1][x], MazeWall::ME_WALL);
				Create(&_maze[y + 2][x], MazeWall::ME_WALL);
				y += 2;
				move_x.push_back(0);
				move_y.push_back(2);
				std::vector<Direction>().swap(direction);
				ExtendWall(x, y, _maze, move_x, move_y);
				break;
			default:
				break;
			}
		}

	}
	else {
		x -= move_x.back();
		y -= move_y.back();
		move_x.pop_back();
		move_y.pop_back();
		std::vector<Direction>().swap(direction);
		ExtendWall(x, y, _maze, move_x, move_y);
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (_maze[i][j] == (int)MazeWall::ME_WALL) {
				Create(&_maze[i][j], MazeWall::WALL);
			}
		}

	}

	//m_create_direction = NO_D;

	MazeCout(_maze);

	return 0;
}

void MazeCreate::MazeCout(int _maze[height][width]) {

	system("cls");

	for (int y = 0; y < height; y++) {
		std::cout << std::endl;
		for (int x = 0; x < width; x++) {
			switch (_maze[y][x])
			{
			case (int)MazeWall::WALL:
				std::cout << "■";
				break;
			case(int)MazeWall::START:
				std::cout << "＊";
				break;
			case(int)MazeWall::GOOL:
				std::cout << "＠";
				break;
			default:
				std::cout << "　";
				break;
			}
		}
	}
}

bool MazeCreate::ConditionCheck(int width, int height) {
	if (width < 5 || height < 5) {
		return false;
	}
	if (width % 2 == 0)width++;
	if (height % 2 == 0)height++;

	return true;
}

bool MazeCreate::MeWallCheck(int x, int y, int _maze[height][width], std::vector<Direction>& direction) {
	if (_maze[y - 2][x] != (int)MazeWall::ME_WALL) {
		direction.push_back(Direction::UP);
	}
	if (_maze[y][x + 2] != (int)MazeWall::ME_WALL) {
		direction.push_back(Direction::RIGHT);
	}
	if (_maze[y + 2][x] != (int)MazeWall::ME_WALL) {
		direction.push_back(Direction::DOWN);
	}
	if (_maze[y][x - 2] != (int)MazeWall::ME_WALL) {
		direction.push_back(Direction::LEFT);
	}

	if (direction.empty() == false) {
		return true;
	}
	return false;
}

bool MazeCreate::WallCheck(int x, int y, int _maze[height][width]) {
	if (_maze[y - 1][x] == (int)MazeWall::WALL) {
		return false;
	}
	else if (_maze[y][x + 1] == (int)MazeWall::WALL) {
		return false;
	}
	else if (_maze[y + 1][x] == (int)MazeWall::WALL) {
		return false;
	}
	else if (_maze[y][x - 1] == (int)MazeWall::WALL) {
		return false;
	}
	else {
		return true;
	}
}