//BFS-走迷宫:给定一个n*m的二维整数数组，用来表示一个迷宫，数组中只包含0或1，其中0表示可以走的路，1表示不可以通过的墙。最初一个人在左上角（1，1）处
//该人每次可以向上下左右任意一个方向移动一个位置，问该人从左上角移动至右下角（n，m）处至少需要移动多少次。
/*
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
output
8
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N];//存图 
int d[N][N];//存每一个点到起点的距离 

PII q[N * N];

int bfs()
{
	int hh = 0, tt = 0;	//模拟一个队列 
	q[0] = {0, 0};
	memset(d, -1, sizeof d);
	d[0][0] = 0;
//	↑(-1，0) →(0，1) ↓(1，0) ←(0，-1)
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
	while(hh <= tt)
	{
		PII t = q[hh++];
		for(int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i], y = t.second + dy[i]; 
			if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
			{
				d[x][y] = d[t.first][t.second] + 1;
				q[++tt] = {x, y};
			}
		}
	 } 
	 return d[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d",&g[i][j]);
			
	cout << bfs() << endl; 
	return 0;
}
