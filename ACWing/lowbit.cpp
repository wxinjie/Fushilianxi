//lowbit(x):����x�����һλ1    x = 101000  lowbit(x) = 1000  lowbit�����߼� x & -x ��  -x = ~x + 1    ->  x & (~x + 1)
//Ӧ�ã�ͳ��x���������ж���1
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
