//完全背包问题优化
/*
	f[i,j] = f[i - 1,j - v[i]*k] + w[i] * k
	
	f[i,j] = max(f[i - 1,j] , f[i - 1,j - v] + w , f[i - 1,j - 2v] + 2w,...)
	f[i,j - v] = max(f[i - 1,j - v] , f[i - 1,j - 2v] + 2w,...)
	
	f[i,j] =Max(f[i - 1,j],f[i - 1,j - v] + w)
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
		{
			f[i][j] = f[i - 1][j];
			if(j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);	
		}
				
	cout << f[n][m] << endl;
	return 0;
} 
