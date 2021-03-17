/*
哈希表   1.存储结构,处理冲突方式：开放寻址法、拉链法    2.字符串哈希方式
*/
//进行n次操作，维护一个集合 ： I x：插入一个数x     Q x：询问数x是否在集合中出现过      n<=10^5    -10^9 =< x <= 10^9 

//拉链法 
/*5
I 1
I 2
I 3
Q 2
Q 5
output
yes
no
*/
#include<iostream> 
#include<cstring>
using namespace std;

const int N = 1e5 + 3;
/*
for(int i = 100000; ; i++)
	{
		bool flag = true;
		for(int j = 2; j * j <= i; j++)
		{
			if(i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout << i << endl;
			break;
		}
	}
*/

int h[N], e[N], ne[N], idx;//h:槽 

void insert(int x)
{
	int k = (x % N + N) % N;//+N是为了让结果变成正数
	e[idx] = x, ne[idx] = h[k], h[k] = idx++; 
}

bool find(int x)
{
	int k = (x % N + N) % N;
	for(int i = h[k]; i != -1; i = ne[i])
		if(e[i] == x)
			return true;
	
	return false; 
 } 

int main()
{
	int n;
	scanf("%d", &n);
	memset(h, -1, sizeof(h));
	
	while(n--)
	{
		char op[2];
		int x;
		scanf("%s%d", op, &x);
		if(op[0] == 'I') insert(x);
		else
		{
			if(find(x)) puts("yes");
			else puts("no");
		}
	}
 } 
