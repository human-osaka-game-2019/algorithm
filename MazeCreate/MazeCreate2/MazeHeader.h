#ifndef MAZE_HEADER_H_
#define MAZE_HEADER_H_

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<random>
#include<vector>

enum class MazeWall {
	LOAD = -2, 
	WALL,
	START, 
	GOAL,
};

enum class Direction {
	NO_D = -1,
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

	static const int width = 9;
	static const int height = 9;
public:

	void Create(int* _maze, MazeWall maze_wall);
	void MazeCout(int _maze[height][width]);
	void GetRandLoad(int _maze[height][width], RandState* rand_state);
	int ExtendLoad(int x, int y, int _maze[height][width], std::vector<int>& move_x, std::vector<int>& move_y);
	bool ConditionCheck(int width, int height);
	bool LoadCheck(int x, int y, int _maze[height][width], std::vector<Direction>& direction);
};


#endif
