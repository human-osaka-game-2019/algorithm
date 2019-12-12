#ifndef MAP_H
#define MAP_H

#include <iostream>

using std::cout;
using std::endl;

namespace MapSize
{
	const int Width = 11;
	const int Height = 11;
}

class Map
{
public:

	Map();

	~Map();

	int Maze[MapSize::Height][MapSize::Width] = 
	{
		{1,1,1,1,1,1,1,1,1,1,1},
	    {1,2,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,3,1},
	    {1,1,1,1,1,1,1,1,1,1,1}
	
	};

	void Show();


private:

	void Initialize();

	void DrawMapData(int MapDate);
};

#endif
