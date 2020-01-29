#ifndef MAZE_WALL_H_
#define MAZE_WALL_H_

#include <string>
#include <vector>

#include <stdio.h>
#include <iostream>
#include <random>

#include "Main.h"

class Maze
{
public:

	//初期化
	void InitWall();

	void Create();


	//マップの
	static const int width = 13;
	static const int height = 13;

	int map[width * height];


private:

	//終わっているか判断する関数
	bool Finish();
	//ゴールまでが一本道かどうか
	void AGoalPath();
	//閉じた領域がない
	void ClosedArea();
	//ステージの描画
	void DrawMap();
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



	static const int pillar_width = width / 2 + 1;
	static const int pillar_height = height / 2 + 1;


	int pillar[pillar_width * pillar_height];//柱を立てる場所
	//柱を立てはじめ
	int start = 0;

	int player = 12;
	int playerdirection;

	std::mt19937 mt{ std::random_device{}() };

	Direction direction;
};





#endif