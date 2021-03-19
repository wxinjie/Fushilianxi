//Bellman-Ford
/*核心思想
 for n次   ***迭代k次含义是：从1号点经过不超过k条边走到每个点的最短距离 
 	for 所有边 a，b，w
	 	dist[b] = min ( dist[b], dist[a] + w[a]);  (松弛操作) 
		 
最终满足：		 dist[b] <= dist[a] + w (三角不等式) 
注：存在负权回路，最短路不一定存在！ Dijkstra算法不能处理负权边问题. 
*/

//有边数限制的最短路径：给定一个n个点m条边的有向图，图中可能存在重环和自环，边权可能为负数。求出从1号点到n号点的最多经过k条边的最短距离，如果无法从1号点走到n号点，
//输出impossible。
/*
3 3 1
1 2 1
2 3 1
1 3 3
output
3
*/

#include<cstring>   
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510, M = 10010;

int n, m ,k;
int dist[N], backup[N];

struct Edge
{
	int a, b ,w;
}edges[M];

int bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 0; i < k; i++)
	{
		memcpy(backup, dist, sizeof dist); //备份，防止发生串联，保证只用上一次的迭代结果 
		for(int j = 0; j < m; j++)
		{
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			dist[b] = min(dist[b],  backup[a] + w);
		 } 
	}
	if(dist[n] > 0x3f3f3f3f / 2) return -1;
	return dist[n];
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = {a, b, w};
	}
	int t = bellman_ford();
	
	if(t == -1) puts("impossible");
	else printf("%d\n", t);
	return 0;
}















