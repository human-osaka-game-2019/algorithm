#include "Search.h"

void Search::NodeCheck(int* map[], int height, int width)
{
	int direction = 0;
	Direction RodeDirection[4] = { Direction::UnKnown };

	for (int a = 0; a < 4; a++)
	{
		switch (direction)
		{
		case 0: // Down

			if (map[height + 1][width] == 0 || map[height + 1][width] == 4)
			{
				road.value += 1;
				RodeDirection[road.value] = Direction::Down;
			}

			break;

		case 1: // Up

			if (map[height - 1][width] == 0 || map[height - 1][width] == 4)
			{
				road.value += 1;
				RodeDirection[road.value] = Direction::Up;
			}

			break;

		case 2: // Right

			if (map[height][width + 1] == 0 || map[height][width + 1] == 4)
			{
				road.value += 1;
				RodeDirection[road.value] = Direction::Right;
			}

			break;

		case 3: // Left

			if (map[height][width - 1] == 0 || map[height][width - 1] == 4)
			{
				road.value += 1;
				RodeDirection[road.value] = Direction::Left;
			}

			break;
		}

		direction += 1;
	}

	if (road.value > 2)
	{
		map[height][width] = 4;

		node.emplace_back(height, width);

		for (int i = 0; i < 4; i++)
		{
			if (RodeDirection[i] != Direction::UnKnown)
			{
				node[NodeNumber].SearchDirection.push_back(RodeDirection[i]);
			}
		}
		
		// TODO : 仮置き
		node[NodeNumber].Show();

		NodeNumber += 1;
	}

	road.value = 0;
}


Direction Search::AdvanceDirection(int* map[], int x, int y)
{

	if (NotDirection != Direction::Up && (map[y - 1][x] == 0 || map[y - 1][x] == 4 || map[y - 1][x] == 3))
	{
		NotDirection = Direction::Down;
		return Direction::Up;
	}
	else if (NotDirection != Direction::Down && (map[y + 1][x] == 0 || map[y + 1][x] == 4 || map[y + 1][x] == 3))
	{
		NotDirection = Direction::Up;
		return Direction::Down;
	}
	else if (NotDirection != Direction::Left && (map[y][x - 1] == 0 || map[y][x - 1] == 4 || map[y][x - 1] == 3))
	{
		NotDirection = Direction::Right;
		return Direction::Left;
	}
	else if (NotDirection != Direction::Right && (map[y][x + 1] == 0 || map[y][x + 1] == 4 || map[y][x + 1] == 3))
	{
		NotDirection = Direction::Left;
		return Direction::Right;
	}

	return Direction::Stop;

}

bool Search::IsNode(int* map[], int x, int y)
{
	if (map[y][x] == 4)
	{
		return true;
	}

	return false;
}

int Search::Node確認関数(int* map[], int x, int y)
{
	int size = node.size();

	for (int i = 0; i < size; i++)
	{
		int node_position_x = node[i].Position[1];
		int node_position_y = node[i].Position[0];

		if (node_position_y == y)
		{
			if (node_position_x == x)
			{
				return i;
			}
		}
	}

	return -1;
}

void Search::Move(Direction direction)
{
	switch (direction)
	{
	case Direction::Up:
		Y -= 1;
		break;
	case Direction::Down:
		Y += 1;
		break;
	case Direction::Right:
		X += 1;
		break;
	case Direction::Left:
		X -= 1;
		break;
	default:
		break;
	}

}

void Search::NodeDirectionChoice(int node_number)
{
	direction = node[node_number].SearchDirection[0];

	switch (direction)
	{
	case Direction::Up:
		NotDirection = Direction::Down;
		break;
	case Direction::Down:
		NotDirection = Direction::Up;
		break;
	case Direction::Right:
		NotDirection = Direction::Left;
		break;
	case Direction::Left:
		NotDirection = Direction::Right;
		break;
	default:
		NotDirection = Direction::UnKnown;
		break;
	}

	node[node_number].DeleteRoadDirection(direction);


}









void Search::flow(int* map[],const int Start_x,const int Start_y)
{
	X = Start_x;
	Y = Start_y;
	bool NodeCheckFlag;

	while (count < 200)
	{
		count++;
		// nodeに着いたら
		if (IsNode(map, X, Y) == true)
		{
			// どのnode か区別
			node_number = Node確認関数(map, X, Y);

			if (Course.empty() == true || Course.back() != node_number)
			{
				Course.push_back(node_number);
			}


			if (direction != Direction::UnKnown)
			{
				// node の保持している進める方向の情報を消す(進んでいる方向の逆)
				node[node_number].DeleteRoadDirection(NotDirection);
			}



			// nodeの方向を算出する関数
			NodeDirectionChoice(node_number);

			// node のcost を設定
			if (node[node_number].cost == 0)
			{
				node[node_number].cost = cost;
				cost = 0;
			}
		}
		else
		{
			direction = AdvanceDirection(map, X, Y);
		}

		// 行き止まりの場合
		if (direction == Direction::Stop)
		{
			// 一つ前のnodeに戻る
			int node_pos_x = node[node_number].Position[1];
			int node_pos_y = node[node_number].Position[0];

			// 行き止まりの場合ひとつ前のnodeに戻る
			X = node_pos_x;
			Y = node_pos_y;

			direction = Direction::UnKnown;

			// 1costも初期値に
			cost = 0;

		}
		else
		{
			cost += 1;

			// 移動関数
			Move(direction);
		}

		if (map[X][Y] == 3)
		{
			int Coust = 0;

			std::cout << "node順は ";
			for (auto number : Course)
			{
				Coust += node[number].cost;

				std::cout << " " << number << " ";
			}

			std::cout << std::endl;

			Coust += cost;

			std::cout << "最短経路は : " << Coust << std::endl;

			break;
		}

	}

}
