#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Map.h"
#include "Node.h"
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
	std::vector<Node> node;
};


#endif // !ALGORITHM_H
