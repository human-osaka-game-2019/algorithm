#include "Node.h"

void Node::InputPosition(int height, int width)
{

	Position[0] = height;
	Position[1] = width;

}

void Node::Show()
{
	std::cout << "所持方向 : ";

	for (Direction i : SearchDirection)
	{
		switch (i)
		{
		case Direction::Down:
			std::cout << "下 ";
			break;
		case Direction::Up:
			std::cout << "上 ";
			break;
		case Direction::Right:
			std::cout << "右 ";
			break;
		case Direction::Left:
			std::cout << "左 ";
			break;
		default:
			break;
		}
	}

	std::cout << std::endl;

	std::cout << "Node場所 : " << Position[0] << " " << Position[1] << std::endl;
	std::cout << std::endl;
}

void Node::DeleteRoadDirection(Direction deleteDirection)
{
	for (auto it = SearchDirection.begin(); it != SearchDirection.end();) {
		// 条件一致した要素を削除する
		if (*it == deleteDirection) {
			// 削除された要素の次を指すイテレータが返される。
			it = SearchDirection.erase(it);
		}
		// 要素削除をしない場合に、イテレータを進める
		else {
			++it;
		}
	}
}