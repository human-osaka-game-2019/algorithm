#ifndef EXTEND_WALL_H_
#define EXTEND_WALL_H_

#include <string>
#include <vector>

#include <stdio.h>
#include <iostream>
#include <random>

using namespace std;

class Maze
{
public:
	
	//方向
	enum Direction
	{
		//上
		UP,
		//下
		DOWN,
		//右
		RIGHT,
		//左
		LEFT
	};

	enum PillarState
	{
		//拡張
		Expanding = -2,
		//拡張済み
		Expanded,
	};

	//
	enum MapState
	{
		//道
		Path,
		//壁
		Wall,
		//ゴール
		Goal,
		//スタート
		Start,
	};

	
	//初期化
	void InitWall();
	//終わっているか判断する関数
	bool Finish();
	//ゴールまでが一本道かどうか
	void AGoalPath();
	//閉じた領域がない
	void ClosedArea();
	//ステージの描画
	void DrawMap(int wall[]);
	//拡張中の壁にする
	void ExpandWall();
	//方向をランダムにする関数
	void RandomDirection();
	//拡張を完了する関数
	void ExpandComplete();
	//壁を作る
	void MakeWall();
	//作りはじめをランダムにする関数
	void RandomStart();



	//方向を見て
	int SearchDirction(int wall, int direction);
	
	//マップの
	static const int width = 13;
	static const int height = 13;

	static const int pillar_width = width / 2 + 1;
	static const int pillar_height = height / 2 + 1;

	int map[width * height];

	int pillar[pillar_width * pillar_height];//柱を立てる場所
	//柱を立てはじめ
	int start = 0;

	int player = 12;
	int playerdirection;

	std::mt19937 mt{ std::random_device{}()};

	Maze::Direction direction;





	//void Draw(int col, int row, vector<string> wall);
	//void WallChange(int x);
	//vector<string> wall;

	
};





#endif