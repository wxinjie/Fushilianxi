/*												朴素Dijkstra算法 适合稠密图  O(n^2) 
							所有边权都是正数 
												堆优化版的Dijkstra算法 适合稀疏图O(mlogn)
			单源最短路径 
											Bellman-Ford O(mn)
							存在负权边 
											SPFA 一般：O(m) 最坏：O(mn)  不适用于求 限制经过边数的题目 
最短路   难点：建图，将问题抽象为最短路问题！ 
							
			多源汇最短路径 	Floyed算法 O(n^3)
			
			
*/ 
//朴素Dijkstra算法 初始化dis[1] = 0 dis[i] = 正无穷，然后开始n轮迭代，将不在集合s中的距离最近的点t加入s，用t更新到其他点的距离 
//给定一个n个点m条边的有向图，图中可能存在重边和自环,所有边权均为正值。所有边的长度都是1，点的编号为1~n。求出1号点到n号点的最短距离，若果无法从1号点走到n号点，输出-1 
//第一行n，m 接下来m行每行包含三个整数x， y， z，表示x和y之间存在一条有向边，边长为z。
/*
3 3
1 2 2
2 3 1
1 3 4
output
3 
*/

#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];//邻接矩阵 
int dist[N];
bool st[N];

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 0; i < n; i++)
	{
		int t = -1;
		for(int j = 1; j <= n; j++)
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		
		st[t] = true;
		
		for(int j = 1; j <= n; j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}

int main()
{
	scanf("%d%d", &n, &m);
	//初始化
	memset(g, 0x3f, sizeof g);
	
	//读入m条边
	while(m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c); //可能有重边，只保留最短的 
	 } 
	 int t = dijkstra();
	 printf("%d\n",t);
	 return 0; 
}


















