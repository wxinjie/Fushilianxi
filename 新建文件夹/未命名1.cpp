#include<iostream>

using namespace std;

const int N = 80;

char op[N][N];
bool col[N], dg[N], udg[N];
int n;

void dfs(int u)
{
	if(u == n)
	{
		for(int i = 0; i < n; i++) puts(op[i]);
		puts("");
	}
	
	for(int i = 0; i < n; i++)
	{
		if(!col[i] && !dg[i + u] && !udg[i - u + n])
		{
			op[u][i] = 'Q';
			col[i] = dg[i + u] = udg[i - u + n] = true;
			dfs(u + 1);
			col[i] = dg[i + u] = udg[i - u + n] = false;
			op[u][i] = '.';
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			op[i][j] = '.';
			
	dfs(0);
	return 0;
}
