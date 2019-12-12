#include"MazeHeader.h"

void MazeCreate::GetRandLoad(int _maze[height][width], RandState* rand_state) {
	std::mt19937 mt;
	std::random_device rnd;
	mt.seed(rnd());

		rand_state->rand_y = mt() % (height - 1) + 1;
		rand_state->rand_x = mt() % (width - 1) + 1;
		if (rand_state->rand_y % 2 == 0)
			++rand_state->rand_y;

		if (rand_state->rand_x % 2 == 0)
			++rand_state->rand_x;

		Create(&_maze[rand_state->rand_y][rand_state->rand_x], MazeWall::LOAD);
}

void MazeCreate::Create(int* _maze, MazeWall maze_wall) {

	switch (maze_wall)
	{
	case MazeWall::LOAD:
		*_maze = (int)MazeWall::LOAD;
		break;
	case MazeWall::WALL:
		*_maze = (int)MazeWall::WALL;
		break;
	case MazeWall::START:
		*_maze = (int)MazeWall::START;
		break;
	case MazeWall::GOAL:
		*_maze = (int)MazeWall::GOAL;
		break;
	default:
		break;
	}
}

int MazeCreate::ExtendLoad(int x, int y, int _maze[height][width], std::vector<int>& move_x, std::vector<int>& move_y)
{

	std::vector<Direction>direction;

	if (LoadCheck(x, y, _maze, direction) == true) {

		std::mt19937 mt;           
		std::random_device rnd;     
		mt.seed(rnd());

		int rand_direction = mt() % direction.size();

			switch (direction[rand_direction])
			{
			case Direction::UP:
				Create(&_maze[y - 1][x], MazeWall::LOAD);
				Create(&_maze[y - 2][x], MazeWall::LOAD);
				y -= 2;
				move_x.push_back(0);
				move_y.push_back(-2);
				std::vector<Direction>().swap(direction);
				ExtendLoad(x, y, _maze, move_x, move_y);
				break;
			case Direction::RIGHT:
				Create(&_maze[y][x + 1], MazeWall::LOAD);
				Create(&_maze[y][x + 2], MazeWall::LOAD);
				x += 2;
				move_x.push_back(2);
				move_y.push_back(0);
				std::vector<Direction>().swap(direction);
				ExtendLoad(x, y, _maze, move_x, move_y);
				break;
			case Direction::LEFT:
				Create(&_maze[y][x - 1], MazeWall::LOAD);
				Create(&_maze[y][x - 2], MazeWall::LOAD);
				x -= 2;
				move_x.push_back(-2);
				move_y.push_back(0);
				std::vector<Direction>().swap(direction);
				ExtendLoad(x, y, _maze, move_x, move_y);
				break;
			case Direction::DOWN:
				Create(&_maze[y + 1][x], MazeWall::LOAD);
				Create(&_maze[y + 2][x], MazeWall::LOAD);
				y += 2;
				move_x.push_back(0);
				move_y.push_back(2);
				std::vector<Direction>().swap(direction);
				ExtendLoad(x, y, _maze, move_x, move_y);
				break;
			default:
				break;
			}
	}
	else if (move_x.empty() == false && move_y.empty() == false) {
		x -= move_x.back();
		y -= move_y.back();
		move_x.pop_back();
		move_y.pop_back();
		std::vector<Direction>().swap(direction);
		ExtendLoad(x, y, _maze, move_x, move_y);
	}

	//m_create_direction = NO_D;

	MazeCout(_maze);

	std::vector<Direction>().swap(direction);

	return 0;
}

void MazeCreate::MazeCout(int _maze[height][width]) {

	system("cls");

	for (int y = 0; y < height; y++) {
		std::cout << std::endl;
		for (int x = 0; x < width; x++) {
			switch (_maze[y][x])
			{
			case (int)MazeWall::LOAD:
				std::cout << "　";
				break;
			case (int)MazeWall::START:
				std::cout << "＊";
				break;
			case (int)MazeWall::GOAL:
				std::cout << "＠";
				break;
			case (int)MazeWall::WALL:
				std::cout << "■";
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

bool MazeCreate::LoadCheck(int x, int y, int _maze[height][width], std::vector<Direction>& direction) {
	if (_maze[y - 1][x] == (int)MazeWall::WALL && _maze[y - 2][x] == (int)MazeWall::WALL) {
		direction.push_back(Direction::UP);
	}

	if (_maze[y][x + 1] == (int)MazeWall::WALL && _maze[y][x + 2] == (int)MazeWall::WALL) {
		direction.push_back(Direction::RIGHT);
	}

	if (_maze[y + 1][x] == (int)MazeWall::WALL && _maze[y + 2][x] == (int)MazeWall::WALL) {
		direction.push_back(Direction::DOWN);
	}

	if (_maze[y][x - 1] == (int)MazeWall::WALL && _maze[y][x - 2] == (int)MazeWall::WALL) {
		direction.push_back(Direction::LEFT);
	}

	if (direction.empty() == false) {
		return true;
	}
	return false;
}
