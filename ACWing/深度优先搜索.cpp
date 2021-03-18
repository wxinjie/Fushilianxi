/*						数据结构    空间复杂度     
1.深度优先搜索 DFS		stack			O（h） 			不具有最短性质 
2.宽度优先搜索 BFS		queue			O（2^h） 		最短路径 
3.树与图的存储
4.树与图的深度优先遍历
5.树与图的宽度优先遍历
6.拓扑排序
*/ 

//DFS  考虑顺序！ 树的形式搜索  回溯，恢复现场 
//排列数字：给定一个数字n，将1~n排成一排，按字典序输出所有的排列。
#include<iostream>

using namespace std;

const int N = 10;

int n;
int path[N];
bool st[N];

void dfs(int u)
{
	if(u == n)
	{
		for(int i = 0; i < n; i++) printf("%d ",path[i]);
		puts("");
		return ;
	}
	 
	for(int i = 1; i <= n; i++)
	{
		if(!st[i])
		{
			path[u] = i;
			st[i] = true;
			dfs(u + 1);
			st[i] = false; //恢复现场 
		}
	}
 } 

int main()
{
	cin >> n;
	
	dfs(0);
	
	return 0;
 } 


 
