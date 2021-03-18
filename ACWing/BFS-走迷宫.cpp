//BFS-���Թ�:����һ��n*m�Ķ�ά�������飬������ʾһ���Թ���������ֻ����0��1������0��ʾ�����ߵ�·��1��ʾ������ͨ����ǽ�����һ���������Ͻǣ�1��1����
//����ÿ�ο�����������������һ�������ƶ�һ��λ�ã��ʸ��˴����Ͻ��ƶ������½ǣ�n��m����������Ҫ�ƶ����ٴΡ�
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
int g[N][N];//��ͼ 
int d[N][N];//��ÿһ���㵽���ľ��� 

PII q[N * N];

int bfs()
{
	int hh = 0, tt = 0;	//ģ��һ������ 
	q[0] = {0, 0};
	memset(d, -1, sizeof d);
	d[0][0] = 0;
//	��(-1��0) ��(0��1) ��(1��0) ��(0��-1)
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
