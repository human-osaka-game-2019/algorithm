#ifndef MAZE_CREATE_H_
#define MAZE_CREATE_H_

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<random>
#include<vector>

enum class MazeWall {
	NO,
	WALL,
	ME_WALL,
	SEED,
	START,
	GOOL,
};

enum class Direction {
	NO_Direction = -1,
	UP,
	RIGHT,
	DOWN,
	LEFT,
};

typedef struct {
	int rand_x = 0;
	int rand_y = 0;
}RandState;

class MazeCreate {
private:

	int m_seed_count = 0;
	int m_create_count = 0;

	static const int width = 15;
	static const int height = 15;

public:

	int GetSeedCount();
	int GetCreateCount();
	int ExtendWall(int x, int y, int _maze[height][width], std::vector<int>& move_x, std::vector<int>& move_y);
	void MinusCreateCount();
	void GetRandSeed(int _maze[height][width], RandState* rand_state);
	void PlusSeedCount();
	void MinusSeedCount();
	void Create(int* _maze, MazeWall maze_wall);
	void MazeCout(int _maze[height][width]);
	bool ConditionCheck(int width, int height);
	bool MeWallCheck(int x, int y, int _maze[height][width], std::vector<Direction>& direction);
	bool WallCheck(int x, int y, int _maze[height][width]);
};

#endif // !HEADER_H_

