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
		DeadEnd,//! �s���~�܂�
		Aisle,	//! �ʘH
		Fork,	//!����H
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
	* @brief �_�C�N�X�g���@�ɂ��o�H�T���p�ċA�֐�
	* @param x ���Ă���X���W
	* @param y ���Ă���Y���W
	* @param _maze[height][wigth] ���H�̍\����
	* @return ���s�����ꍇ-1�A�I�������0���Ԃ�
	*/
	int RouteSearchDijkstra(int x, int y, int _maze[height][width]);

	/**
	* @brief �X�^�[�g�p�o�H�T���֐�
	* @param x �X�^�[�g�n�_��X���W
	* @param y �X�^�[�g�n�_��Y���W
	* @param _maze[height][wigth] ���H�̍\����
	* @return ���s�����ꍇ0���Ԃ�
	*/
	int RouteSearchDijkstraEx(int x, int y, int _maze[height][width]);

	/**
	* @brief �R�X�g���X�V�ł������m�F����p�֐�
	* @param &_maze1 ��ƂȂ�l
	* @param &_maze2 �X�V�������l
	* @param cost �X�V����R�X�g
	*/
	bool IsUpdatedCost(int& _maze1, int& _maze2, int cost = 1.0);

	/**
	* @brief �ǂ̕����ɐi�ނ��m�F���邽�߂̊֐��i�l�̍X�V����j
	* @param x ���S�ƂȂ�X���W
	* @param y ���S�ƂȂ�Y���W
	* @param _maze[height][wigth] ���H�̍\����
	* @return �i�ޕ����A�ǂ��ɂ��i�߂Ȃ�����No���Ԃ�
	*/
	Direction GetRouteDirection(int x, int y, int _maze[height][width]);

	/**
	* @brief �ǂ̕����ɐi�ނ��m�F���邽�߂̊֐��i�l�̍X�V�Ȃ��j
	* @param x ���S�ƂȂ�X���W
	* @param y ���S�ƂȂ�Y���W
	* @param _maze[height][wigth] ���H�̍\����
	* @return �i�ޕ����A�ǂ��ɂ��i�߂Ȃ�����No���Ԃ�
	*/
	Direction GetRouteDirectionEx(int x, int y, int _maze[height][width], int cost = 1);

	/**
	* @brief ���݂̍��W������H���ǂ����m�F����֐��A����H�Ȃ��vector�ɍ��W��ۑ�����
	* @note �l���X�V�ł��邩�Ŕ��f���Ă���̂ŁA�l���X�V����ƕ���H�ł����Ă�����H�����ł͂Ȃ��Ȃ�
	* @param x ���S�ƂȂ�X���W
	* @param y ���S�ƂȂ�Y���W
	* @param _maze[height][wigth] ���H�̍\����
	* @return LoadType���Ԃ�
	*/
	LoadType IsInexistentLoad(int x, int y, int _maze[height][width], int cost = 1);

};
#endif // !ROUTE_SEARCH_H_

