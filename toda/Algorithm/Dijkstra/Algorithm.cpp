#include "Algorithm.h"

void Algorithm::NodeCheck(int* map[], int height, int width)
{
	int Direction = 0;
	int RodeDirection[4] = { 5 };

	for (int a = 0; a < 4; a++)
	{
		switch (Direction)
		{
		case 0:

			if (map[height + 1][width] == 0 || map[height + 1][width] == 4)
			{
				rode.value += 1;
				RodeDirection[rode.value] = 0;
			}

			break;

		case 1:

			if (map[height - 1][width] == 0 || map[height - 1][width] == 4)
			{
				rode.value += 1;
				RodeDirection[rode.value] =1;
			}

			break;

		case 2:

			if (map[height][width + 1] == 0 || map[height][width + 1] == 4)
			{
				rode.value += 1;
				RodeDirection[rode.value] = 2;
			}

			break;

		case 3:

			if (map[height][width - 1] == 0 || map[height][width - 1] == 4)
			{
				rode.value += 1;
				RodeDirection[rode.value] = 3;
			}

			break;
		}

		Direction += 1;
	}

	if (rode.value > 2)
	{
		map[height][width] = 4;
		node[NodeNumber].InputPosition(height, width);
		for (int i = 0; i < 4; i ++)
		{
			if (RodeDirection[i] < 5)
			{
				node[NodeNumber].Distance.push_back(RodeDirection[i]);
			}
		}

		NodeNumber += 1;
	}

	rode.value = 0;
}
