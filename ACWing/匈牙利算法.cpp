//�������㷨 ����ͼ���ƥ����� ƥ��ָ�������������߶�������һ���㣬����̤��ֻ��
/*����ͼ�����ƥ��
����һ������ͼ��������벿����n1�����ţ�1~n1�����Ұ벿����n2���㣨���1~n2��������ͼ������m���ߡ�
���ݱ�֤����һ���ߵ������˵㶼��������ͬһ�����С�
�����������ͼ�����ƥ���� 
���� ��n1��n2, m
m�У�u��v
*/

/*
2 2 4
1 1
1 2
2 1
2 2
output
2
*/

#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];//�Ұ벿�ĵ�ƥ��ĵ� 
bool st[N]; 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
	for(int i = h[x]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			st[j] = true;
			if(match[j] == 0 || find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false; 
}

int main()
{
	scanf("%d%d%d", &n1, &n2, &m);
	memset(h, -1, sizeof h);
	
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	int res = 0;//��ǰƥ������
	for(int i = 1; i <= n1; i++)
	{
		memset(st, false, sizeof st);//��֤ÿ���Ұ벿�ĵ�ֻ����һ��
		if(find(i))	res++; 
	 } 
	 
	 printf("%d\n",res);
	 return 0;
}
 
 
