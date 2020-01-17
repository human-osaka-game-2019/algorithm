#ifndef ROUTE_SEARCH_H_
#define ROUTE_SEARCH_H_

#include"MazeCreate.h"

class Algorithm
{
protected:

	static const int width = 15;
	static const int height = 15;

	int save_gool_x;
	int save_gool_y;

	const int null = 99;

public:

	Algorithm() {}
	virtual ~Algorithm() {}
	int GetGool(int _maze[height][width]);
	void MazeInitialize(int _maze[height][width]);
};

class Dijkstra :public Algorithm
{
private:

	enum class LoadType
	{
		DeadEnd,//! 行き止まり
		Aisle,	//! 通路
		Fork,	//!分岐路
	};

	enum class Direction
	{
		No,
		Up,
		Left,
		Down,
		Right,
	};

	std::vector<int>save_fork_x;
	std::vector<int>save_fork_y;

public:
	Dijkstra() {}
	~Dijkstra() {}
	/**
	* @brief ダイクストラ法による経路探索用再帰関数
	* @param x 見ているX座標
	* @param y 見ているY座標
	* @param _maze[height][wigth] 迷路の構造体
	* @return 失敗した場合-1、終了すれば0が返る
	*/
	int RouteSearchDijkstra(int x, int y, int _maze[height][width]);

	/**
	* @brief スタート用経路探索関数
	* @param x スタート地点のX座標
	* @param y スタート地点のY座標
	* @param _maze[height][wigth] 迷路の構造体
	* @return 失敗した場合0が返る
	*/
	int RouteSearchDijkstraEx(int x, int y, int _maze[height][width]);

	/**
	* @brief コストを更新できたか確認する用関数
	* @param &_maze1 基準となる値
	* @param &_maze2 更新したい値
	* @param cost 更新するコスト
	*/
	bool IsUpdatedCost(int& _maze1, int& _maze2, int cost = 1.0);

	/**
	* @brief どの方向に進むか確認するための関数（値の更新あり）
	* @param x 中心となるX座標
	* @param y 中心となるY座標
	* @param _maze[height][wigth] 迷路の構造体
	* @return 進む方向、どこにも進めない時はNoが返る
	*/
	Direction GetRouteDirection(int x, int y, int _maze[height][width]);

	/**
	* @brief どの方向に進むか確認するための関数（値の更新なし）
	* @param x 中心となるX座標
	* @param y 中心となるY座標
	* @param _maze[height][wigth] 迷路の構造体
	* @return 進む方向、どこにも進めない時はNoが返る
	*/
	Direction GetRouteDirectionEx(int x, int y, int _maze[height][width], int cost = 1);

	/**
	* @brief 現在の座標が分岐路かどうか確認する関数、分岐路ならばvectorに座標を保存する
	* @note 値を更新できるかで判断しているので、値を更新すると分岐路であっても分岐路扱いではなくなる
	* @param x 中心となるX座標
	* @param y 中心となるY座標
	* @param _maze[height][wigth] 迷路の構造体
	* @return LoadTypeが返る
	*/
	LoadType IsInexistentLoad(int x, int y, int _maze[height][width], int cost = 1);

};
#endif // !ROUTE_SEARCH_H_

