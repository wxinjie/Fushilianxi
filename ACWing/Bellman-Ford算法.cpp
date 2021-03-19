//Bellman-Ford
/*����˼��
 for n��   ***����k�κ����ǣ���1�ŵ㾭��������k�����ߵ�ÿ�������̾��� 
 	for ���б� a��b��w
	 	dist[b] = min ( dist[b], dist[a] + w[a]);  (�ɳڲ���) 
		 
�������㣺		 dist[b] <= dist[a] + w (���ǲ���ʽ) 
ע�����ڸ�Ȩ��·�����·��һ�����ڣ� Dijkstra�㷨���ܴ���Ȩ������. 
*/

//�б������Ƶ����·��������һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����ػ����Ի�����Ȩ����Ϊ�����������1�ŵ㵽n�ŵ����ྭ��k���ߵ���̾��룬����޷���1�ŵ��ߵ�n�ŵ㣬
//���impossible��
/*
3 3 1
1 2 1
2 3 1
1 3 3
output
3
*/

#include<cstring>   
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510, M = 10010;

int n, m ,k;
int dist[N], backup[N];

struct Edge
{
	int a, b ,w;
}edges[M];

int bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 0; i < k; i++)
	{
		memcpy(backup, dist, sizeof dist); //���ݣ���ֹ������������ֻ֤����һ�εĵ������ 
		for(int j = 0; j < m; j++)
		{
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			dist[b] = min(dist[b],  backup[a] + w);
		 } 
	}
	if(dist[n] > 0x3f3f3f3f / 2) return -1;
	return dist[n];
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = {a, b, w};
	}
	int t = bellman_ford();
	
	if(t == -1) puts("impossible");
	else printf("%d\n", t);
	return 0;
}















