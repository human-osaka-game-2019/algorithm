/**
* @file RouteSearch.h
*/

#ifndef ROUTE_SEARCH_H_
#define ROUTE_SEARCH_H_

#include"MazeCreate.h"

/**
* @brief 経路探索に必要なものをまとめたクラス
*/
class Algorithm
{
protected:

	static const int width = 9;
	static const int height = 9;

	int save_gool_x;
	int save_gool_y;

	const int null = 99;

public:

	Algorithm() {}
	virtual ~Algorithm() {}
	/**
	* @brief ゴールの位置を返す関数
	* @param _maze[height][width] 迷路二次元配列
	* @return ゴールをさす配列
	*/
	int GetGool(int _maze[height][width]);
	/**
	* @brief 経路探索用初期化関数
	* @param _maze[height][width] 迷路二次元配列
	*/
	void MazeInitialize(int _maze[height][width]);
};

/**
* @brief ベルマンフォード法による経路探索クラス
*/
class BellmanFord :public Algorithm
{
private:

public:
	BellmanFord() {}
	~BellmanFord() {}
	/**
	* @brief ベルマンフォード法による経路探索関数
	* @note 再起関数
	* @param _maze[height][width] 迷路二次元配列
	*/
	void RouteSearchBellmanFord(int _maze[height][width]);
	/**
	* @brief 距離を更新し、更新されたか否かを返す関数
	* @param _maze1 更新できるか確認したい場所
	* @param _maze2 更新できるか確認したい場所
	* @param cost 距離のコスト
	* @return 更新できたならtrueを返す
	*/
	bool IsUpdatedCost(int* _maze1, int* _maze2, int cost = 1.0);
	/**
	* @brief その地点が壁か否かを返す関数
	* @param 確認したい位置
	* @return 壁でなければtrueを返す
	*/
	bool IsInexistentWall(int _maze);
};

#endif
