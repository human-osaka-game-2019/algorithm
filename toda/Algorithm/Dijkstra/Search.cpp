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
				rode.value += 1;
				RodeDirection[rode.value] = Direction::Down;
			}

			break;

		case 1: // Up

			if (map[height - 1][width] == 0 || map[height - 1][width] == 4)
			{
				rode.value += 1;
				RodeDirection[rode.value] = Direction::Up;
			}

			break;

		case 2: // Right

			if (map[height][width + 1] == 0 || map[height][width + 1] == 4)
			{
				rode.value += 1;
				RodeDirection[rode.value] = Direction::Right;
			}

			break;

		case 3: // Left

			if (map[height][width - 1] == 0 || map[height][width - 1] == 4)
			{
				rode.value += 1;
				RodeDirection[rode.value] = Direction::Left;
			}

			break;
		}

		direction += 1;
	}

	if (rode.value > 2)
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

	rode.value = 0;
}


Direction Search::AdvanceDirection(int* map[], int x, int y)
{

	if (NotDirection != Direction::Up && (map[y - 1][x] == 0 || map[y - 1][x] == 4))
	{
		NotDirection = Direction::Down;
		return Direction::Up;
	}
	else if (NotDirection != Direction::Down && (map[y + 1][x] == 0 || map[y + 1][x] == 4))
	{
		NotDirection = Direction::Up;
		return Direction::Down;
	}
	else if (NotDirection != Direction::Left && (map[y][x - 1] == 0 || map[y][x - 1] == 4))
	{
		NotDirection = Direction::Right;
		return Direction::Left;
	}
	else if (NotDirection != Direction::Right && (map[y][x + 1] == 0 || map[y][x + 1] == 4))
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

void Search::Move(Direction direction,int x, int y)
{
	switch (direction)
	{
	case Direction::Up:
		y -= 1;
		break;
	case Direction::Down:
		y += 1;
		break;
	case Direction::Right:
		x += 1;
		break;
	case Direction::Left:
		x -= 1;
		break;
	default:
		break;
	}

}

void Search::NodeDirectionChoice(int node_number)
{
	direction = node[node_number].SearchDirection[0];

	std::size_t size = node[node_number].SearchedDirection.size;

	for (int i = 0; i < size; i++)
	{
		if ( direction != node[node_number].SearchedDirection[i])
		{
			direction = Direction::UnKnown;
			break;
		}

	}

}









void Search::flow(int* map[],const int Start_x,const int Start_y)
{
	int X = Start_x;
	int Y = Start_y;
	bool NodeCheckFlag;

	while (true)
	{

		// nodeに着いたら
		if (IsNode(map, X, Y) == true)
		{
			// どのnode か区別
			node_number = Node確認関数(map, X, Y);

			if (direction != Direction::UnKnown)
			{
				// node の保持している進める方向の情報を消す(到着した方向)
				node[node_number].SearchedDirection.push_back(direction);
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
			Move(direction, X, Y);
		}

	}

}