#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int f[N], a[N], n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for(int j = 1; j < i; j++)
			if(a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);
	}
 } 
