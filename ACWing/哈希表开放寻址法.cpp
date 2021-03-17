//开放寻址法
#include<iostream>
#include<cstring>

using namespace std;

const int N = 200003, null =  0x3f3f3f3f;//null不在x范围内 

int h[N];

int find(int x) //返回值有两个含义：如果x在哈希表中，返回x的下标；如果 x不在哈希表中，返回x应该插入的位置 
{
	int k = (x % N + N) % N;
	while(h[k] != null && h[k] != x)
	{
		k++;
		if(k == N) k = 0;
	}
	return k;
 } 
 
int main()
{
	int n;
	scanf("%d", &n);
	char op[2];
	int x;
	memset(h, null, sizeof(h));
	while(n--)
	{	
		scanf("%s%d", op, &x);
		int k = find(x);
		if(op[0] == 'I')
		{
			h[k] = x;
		}
		else
		{
			if(h[k] != null) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
