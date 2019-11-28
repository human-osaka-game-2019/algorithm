#ifndef MAIN_H_
#define MAIN_H_


#include <string>
#include <vector>

#include <stdio.h>
#include <iostream>
#include <random>
//#include <queue>





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








#endif // !MAIN_H_


