//ͼ�е�Ĳ�Σ�����һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի������бߵĳ��ȶ���1����ı��Ϊ1~n�����1�ŵ㵽n�ŵ����̾��룬���1�ŵ�
//�޷��ߵ�n�ŵ㣬���-1�� ��һ�а�����������n��m��������m�У�ÿ�а���������a��b����ʾ����һ����a�ߵ�b�ĳ���Ϊ1�ıߡ�
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
int d[N], q[N];//d:���� q:���� 

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
 

