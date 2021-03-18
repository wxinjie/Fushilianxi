//n-皇后
/*
4
output
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
*/
#include<iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N]; 
bool col[N], dg[N], udg[N];//列，正对角线，反对角线 

void dfs(int u)
{
	if(u == n)
	{
		for(int i = 0; i < n; i++) puts(g[i]);
		puts("");
		return ;
	}
	 
	for(int i = 0; i < n; i++)
	{
		if(!col[i] && !dg[i + u] && !udg[i - u + n])
		{
			g[u][i] = 'Q';
			col[i] = dg[i + u] = udg[i - u + n] = true;
			dfs(u + 1);
			col[i] = dg[i + u] = udg[i - u + n] = false; //恢复现场 
			g[u][i] = '.';
		}
	}
 } 

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			g[i][j] = '.';
	dfs(0);
	return 0;
 } 

 
