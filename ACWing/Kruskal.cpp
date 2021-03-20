//Kruskal算法
/*
1.将所有边按权重从小到大排序 （sort函数即可）  这一步是瓶颈：O(mlogm)
2.枚举每条边 a--c--b                     
	if a, b不连通					后两个操作参考并查集2的  Q1 和 C操作    并查集复杂度O（1） 整个2.复杂度为O（m） 
		将这条边加入集合中 
*/
//前面学过的数据结构应用： 单链表存图  、 并查集用来做Kruskal  、 堆用来做Diskstra算法

//Kruskal算法求最小生成树	 
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N =  100010;

int n, m;
int p[N];

struct Edge
{
	int a, b, w;
	
	bool operator< (const Edge & W) const
	{
		return w < W.w;
	}
}edges[N];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < n; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = {a, b, w};
	}
	//Kruskal:
	sort(edges, edges + m);
	
	for(int i = 1; i <= n; i++) p[i] = i; //初始化并查集
	 
	int res = 0, cnt = 0;//res:最小生成树所有边之和 cnt：当前加入边数 
	for(int i = 0; i < m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		
		a = find(a), b = find(b);
		if(a != b)
		{
			p[a] = b;
			res += w;
			cnt++;
		}
	 } 
	 if(cnt < n - 1) puts("impossible");
	 else printf("%d\n", res);
	 
	 return 0;
}














