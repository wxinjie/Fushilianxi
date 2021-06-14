#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e5 + 10;
int a[N];

int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]); 
	}
	int res = 1;
	sort(a, a + n);
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			if((a[j] - a[i]) > d)
			{
				res++;
				i = j;
				break;
			}
		}
	}
	printf("%d", res);
	return 0;
	
}
