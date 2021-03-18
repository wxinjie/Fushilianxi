//����ͼ����������
/*
queue <-- �������Ϊ0�ĵ�
while queue ����
{
	t <--��ͷ
	ö��t�����г��� t-->j
		ɾ��t-->j d[j]--;
		if(d[j] == 0) 
			queue <--j
}
*/
/*
3 3
1 2
2 3
1 3
output
1 2 3
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
	int hh = 0, tt = -1;
	for(int i = 1; i <= n; i++)
	{
		if(!d[i])
		{
			q[++tt] = i;
		}
	}
	while(hh <= tt)
	{
		int t = q[hh++];
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			d[j]--;
			if(!d[j]) q[++tt] = j;
		 } 
	}
	return tt == n - 1;//�ж����е��Ƿ���ӹ� 
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b]++;
	}
	
	if(topsort())
	{
		for(int i = 0; i < n; i++) printf("%d ",q[i]);
		puts("");
	}
	else puts("-1");
	return 0;
}












