//��С������(����ͼ,�����ڻ����������Ǹ�����)   1. Prim�㷨  ���ذ�Prim O(n^2)�����Ż���Prim O(mlogn)     2.Kruskal�㷨 O(mlogm)
//						����ѡ�� ����ͼ�����ذ�Prim  ϡ��ͼ��Kruskal 

//����ͼ   1.�ж��ǲ��Ƕ���ͼ��Ⱦɫ��(dfs) O(m + n)   2.�������㷨�������ͼ�����ƥ�� O(mn),ʵ������ʱ��һ��ԶС��O��mn��

/*���ذ�Prim
	dist[i] <-- INF
	for(i = 0; i < n; i++)
		t <-- �ҵ��������������ĵ�
		��t���������㵽���ϵľ���(Dijkstra�㷨�Ǹ��������㵽1�ŵ�ľ���)
		st[t] = true;
*/

/*Prim�㷨����С������������һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի�����Ȩ����Ϊ����������С������������Ȩ��֮�ͣ������С�����������������impossible
����һ�űߴ�Ȩ������ͼG(V, E) ,����V��ʾͼ�е�ļ��ϣ�E��ʾͼ�бߵļ��ϣ� n = |V| , m = |E|��
��V�е�ȫ�������E�е�n - 1���߹��ɵ�������ͨ��ͼ����ΪG��һ�������������бߵ�Ȩֵ֮����С������������Ϊ����ͼG����С��������
���룺 n ��m
		m�У� u��v��w����ʾu�㵽v��֮�����һ��ȨֵΪw�ı�
*/

/*
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
output
6
*/
 
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];


int prim()
{
	memset(dist, 0x3f, sizeof dist);
	
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		int t = -1;
		for(int j = 1; j <= n; j++) //��ǰ���뼯����С�ĵ� 
			if(!st[j] && (t == -1 || dist[t] > dist[j]))  
				t = j;
		 
		if(i && dist[t] == INF) return INF; //����ͨ��ֱ�ӷ��� 
		
		if(i) res += dist[t];  //ֻҪ���ǵ�һ����͸��¾��� 
		
		for(int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]); //��t���������㵽���ϵľ��룡�����ȸ��´�����t�����������Ŀ���ǲ�ʹ�Ի���ֵ���Ŵ𰸣�j=t) 
		
		st[t] = true;
	}
	return res; 
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof g);
	while(m--)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		g[a][b] = g[b][a] = min(g[a][b], w);
	}
	
	int t = prim();
	
	if(t == INF) puts("impossible");
	else printf("%d\n", t);
	return 0;
}





















 
		 
 

 
