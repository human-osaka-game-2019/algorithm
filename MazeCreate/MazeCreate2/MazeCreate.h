/**
* @file MazeCreate.h
*/

#ifndef MAZE_CREATE_H_
#define MAZE_CREATE_H_

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<random>
#include<vector>

/**
* @enum MazeWall
*/
enum class MazeWall {
	//!何もない通路
	NO = -4,
	//!壁
	WALL,
	//!現在伸ばしている壁
	ME_WALL,
	//!壁伸ばし開始点
	SEED,
	//!迷路のスタート地点
	START,
	//!迷路のゴール地点
	GOAL,
};

/**
* @enum Direction
*/
enum class Direction {
	//!方向なし
	NO_Direction = -1,
	//!上
	UP,
	//!右
	RIGHT,
	//!下
	DOWN,
	//!左
	LEFT,
};

/**
* @brief 伸ばしたいSEEDの位置記憶用
*/
typedef struct {
	int rand_x = 0;
	int rand_y = 0;
}RandState;

/**
* @brief 迷路生成用
*/
class MazeCreate {
private:

	int m_seed_count = 0;
	int m_create_count = 0;

	static const int width = 9;
	static const int height = 9;

public:

	/**
	* @brief 壁をのばす種の個数を返す関数
	* @return SEEDの数
	*/
	int GetSeedCount();
	/**
	* @brief 壁をのばす関数
	* @note 再起関数
	* @param x 現在のx座標
	* @param y 現在のy座標
	* @param _maze[height][width] 迷路二次元配列
	* @param move_x 移動順記憶用vector
	* @param move_y 移動順記憶用vector
	* @return 終了した時0が返る
	*/
	int ExtendWall(int x, int y, int _maze[height][width], std::vector<int>& move_x, std::vector<int>& move_y);
	/**
	* @brief ランダムなSEEDを取り出す関数
	* @param _maze[height][width] 迷路二次元配列
	* @param rand_state 取り出したSEEDの座標を記憶する構造体
	*/
	void GetRandSeed(int _maze[height][width], RandState* rand_state);
	/**
	* @brief 記憶しているSEEDの数を足す関数
	*/
	void PlusSeedCount();
	/**
	* @brief 記憶しているSEEDの数を引く関数
	*/
	void MinusSeedCount();
	/**
	* @brief 指定した位置の中身を変える関数
	* @param _maze 変えたい位置
	* @param maze_wall 何に変えたいか指定する
	*/
	void Create(int* _maze, MazeWall maze_wall);
	/**
	* @brief 迷路を表示する関数
	* @param _maze[height][width] 迷路二次元配列
	*/
	void MazeCout(int _maze[height][width]);
	/**
	* @brief 指定した高さ、幅が迷路生成の条件にあっているかを確認する関数
	* @param width 幅
	* @param height 高さ
	* @return 条件を満たしていればtrueを返す
	*/
	bool ConditionCheck(int width, int height);
	/**
	* @brief 自分が現在伸ばしている壁かを返す関数
	* @param x 現在のx座標
	* @param y 現在のy座標
	* @param _maze[height][width] 迷路二次元配列
	* @param direction 方向記憶用vector
	* @return ME_WALLと接していればfalseを返す
	*/
	bool MeWallCheck(int x, int y, int _maze[height][width], std::vector<Direction>& direction);
	/**
	* @brief 四方を見て壁が接しているか確認する関数
	* @param x 現在のx座標
	* @param y 現在のy座標
	* @param _maze[height][width] 迷路二次元配列
	* @return 壁と接していればfalseを返す
	*/
	bool WallCheck(int x, int y, int _maze[height][width]);
};

#endif // !HEADER_H_
