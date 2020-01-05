#ifndef SEARCH_H
#define SEARCH_H

#include "Node.h"
#include "Direction.h"
 
#include  <list>

 struct Road
 {
 	Road() : value(0)
 	{
 	}
 
 	int value;
 };
 
 class Search
 {
 public:

	 void NodeCheck(int* map[], int height, int widht);

	 Direction AdvanceDirection(int* map[], int x, int y);

	 bool IsNode(int* map[], int x, int y);

	 void flow(int* map[],const int x,const int y);

	 int Node確認関数(int* map[], int x, int y);

	 void Move(Direction direction,int x, int y);

	 void NodeDirectionChoice(int node_number);
 private:

	 int NodeNumber = 0;
	 int node_number;
	 int cost = 0;

	 Direction direction;
	 Direction NotDirection = Direction::UnKnown;

	 Road rode;
	 std::vector<Node> node;

 };


#endif
