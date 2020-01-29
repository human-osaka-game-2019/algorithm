#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


struct Edge
{
	int src, dest, weight;
};

// グラフ構造
// V :: 頂点の数E::幹線の数
// edge :: ポインタ型に異なる頂点を接続するために存在
struct Graph
{
	int V, E;

	struct Edge* edge;
};

// VとEを介して頂点と幹線の数を用いるグラフを作成
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));

	graph->V = V;
	graph->E = E;

	graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));

	return graph;
}

// 結果を出力   頂点:Vertex 距離:Distance
void printArr(int dist[], int n)
{
	printf("頂点   距離\n");
	for (int i = 0; i < n; ++i)
		dist[i] == INT_MAX ? printf("%d \tINF\n", i) : printf("%d \t %d\n", i, dist[i]);
}

// srcから他のすべての頂点までの最短距離を見つけるためのBellmanFord関数
// 陰の重みまで適用が可能である。
void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int* dist = (int*)malloc(sizeof(int) * V); // int dist[V+1]と同じ

											 // すべての最短距離を無限大にしてくれて、開始点（src）のみ0に初期化 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// ベルマンフォードアルゴリズム
	for (int i = 1; i <= V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			//頂点u（始点）無限大ではなく、
			//出発点までの最短距離+重みが到着地の重みよりも
			//小さいときに更新してくれる。
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	// 陰の重みため無限最短経路が小さくなることがある場合は
    //移動して教えてくれる。
	for (int i = 0; i < E; i++)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		//if文では、現在の位置の最短距離 + 重みが継続してより小さくなる場合
		//陰のサイクルがあると判断する。
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			printf("\n");
	}

	printArr(dist, V);

	return;
}


int main()
{
	int V = 5;  // 頂点の数 
	int E = 9;  // 幹線の数
	struct Graph* graph = createGraph(V, E);

	// グラフの情報を入力
	graph->edge[0].src = 0; // 0から
	graph->edge[0].dest = 2; // 2に行く幹線の
	graph->edge[0].weight = 1; // 重みは1で決める。

	graph->edge[1].src = 0;
	graph->edge[1].dest = 3;
	graph->edge[1].weight = 5;

	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = -2;

	graph->edge[3].src = 2;
	graph->edge[3].dest = 1;
	graph->edge[3].weight = 4;

	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	graph->edge[5].src = 3;
	graph->edge[5].dest = 0;
	graph->edge[5].weight = -1;

	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 3;

	graph->edge[7].src = 4;
	graph->edge[7].dest = 0;
	graph->edge[7].weight = 1;

	graph->edge[8].src = 4;
	graph->edge[8].dest = 2;
	graph->edge[8].weight = -1;

	BellmanFord(graph, 0);

	return 0;

}