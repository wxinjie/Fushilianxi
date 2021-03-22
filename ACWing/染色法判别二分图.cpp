//����ͼ���ʣ�һ��ͼ�Ƕ���ͼ���ҽ���ͼ�в���������
//֤��һ��ͼ�Ƕ���ͼ��Ⱦɫ��
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
		if(!color[j])//δȾ��ɫ��Ⱦɫ 
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
	
	//��ʼȾɫ
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
















