//��ȫ��������
/*

													����ѡ�� 
											���� 
													������1.ȥ��k����Ʒi  2.��Max��f[i-1][j - k*v[i]] 3.�ټӻ���k����Ʒi f[i-1][j - k*v[i]] + k *  w[i]		
		״̬��ʾ f��i��j�� ��ά��ʾ 
											���� ��Max�� Min������ 
DP 
  
		״̬���� 	���ϻ��֣�1~i-1,i��  1.���� 2.��©     f(i,j) = max(f(i - 1,j), f(i - 1,j - vi) + wi) 
*/  
/*
4 5
1 2
2 4
3 4
4 5
output 
10
*/
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k * v[i] <= j; k++)
				f[i][j] = max(f[i- 1][j], f[i - 1][j - k * v[i]] + k * w[i]);
				
	cout << f[n][m] << endl;
	return 0;
}
