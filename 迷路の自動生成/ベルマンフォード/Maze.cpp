#include "Maze.h"

void Maze::Create()
{
	while (true)
	{

		RandomDirection();

		if (pillar[start] == Expanded)
		{
			RandomStart();
			continue;
		}

		ExpandWall();


		if (pillar[start] == Expanding)
		{
			ExpandComplete();
		}



		//終了
		if (Finish() == true)
		{
			break;
		}

		//画面クリア
		std::system("cls");

		//描画
		DrawMap();
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


void Maze::DrawMap()
{
	int everything = width * height;

	for (int i = 0; i < everything; i++)
	{
		if (map[i] == Path)
		{
			printf("\033[0m");
			printf("　");
			//cout << "□" << ends;
		}
		else if (map[i] == Wall)
		{
			printf("\033[33m");
			printf("■");
			//cout << "■" << ends;
		}
		else if (map[i] == Start)
		{
			printf("Ｓ");
		}
		else if (map[i] == Goal)
		{
			printf("Ｇ");
		}
		if ((i + 1) % width == 0)
		{
			std::cout << std::endl;
		}
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