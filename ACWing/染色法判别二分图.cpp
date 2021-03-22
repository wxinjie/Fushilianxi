//二分图性质：一个图是二分图当且仅当图中不含奇数环
//证明一个图是二分图：染色法
/*
4 4
1 3
1 4
2 3
2 3
output
Yes
*/

#include<cstring>
#include<iostream> 
#include<algorithm>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

bool dfs(int u, int c)
{
	color[u] = c;
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(!color[j])//未染过色，染色 
		{
			if(!dfs(j, 3 - c)) return false;
		}
		else if(color[j] == c) return false; 
	}
	return true;
 } 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main()
{
	scanf("%d%d", &n, &m);
	
	memset(h, -1, sizeof h);
	
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	
	//开始染色
	bool flag = true;
	for(int i = 1; i <= n; i++)
		if(!color[i])
		{
			if(!dfs(i, 1))
			{
				flag = false;
				break;
			}
		}
		
	if(flag) puts("Yes");
	else puts("No");
	return 0;
}
















