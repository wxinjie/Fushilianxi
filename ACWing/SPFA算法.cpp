//SPFA算法：对bellman-ford做优化，dist[b]只有在dist[a]比它小的情况下才有可能变小   ***一般情况下效率比朴素dijkstra效率要高，但是如果被卡了就只能换堆优化版dijkstra 
/*
queue  <-- 1
while 队列不空
	t <-- q.front
	q.pop()
	更新t的所有出边 t->b(w)
	queue <--b 
*/

//给定一个n个点m条边的有向图，图中可能存在重边和自环,所有边权均为正值。所有边的长度都是1，点的编号为1~n。求出1号点到n号点的最短距离，若果无法从1号点走到n号点，输出-1 
//第一行n，m 接下来m行每行包含三个整数x， y， z，表示x和y之间存在一条有向边，边长为z。
/*
3 3
1 2 5
2 3 -3
1 3 4
output
2
*/
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;//因为是稀疏图，改用邻接表方式   w:权重  
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; 
	queue<int> q;//存储所有待更新的点 
	q.push(1);
	st[1] = true;//st存当前点是否在队列中
	while(q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false; 
		
		//更新t的所有邻边
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])//当j不在队列中时才加入 
				{
					q.push(j);
					st[j] = true;
				}
			}
		 } 
	 } 
	 if(dist[n] == 0x3f3f3f3f) return -1;
	 return dist[n]; 
	
}

int main()
{
	scanf("%d%d", &n, &m);
	//初始化
	memset(h, -1 ,sizeof h);
	
	//读入m条边
	while(m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);//用邻接表存，重边无所谓，优先队列会保证选最小的 
	 } 
	 int t = spfa();
	 if(t == -1) puts("impossible");
	 else printf("%d\n",t);
	 return 0; 
}
 
 
 
