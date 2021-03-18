//树和图的存储  树是一种特殊的图，无环连通图，只管图即可，图分为无向图和有向图 存储方式：邻接矩阵、邻接表
//树的重心：给定一棵树，树中包含n个结点（编号1~n)和n - 1条无向边。求树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。
//重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心
//输入第一行整数n和n-1行表示a和b存在边 
/*
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
output
4
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010, M = N * 2;

int n; 
int h[N], e[M], ne[M], idx;//h存每个链表的链表头，e存每个结点的值，ne存next指针
bool st[N];//存放哪些节点遍历过 
int ans = N;//存答案 

void add(int a, int b)	//插入从a指向b的边 
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++; 
}

//以u为根的子树中点的数量 
int dfs(int u)
{
	st[u] = true;//标记当前点已被遍历过
	
	int sum = 1, res = 0;//sum记录当前点的数量  res记录每个连通块的最大值 
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];//当前节点在图中的编号是多少
		if(!st[j]) 
		{
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		} 
	 } 
	 
	 res = max(res, n - sum); //求上面所有点的数量比较选出最大值
	 ans = min(ans, res);
	 return sum; 
}

int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	dfs(1);
	cout << ans << endl;
}

 
