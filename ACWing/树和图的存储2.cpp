//图中点的层次：给定一个n个点m条边的有向图，图中可能存在重边和自环。所有边的长度都是1，点的编号为1~n。求出1号点到n号点的最短距离，如果1号点
//无法走到n号点，输出-1。 第一行包含两个整数n，m。接下来m行，每行包含两个数a，b，表示存在一条从a走到b的长度为1的边。
/*
4 5
1 2
2 3
3 4
1 3
1 4
output
1
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx; 
int d[N], q[N];//d:距离 q:队列 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
	int hh = 0, tt = 0;
	q[0] = 1;
	memset(d, -1, sizeof d);
	d[1] = 0;
	while(hh <= tt)
	{
		int t = q[hh++];
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(d[j] == -1)
			{
				d[j] = d[t] + 1;
				q[++tt] = j;
			}
		}
	 }
	 
	 return d[n]; 
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	cout << bfs() << endl;
	return 0;
}
 

