/*
并查集：
1.将两个集合合并
2.询问两个元素是否在同一集合中
思想：用树来描述每一个集合，根结点的编号就是当前集合的编号，每一个点都存储它的父节点是谁 p[x]表示x的父节点。
问题1：如何判断树根？ if(p[x] == x)
问题2：如何求x的集合编号？：while(p[x] != x) x = p[x];
问题3：如何合并两个集合？p[x]是x的集合编号，p[y]是y的集合编号。p[x] = y 
路径压缩优化：找到x的根结点后将路径上的所有结点都指向根结点 
*/ 

//一共有n个数，编号1~n-1，最开始每个数各在一个集合中。进行m次操作： 1.M a b :将编号为a和b的两个数所在集合合并 2.Q a b ：询问编号为a和b的两个数是否在同一个集合中 
/*
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
yes
no
yes
*/
#include<iostream>

using namespace std;

const int N = 100010;

int n, m, p[N];

int find(int x)	//返回x的祖宗节点+路径压缩 
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x]; 
 } 

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) p[i] = i; 
	
	while(m--)
	{	
		char op[2];
		int a, b;
		scanf("%s %d%d",op, &a, &b);
		if(op[0] == 'M')
		{
			p[find(a)] = find(b);
		}
		else
		{
			if(find(a) == find(b)) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;	
 } 
 
