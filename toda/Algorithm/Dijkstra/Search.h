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

	 void Move(Direction direction);

	 void NodeDirectionChoice(int node_number);
 private:

	 int X;
	 int Y;

	 int NodeNumber = 0;
	 int node_number;
	 int cost = 0;

	 int count = 0;

	 std::vector<int> Course;

	 std::vector<int> SearchList;
	 std::vector<int> NodeList;

	 Direction direction;
	 Direction NotDirection = Direction::UnKnown;

	 Road road;
	 std::vector<Node> node;

 };


#endif
