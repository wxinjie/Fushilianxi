//最小生成树(无向图,不存在环，边是正是负都可)   1. Prim算法  朴素版Prim O(n^2)、堆优化版Prim O(mlogn)     2.Kruskal算法 O(mlogm)
//						方法选择： 稠密图：朴素版Prim  稀疏图：Kruskal 

//二分图   1.判断是不是二分图：染色法(dfs) O(m + n)   2.匈牙利算法：求二分图的最大匹配 O(mn),实际运行时间一般远小于O（mn）

/*朴素版Prim
	dist[i] <-- INF
	for(i = 0; i < n; i++)
		t <-- 找到集合外距离最近的点
		用t更新其他点到集合的距离(Dijkstra算法是更新其他点到1号点的距离)
		st[t] = true;
*/

/*Prim算法求最小生成树：给定一个n个点m条边的无向图，图中可能存在重边和自环，边权可能为负数。求最小生成树的树边权重之和，如果最小生成树不存在则输出impossible
给定一张边带权的无向图G(V, E) ,其中V表示图中点的集合，E表示图中边的集合， n = |V| , m = |E|。
由V中的全部顶点和E中的n - 1条边构成的无向联通子图被称为G的一颗生成树，其中边的权值之和最小的生成树被称为无向图G的最小生成树。
输入： n ，m
		m行， u，v，w，表示u点到v点之间存在一条权值为w的边
*/

/*
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
output
6
*/
 
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];


int prim()
{
	memset(dist, 0x3f, sizeof dist);
	
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		int t = -1;
		for(int j = 1; j <= n; j++) //当前距离集合最小的点 
			if(!st[j] && (t == -1 || dist[t] > dist[j]))  
				t = j;
		 
		if(i && dist[t] == INF) return INF; //不连通，直接返回 
		
		if(i) res += dist[t];  //只要不是第一个点就更新距离 
		
		for(int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]); //用t更新其他点到集合的距离！！！先更新答案再用t更新其他点的目的是不使自环的值干扰答案（j=t) 
		
		st[t] = true;
	}
	return res; 
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof g);
	while(m--)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		g[a][b] = g[b][a] = min(g[a][b], w);
	}
	
	int t = prim();
	
	if(t == INF) puts("impossible");
	else printf("%d\n", t);
	return 0;
}





















 
		 
 

 
