#ifndef Route_H_
#define Route_H_

#include "Main.h"


using namespace std;




class Maze
{
public:



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
	//スタートの位置をランダムでとってくる関数
	void RandomStartPoint();
	//ゴールの位置をランダムでとってくる関数
	void RandomGoalPoint();
	//スタート地点の生成
	void MakeStart();
	//ゴール地点の生成
	void MakeGoal();


	int GetStart();


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

	std::mt19937 mt{ std::random_device{}() };

	Direction direction;

	int start_point = 0;
	int goal_point = 0;

	vector<int>multiple_direction_nodes;

};





#endif