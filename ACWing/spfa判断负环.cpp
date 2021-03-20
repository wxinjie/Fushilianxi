//spfa判断负环：  设一个cnt[]，记录经过的边数    每次执行dist[b] = dist[t] + w 时 更新：cnt[x] = cnt[t] + 1;
//给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。判断图中是否存在负权回路。
/*
3 3
1 2 -1
2 3 4
3 1 -4
output
Yes
*/
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;//因为是稀疏图，改用邻接表方式   w:权重  
int dist[N], cnt[N];//cnt:边数 
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
	//不需要初始化了，因为求得不是距离的绝对值 
	queue<int> q;//存储所有待更新的点 
	for(int i = 1; i <= n; i++) //负环不一定从一号点开始，所以把所有点加进去 
	{
		st[i] = true;
		q.push(i);
	}
	
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
				cnt[j] = cnt[t] + 1;
				if(cnt[j] >= n) return true; 
				if(!st[j])//当j不在队列中时才加入 
				{
					q.push(j);
					st[j] = true;
				}
			}
		 } 
	 } 
	 return false; 
	
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
	 if(spfa()) puts("Yes");
	 else puts("No");
	 return 0; 
} 
