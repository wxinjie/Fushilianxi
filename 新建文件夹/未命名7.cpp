#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int h[N], n, m, size = 0;

void up(int x)
{
	int u = x;
	while(u / 2 && h[u / 2] > h[u]) 
	{
		swap(h[u / 2], h[u]);
		u /= 2;
	}
}

void down(int x)
{
	int u = x;
	if(2 * u < size && h[2 * u] < h[u]) u *= 2;
	if(2 * x + 1 < size && h[2 * x + 1] < h[u]) u = u * 2 + 1;
	if(u != x) swap(h[u], h[x]);
	down(u);
}

int main()
{
	cin >> n >> m;
	while(n--)
	{
		int x;
		cin >> x;
		h[++size] = x;
		up(size);
	}
	
	while(m--)
	{
		printf("%d ", h[1]);
		h[1] = h[size];
		size --;
		down(1);
	}
	return 0;
}
