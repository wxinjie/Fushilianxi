//Kruskal�㷨
/*
1.�����б߰�Ȩ�ش�С�������� ��sort�������ɣ�  ��һ����ƿ����O(mlogm)
2.ö��ÿ���� a--c--b                     
	if a, b����ͨ					�����������ο����鼯2��  Q1 �� C����    ���鼯���Ӷ�O��1�� ����2.���Ӷ�ΪO��m�� 
		�������߼��뼯���� 
*/
//ǰ��ѧ�������ݽṹӦ�ã� �������ͼ  �� ���鼯������Kruskal  �� ��������Diskstra�㷨

//Kruskal�㷨����С������	 
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N =  100010;

int n, m;
int p[N];

struct Edge
{
	int a, b, w;
	
	bool operator< (const Edge & W) const
	{
		return w < W.w;
	}
}edges[N];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < n; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = {a, b, w};
	}
	//Kruskal:
	sort(edges, edges + m);
	
	for(int i = 1; i <= n; i++) p[i] = i; //��ʼ�����鼯
	 
	int res = 0, cnt = 0;//res:��С���������б�֮�� cnt����ǰ������� 
	for(int i = 0; i < m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		
		a = find(a), b = find(b);
		if(a != b)
		{
			p[a] = b;
			res += w;
			cnt++;
		}
	 } 
	 if(cnt < n - 1) puts("impossible");
	 else printf("%d\n", res);
	 
	 return 0;
}














