#ifndef Route_H_
#define Route_H_


#include <iostream>
#include <vector>

struct NodeData
{
	//この頂点の番号
	int vertex_num;
	//ノードの値
	int nodeNum;
	//この頂点とつながっている番号
	std::vector<int> connect_nodes;
};

class Daikstra
{
	void InitNodes();

	std::vector<NodeData> NodesData;

	NodeData nodes_data[];

};

#endif