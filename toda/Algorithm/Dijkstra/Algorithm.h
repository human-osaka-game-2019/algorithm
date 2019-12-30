#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Map.h"
#include <vector>

enum class Direction
{
	Up,
	Down,
	Right,
	Left
};

struct Road
{
	Road() : value(0)
	{
	}

	int value;
};

class Algorithm
{
public:

	void NodeCheck(int* map[],int height,int widht);


private:

	int NodeNumber = 0;

	Road rode;
	Node node[100];
};


#endif // !ALGORITHM_H
