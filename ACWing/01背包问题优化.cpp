//01背包问题优化：f(i，)只用到了f(i-1，)  且第二项都<=j   因此可以用一维来做 
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
		for(int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	cout << f[m] << endl;
	return 0;
} 
