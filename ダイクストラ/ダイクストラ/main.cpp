#include <stdio.h>
#include <limits.h> // INT_MAXに利用

// 頂点の数を定義
#define V 5

int minDistance(int dist[V], bool sptSet[V])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
	{
		if (!sptSet[v] && min > dist[v])
		{
			min_index = v;
			min = dist[v];
		}
	}

	return min_index;
}

// 開始点からその頂点までの最短距離を出力してくれる。
//　Distance　距離
//　printSolution　出力解決
//　/ｔタブ
void printSolution(int dist[], int n)
{
	printf("Vertex   Distance\n");
	for (int i = 0; i < V; i++)
		printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // 最短距離を把握する配列
	bool sptSet[V]; // 訪問したのかチェックするbool型配列

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// 初期条件設定
	dist[src] = 0;

	// 頂点（ｖ）1回のループを実行するということは、最初srcノードを除くすべてのノードへのアクセスをして計算
	// src鉄骨 ノード分岐
	for (int count = 0; count < V - 1; count++)
	{
		//最短距離情報を知っているノードの中で最も距離が短いノードのインデックスを持って来る
		
		int u = minDistance(dist, sptSet);

		// グラフ上のすべてのノードを探索し、uノードの周辺情報を更新する。
		for (int v = 0; v < V; v++)
		{
			// 1.まだ処理がされていないノードであると（無限ループを防ぐ）
			// 2. srcからuまでの経路が存在
			// 3. 基本の　vノードまでの最短距離の値よりも新しく計算された最短距離が短い場合
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v])
			{
				// 最短距離更新
				dist[v] = dist[u] + graph[u][v];
			}
		}

		// もはや このノード(u)は接近することはない。 フラグを trueで設定
		sptSet[u] = true;

		// 現在までの最短距離を出力
		printSolution(dist, V);
	}
}

int main()
{
	int graph[V][V] =
	{
		{ 0, 3, 6, 8, 7 },
		{ 3, 0, 2, 4, 8 },
		{ 6, 2, 0, 5, 5 },
		{ 8, 4, 5, 0, 2 },
		{ 7, 8, 5, 2, 0 },
	};

	dijkstra(graph, 0);

	return 0;
}

/*
ダイクストとは？
グラフ上に存在する二つのノード間の最短距離を求めたいとき利用
まず多エクストラアルゴリズムの前提条件は、次のとおりである。

1. [スタートノード 開始ノードまでの距離は0である。
2.他のノードを介して、このノードを訪問するときは、すべてのトランクの
　重みが正であるため、重複訪問をすれば無条件距離がより長くなる。
（すなわち、0から1への長さが2であるが0から1に1から0に行く4になるので、
　この方法は、距離が長くなりますがする。）

*/