#include "Map.h"

Map::Map()
{
	Initialize();
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

	case 4:

		cout << "Ｎ";
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
			int map_data = Maze[a][b];
			DrawMapData(map_data);
		}

		cout << endl;
	
	}

}

void Map::Initialize()
{
/*	
    for (int a = 0; a < MapSize::Height; a++)
	{
		for (int b = 0; b < MapSize::Width; b++)
		{
			Maze[a][b] = 0;
		}
	}*/

	for (int i = 0; i < MapSize::Height; i++)
	{
		maze[i] = Maze[i];
	}

}