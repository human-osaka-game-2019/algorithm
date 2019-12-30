#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
public:

	Node(int y,int x)
	{
		Position[0] = y;
		Position[1] = x;
	}

	void InputPosition(int height, int width);
	std::vector<int> Distance;

private:

	int Position[2];


};

#endif
