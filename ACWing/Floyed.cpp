//Floyed
/*
�ڽӾ������� d[i][j]
 ����ѭ��   for k: 1 ~ n
 				for i: 1 ~ n
				 	for j:1 ~ n
					 	d[i][j] = min( d[i][j], d[i][k] + d[k][j]) 
*/

//����һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի�����Ȩ����Ϊ������
//�ٸ���k��ѯ�ʣ�ÿ��ѯ�ʰ�����������x��y����ʾ��ѯ�ӵ�x����y����̾��룬���·�������ڣ����impossible�������б�֤�����ڸ�Ȩ��·��

/*
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
output
impossible
1 
*/
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N]; 

void floyed()
{
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
}

int main()
{
	scanf("%d%d%d", &n, &m, &Q);
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i == j) d[i][j] = 0;
			else d[i][j] = INF;
			
	while(m--)
	{
		int a, b ,w;
		scanf("%d%d%d", &a, &b, &w);
		d[a][b] = min(d[a][b], w);//�ر�ֻ��¼��Сֵ 
	}
	
	floyed();
	
	while(Q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(d[x][y] > INF / 2) puts("impossible");
		else printf("%d\n", d[x][y]);
	}
	return 0;
}





















 
