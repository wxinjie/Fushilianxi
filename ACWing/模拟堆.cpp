/*模拟堆 
I x:插入一个数
PM：输出最小值
DM：删除最小值
D k:删除第k个插入的数
C k x：修改第k个插入的数为x 

*/
/*
9
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
PM
OUTPUT:
-10
6
8
*/
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int N = 100010;

int n, m;//m:当前第几个要插入的数 
int h[N], ph[N], hp[N], size = 0; //ph[k]:第k个插入的数在堆中的下标   hp[k]：堆中的k号点是第几个插入的数   存映射关系并每一次操作后维护关系 

void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
 } 

void down(int u)
{
	int t = u;
	if(u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
	if(u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
	if(u != t)
	{
		heap_swap(u, t);
		down(t);
	} 
}

void up(int u)
{
	while(u / 2 && h[u / 2] > h[u]) 
	{
		heap_swap(u / 2, u);
		u /= 2;
	}
}

int main()
{
	scanf("%d",&n);
	int k, x; 
	while(n--)
	{
		char op[10];
		scanf("%s",op);
		if(!strcmp(op, "I"))
		{
			scanf("%d",&x);
			size++;
			m++;
			ph[m] = size;
			hp[size] = m;
			h[size] = x; 
			up(size);
		}
		else if(!strcmp (op, "PM")) printf("%d\n", h[1]);
		else if(!strcmp(op, "DM")) 
		{
			heap_swap(1,size);
			size--;
			down(1);
		}
		else if(!strcmp(op, "D"))
		{
			scanf("%d",&k);
			k = ph[k];
			heap_swap(k, size);
			size--;
			down(k), up(k);//最多执行一个  
		}
		else
		{
			scanf("%d%d", &k, &x);
			k = hp[k];
			h[k] = x;
			down(k), up(k);
		 } 
	}
	
	return 0;
}
