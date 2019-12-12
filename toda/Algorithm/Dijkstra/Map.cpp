#include "Map.h"

Map::Map()
{
	// Initialize();
}

Map::~Map()
{

}

void Map::DrawMapData(int MapData)
{
	switch (MapData)
	{
	case 0:
		
		cout << "　";
		break;

	case 1:

		cout << "■";
		break;

	case 2:
		
		cout << "Ｓ" ;
		break;

	case 3:

		cout << "Ｇ" ;
		break;

	default:
		break;

	}
}

void Map::Show()
{
	for (int a = 0; a < MapSize::Height; a++)
	{
		for (int b = 0; b < MapSize::Width; b++)
		{
			DrawMapData(Maze[a][b]);
		}

		cout << endl;
	
	}

}

void Map::Initialize()
{
	for (int a = 0; a < MapSize::Height; a++)
	{
		for (int b = 0; b < MapSize::Width; b++)
		{
			Maze[a][b] = 0;
		}
	}

}