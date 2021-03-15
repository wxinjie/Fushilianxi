//lowbit(x):返回x的最后一位1    x = 101000  lowbit(x) = 1000  lowbit背后逻辑 x & -x ：  -x = ~x + 1    ->  x & (~x + 1)
//应用：统计x二进制中有多少1
/*
5
1 2 3 4 5
output
1 1 2 1 2
*/
#include<iostream>

using namespace std;

int lowbit(int x)
{
	return x & -x;
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		
		int res = 0;
		while(x != 0)
		{
			x -= lowbit(x);
			res++;
		}
		cout << res << ' ';
	 } 
	return 0;
 } 
