
#include "Dijkstra.h"
//
//void Maze::InitWall()
//{
//	//初期化ステージ
//	for (int i = 0; i < width * height; i++)
//	{
//		map[i] = 0;
//	}
//
//	int count_ = 0;
//
//	//初期化柱
//	for (int i = 0; i < width * height; i++)
//	{
//		if ((i / width) % 2 == 0)
//		{
//			if (i % 2 == 0)
//			{
//				pillar[count_] = i;
//				count_++;
//			}
//		}
//	}
//	for (int i = 0; i < pillar_width * pillar_height; i++)
//	{
//		if ((0 <= i && i <= pillar_width - 1) || (pillar_width * pillar_height - pillar_width <= i && i <= pillar_width * pillar_height) || (i % pillar_width == 0) || (i % pillar_width == pillar_width - 1))
//		{
//			pillar[i] = Wall;
//		}
//	}
//
//	for (int i = 0; i < width * height; i++)
//	{
//		if ((0 <= i && i <= width - 1) || (width * height - width <= i && i <= width * height) || (i % width == 0) || (i % width == width - 1))
//		{
//			map[i] = Wall;
//		}
//	}
//
//	for (int i = 0; i < pillar_width * pillar_height; i++)
//	{
//		if (pillar[i] != Wall)
//		{
//			map[pillar[i]] = Wall;
//		}
//	}
//
//
//	//1列目
//	map[15] = Wall;
//	//2列目
//	map[29] = Wall;
//	map[31] = Wall;
//	map[33] = Wall;
//	map[35] = Wall;
//	//3列目
//	map[41] = Wall;
//	map[45] = Wall;
//	map[47] = Wall;
//	//4列目
//	map[55] = Wall;
//	map[61] = Wall;
//	//5列目
//	map[67] = Wall;
//	map[69] = Wall;
//	//6列目
//	map[83] = Wall;
//	map[85] = Wall;
//	map[89] = Wall;
//	//7列目
//	map[97] = Wall;
//	//8列目	
//	map[105] = Wall;
//	map[109] = Wall;
//	map[113] = Wall;
//	//9列目	
//	map[119] = Wall;
//	map[127] = Wall;
//	//10列目
//	map[133] = Wall;
//	map[137] = Wall;
//	map[141] = Wall;
//	//11列目	
//	map[151] = Wall;
//
//
//	//ゴール
//	map[16] = Goal;
//
//}

void Maze::DrawMap(int wall[])
{
	int everything = width * height;

	for (int i = 0; i < everything; i++)
	{
		if (wall[i] == Path)
		{
			printf("　");
			//cout << "□" << ends;
		}
		else if (wall[i] == Wall)
		{
			printf("■");
			//cout << "■" << ends;
		}
		else if (wall[i] == Start)
		{
			printf("Ｓ");
		}
		else if (wall[i] == Goal)
		{
			printf("Ｇ");
		}


		if ((i + 1) % width == 0)
		{
			cout << endl;
		}
	}
}


void Maze::ExpandComplete()
{
	for (int i = 0; i < pillar_width * pillar_height; i++)
	{
		if (pillar[i] == Expanding)
		{
			pillar[i] = Expanded;
		}
	}
}

void Maze::ExpandWall()
{
	switch (direction)
	{
	case UP:
		for (int i = 0; i < 3; i++)
		{
			map[pillar[start] - (i * width)] = Wall;
		}

		pillar[start] = Expanding;

		if (pillar[start - pillar_width] == Expanding)
		{
			start -= pillar_width;
		}

		break;

	case DOWN:
		for (int i = 0; i < 3; i++)
		{
			map[pillar[start] + (i * width)] = Wall;
		}

		pillar[start] = Expanding;

		if (pillar[start + pillar_width] == Expanding)
		{
			start += pillar_width;
		}

		break;

	case RIGHT:
		for (int i = 0; i < 3; i++)
		{
			map[pillar[start] + i] = Wall;
		}

		pillar[start] = Expanding;

		if (pillar[start + 1] == Expanding)
		{
			start += 1;
		}

		break;

	case LEFT:
		for (int i = 0; i < 3; i++)
		{
			map[pillar[start] - i] = Wall;
		}

		pillar[start] = Expanding;

		if (pillar[start - 1] == Expanding)
		{
			start -= 1;
		}

		break;
	}
}

void Maze::InitWall()
{
	//初期化ステージ
	for (int i = 0; i < width * height; i++)
	{
		map[i] = 0;
	}

	int count_ = 0;

	//初期化柱
	for (int i = 0; i < width * height; i++)
	{
		if ((i / width) % 2 == 0)
		{
			if (i % 2 == 0)
			{
				pillar[count_] = i;
				count_++;
			}
		}
	}
	for (int i = 0; i < pillar_width * pillar_height; i++)
	{
		if ((0 <= i && i <= pillar_width - 1) || (pillar_width * pillar_height - pillar_width <= i && i <= pillar_width * pillar_height) || (i % pillar_width == 0) || (i % pillar_width == pillar_width - 1))
		{
			pillar[i] = Expanded;
		}
	}

	for (int i = 0; i < width * height; i++)
	{
		if ((0 <= i && i <= width - 1) || (width * height - width <= i && i <= width * height) || (i % width == 0) || (i % width == width - 1))
		{
			map[i] = Wall;
		}
	}
}


int Maze::SearchDirction(int wall, int direction)
{
	switch (direction)
	{
	case UP:

		return wall - (2 * width);

		break;

	case DOWN:

		return wall + (2 * width);

		break;

	case RIGHT:

		return wall + 2;

		break;

	case LEFT:

		return wall - 2;

		break;
	}
}

bool Maze::Finish()
{
	int count = 0;

	for (int i = 0; i < pillar_width * pillar_height; i++)
	{
		if (pillar[i] == -1)
		{
			count++;
		}
	}

	if (count == pillar_width * pillar_height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Maze::RandomDirection()
{
	std::uniform_int_distribution<int>randomdirection(0, 3);
	direction = (Direction)randomdirection(mt);
}

void Maze::RandomStart()
{
	std::uniform_int_distribution<int>randompillar(0, pillar_width * pillar_height - 1);
	start = (int)randompillar(mt);
}

void Maze::RandomStartPoint()
{
	std::uniform_int_distribution<int>randomstartpoint(0,width * height);
	start_point = (int)randomstartpoint(mt);
}

void Maze::RandomGoalPoint()
{
	std::uniform_int_distribution<int>randomgoalpoint(0, width * height);
	goal_point = (int)randomgoalpoint(mt);
}

void Maze::MakeStart()
{

	
	map[width + 1] = Start;
	/*while (true)
	{
		RandomStartPoint();
		if (map[start_point] == Path)
		{
			map[start_point] = Start;
			break;
		}
	}*/
}


void Maze::MakeGoal()
{
	map[width * height -width - 2] = Goal;
	/*while(true) {
		RandomGoalPoint();
		if (map[goal_point] == Path)
		{
			map[goal_point] = Goal;
			break;
		}
	}*/
}



int Maze::GetStart()
{
	for (int cell:map)
	{
		if (cell == Start)
		{
			return cell;
		}
	}
}


