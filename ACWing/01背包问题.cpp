/*DP:
  背包问题 01（每件物品最多用一次）、多重（每个物品有i个）、完全（每件物品有无限个）、分组（物品有n组，每组多干个物品中只能选一个）背包问题 
  线性DP
  区间DP
  计数类DP
  数位统计DP
  状态压缩DP
  树形DP
  记忆化搜索
*/

/*01背包问题
有N件物品和一个容量为V的背包。每件物品只能使用一次。
第i件物品的体积是vi，价值是wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包的容量，且总价值最大。
输出最大价值。
*/

/*

													所有选法 
											集合 
													条件：1.只从前i个物品中选  2.总体积<=j		
		状态表示 f（i，j） 几维表示 
											属性 ：Max， Min，数量 
DP 
  
		状态计算 	集合划分  1.不重 2.不漏     f(i,j) = max(f(i - 1,j), f(i - 1,j - vi) + wi) 
*/ 


/*
4 5
1 2
2 4
3 4
4 5
output
8
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
		{
			f[i][j] = f[i - 1][j];
			if(j >= v[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
		}
	cout << f[n][m] << endl;
	return 0;
}

























