//分组背包问题：N组物品和容量为V的背包，每组物品有若干个，同一组内的物品最多只能选一个。每件物品的体积是vij，价值是wij i是组号，j是组内编号
//输入 N V N行：第一行si表示第i组物品数量，si行 

/*

													只从前i组物品中选，并且总体积不超过j的所有选法 
											集合 
													
		状态表示 f（i，j） 几维表示 
											属性 ：Max（本题）， Min，数量 
DP 
  
		状态计算 	集合划分（1~i-1,i）  1.不重 2.不漏     f[i][j] = max(f[i - 1][j] , f[i - 1][j - v[i,k]] + w[i,k]);  v[i,k]:第i组第k个 
*/  
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		for(int j = 0; j < s[i]; j++)
			cin >> v[i][j] >> w[i][j];
	}
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= 0; j--)
			for(int k = 0; k < s[i]; k++)
				if(v[i][k] <= j) 
					f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
	cout << f[m] << endl;
	
	return 0;
}
 










