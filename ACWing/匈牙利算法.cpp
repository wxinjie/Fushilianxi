//匈牙利算法 二分图最大匹配次数 匹配指的是任意两条边都不共用一个点，不脚踏两只船
/*二分图的最大匹配
给定一个二分图，其中左半部包含n1个点编号（1~n1），右半部包含n2个点（编号1~n2），二分图共包含m条边。
数据保证任意一条边的两个端点都不可能在同一部分中。
请你求出二分图的最大匹配数 
输入 ：n1，n2, m
m行：u，v
*/

/*
2 2 4
1 1
1 2
2 1
2 2
output
2
*/

#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];//右半部的点匹配的点 
bool st[N]; 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
	for(int i = h[x]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			st[j] = true;
			if(match[j] == 0 || find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false; 
}

int main()
{
	scanf("%d%d%d", &n1, &n2, &m);
	memset(h, -1, sizeof h);
	
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	int res = 0;//当前匹配数量
	for(int i = 1; i <= n1; i++)
	{
		memset(st, false, sizeof st);//保证每个右半部的点只考虑一遍
		if(find(i))	res++; 
	 } 
	 
	 printf("%d\n",res);
	 return 0;
}
 
 
