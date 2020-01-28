#ifndef SEARCH_H
#define SEARCH_H

#include "Node.h"
#include "Direction.h"
 
#include  <list>

/**
 roadの情報を持ったクラス
 */
 struct Road
 {
 	Road() : value(0)
 	{
 	}
 
 	int value;
 };
 
 /**
 最短経路をだすクラス
 */
 class Search
 {
 public:

	 /**
	  * nodeかになる存在かどうかの確認関数
	  * @param int* map[] マップのポインタ
	  * @param int height マップの高さ
	  * @param int widht マップの幅
	  */
	 void NodeCheck(int* map[], int height, int widht);

	 /**
	  * 進める方向の確認関数
	  * @param int* map[] マップのポインタ
	  * @param int x 現在のX座標
	  * @param int y 現在のY座標
	  * @return 進める方向を 型(Direction) で返す 
	  */
	 Direction AdvanceDirection(int* map[], int x, int y);

	 /**
	  * nodeに着いたかの確認関数
	  * @param int* map[] マップのポインタ
	  * @param int x 現在のX座標
	  * @param int y 現在のY座標
	  * @return Nodeであれば ture を返す
	  */
	 bool IsNode(int* map[], int x, int y);

	 /**
	  * メインの回している関数
	  * @param int* map[] マップのポインタ
	  * @param const int x	初期のX座標
	  * @param const int y	初期のY座標
	  */
	 void flow(int* map[],const int x,const int y);

	 /**
	  * どのNodeかの確認関数
	  * @param int* map[] マップのポインタ
	  * @param int x 現在のX座標
	  * @param int y 現在のY座標
	  */
	 int CheckNodeNumber(int* map[], int x, int y);

	 /**
	  * 内部の座標を動かす関数
	  * @param Direction direction 動く方向
	  */
	 void Move(Direction direction);

	 /**
	  * Nodeが保持している方向を方向変数に代入する関数
	  * @param int node_number どのnodeかの番号
	  */
	 void NodeDirectionChoice(int node_number);

 private:
	 
	 //! X座標の変数
	 int X;
	 //! Y座標の変数
	 int Y;

	 //! どのnodeかの番号を付ける為の変数
	 int NodeNumber = 0;

	 //! どのnodeかの番号を付ける変数
	 int node_number;
	 
	 //! Nodeのcostを保持する変数
	 int cost = 0;

	 //! ループの回数をカウントする為の変数
	 int count = 0;

	 //! 経路のnodeの番号を保持する配列
	 std::vector<int> Course;

	 //! enum の class のインスタンス
	 Direction direction;
	 
	 //! 進んではいけない方向を保持する変数
	 Direction NotDirection = Direction::UnKnown;

	 //! rodeのインスタンス
	 Road road;
	
	 //! Nodeのインスタンスの配列
	 std::vector<Node> node;

 };


#endif
