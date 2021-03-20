//Floyed
/*
邻接矩阵存距离 d[i][j]
 三重循环   for k: 1 ~ n
 				for i: 1 ~ n
				 	for j:1 ~ n
					 	d[i][j] = min( d[i][j], d[i][k] + d[k][j]) 
*/

//给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。
//再给定k个询问，每个询问包含两个整数x和y，表示查询从点x到点y的最短距离，如果路径不存在，输出impossible。数据中保证不存在负权回路。

/*
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
output
impossible
1 
*/
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N]; 

void floyed()
{
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
}

int main()
{
	scanf("%d%d%d", &n, &m, &Q);
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i == j) d[i][j] = 0;
			else d[i][j] = INF;
			
	while(m--)
	{
		int a, b ,w;
		scanf("%d%d%d", &a, &b, &w);
		d[a][b] = min(d[a][b], w);//重边只记录最小值 
	}
	
	floyed();
	
	while(Q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(d[x][y] > INF / 2) puts("impossible");
		else printf("%d\n", d[x][y]);
	}
	return 0;
}





















 
