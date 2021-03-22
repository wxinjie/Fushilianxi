//完全背包问题
/*

													所有选法 
											集合 
													条件：1.去掉k个物品i  2.求Max，f[i-1][j - k*v[i]] 3.再加回来k个物品i f[i-1][j - k*v[i]] + k *  w[i]		
		状态表示 f（i，j） 几维表示 
											属性 ：Max， Min，数量 
DP 
  
		状态计算 	集合划分（1~i-1,i）  1.不重 2.不漏     f(i,j) = max(f(i - 1,j), f(i - 1,j - vi) + wi) 
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
