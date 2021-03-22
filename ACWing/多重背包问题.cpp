//多重背包问题：N种物品和一个容量为V的背包。第i种物品最多有si件，每件体积是vi，价值是wi。 
/*

													所有只从前i个物品中选，并且总体积不超过j的选法 
											集合 
													
		状态表示 f（i，j） 几维表示 
											属性 ：Max（本题）， Min，数量 
DP 
  
		状态计算 	集合划分（1~i-1,i）  1.不重 2.不漏     f[i][j] = max(f[i - 1][j - v[i] * k] + w[i] * k); k = 0,1,2,... si 
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









 
