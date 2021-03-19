/*												����Dijkstra�㷨 �ʺϳ���ͼ  O(n^2) 
							���б�Ȩ�������� 
												���Ż����Dijkstra�㷨 �ʺ�ϡ��ͼO(mlogn)
			��Դ���·�� 
											Bellman-Ford O(mn)
							���ڸ�Ȩ�� 
											SPFA һ�㣺O(m) ���O(mn)  ���������� ���ƾ�����������Ŀ 
���·   �ѵ㣺��ͼ�����������Ϊ���·���⣡ 
							
			��Դ�����·�� 	Floyed�㷨 O(n^3)
			
			
*/ 
//����Dijkstra�㷨 ��ʼ��dis[1] = 0 dis[i] = �����Ȼ��ʼn�ֵ����������ڼ���s�еľ�������ĵ�t����s����t���µ�������ľ��� 
//����һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի�,���б�Ȩ��Ϊ��ֵ�����бߵĳ��ȶ���1����ı��Ϊ1~n�����1�ŵ㵽n�ŵ����̾��룬�����޷���1�ŵ��ߵ�n�ŵ㣬���-1 
//��һ��n��m ������m��ÿ�а�����������x�� y�� z����ʾx��y֮�����һ������ߣ��߳�Ϊz��
/*
3 3
1 2 2
2 3 1
1 3 4
output
3 
*/

#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];//�ڽӾ��� 
int dist[N];
bool st[N];

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 0; i < n; i++)
	{
		int t = -1;
		for(int j = 1; j <= n; j++)
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		
		st[t] = true;
		
		for(int j = 1; j <= n; j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}

int main()
{
	scanf("%d%d", &n, &m);
	//��ʼ��
	memset(g, 0x3f, sizeof g);
	
	//����m����
	while(m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c); //�������رߣ�ֻ������̵� 
	 } 
	 int t = dijkstra();
	 printf("%d\n",t);
	 return 0; 
}


















