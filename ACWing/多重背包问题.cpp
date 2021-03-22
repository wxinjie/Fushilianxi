//���ر������⣺N����Ʒ��һ������ΪV�ı�������i����Ʒ�����si����ÿ�������vi����ֵ��wi�� 
/*

													����ֻ��ǰi����Ʒ��ѡ�����������������j��ѡ�� 
											���� 
													
		״̬��ʾ f��i��j�� ��ά��ʾ 
											���� ��Max�����⣩�� Min������ 
DP 
  
		״̬���� 	���ϻ��֣�1~i-1,i��  1.���� 2.��©     f[i][j] = max(f[i - 1][j - v[i] * k] + w[i] * k); k = 0,1,2,... si 
*/   

/*
4 5
1 2 3
2 4 1
3 4 3
4 5 2
output
10
*/
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N], w[N], s[N];
int f[N][N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
	
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k <= s[i] && k * v[i] <= j; k++)
				f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
				
	cout << f[n][m] << endl; 
	return 0; 
}









 
