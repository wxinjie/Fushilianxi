//单调队列应用---滑动窗口
//第一行包含两个数n和k，分别代表数组长度和滑动窗口大小；第二行有n个数，代表数组的具体值
//输出第一行表示每个滑动窗口中的最小值，第二行表示每个滑动窗口中的最大值
/*
8 3
1 3 -1 -3 5 3 6 7
output
-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/
#include<iostream>

using namespace std;

const int N = 100010;

int n, k;
int a[N], q[N];//单调队列q存下标 

int main()
{
	scanf("%d%d",&n, &k);
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	int hh = 0, tt = -1;
	for(int i = 0; i < n; i++)
	{
		//判断队头是否已经滑出窗口,每次只会移动一个数，因此if即可                                            
 		if(hh <= tt && i - k + 1 > q[hh]) hh++;
		while(hh <= tt && a[q[tt]] >= a[i]) tt--;//如果新插入的数比队尾的数要小的话，就出队
		q[++tt] = i; 
		if(i >= k - 1) printf("%d ",a[q[hh]]);  //特判一下初始长度不满足k的情况
	}
	puts(""); 
	
	
	//最大值类似
	hh = 0, tt = -1;
	
	for(int i = 0; i < n; i++)
	{
		//判断队头是否已经滑出窗口,每次只会移动一个数，因此if即可 
		if(hh <= tt && i - k + 1 > q[hh]) hh++;
		while(hh <= tt && a[q[tt]] <= a[i]) tt--;//如果新插入的数比队尾的数要小的话，就出队
		q[++tt] = i; 
		if(i >= k - 1) printf("%d ",a[q[hh]]);  //特判一下初始长度不满足k的情况
	}
	puts("");  
	return 0;	
 } 
