//����һ������Ϊn���������У����ÿ������ߵ�һ������С��������������������-1 
/*
5
3 4 2 7 5
output
-1 3 -1 2 2
*/
#include<iostream>

using namespace std;

const int N = 100010;

int n, tt, stk[N];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		while(tt && stk[tt] > x) tt--;
		if(tt) cout << stk[tt] << ' ';
		else cout << "-1 ";
		stk[++tt] = x;
	}
	return 0;
 } 

