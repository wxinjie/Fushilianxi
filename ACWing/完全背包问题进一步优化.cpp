//完全背包问题进一步优化（一维数组） 
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	
	for(int i = 1; i <= n; i++)
		for(int j = v[i]; j <= m; j++)
			f[j] = max(f[j], f[j - v[i]] + w[i]);// !!! 这里是和01背包问题相区别的地方，01要求算i- 1层，完全背包优化后要求算i层，此时j从v[i]开始，j - v[i]已经被算过了，属于第i层，刚好合适 
			
	cout << f[m] << endl;
	return 0;
}
