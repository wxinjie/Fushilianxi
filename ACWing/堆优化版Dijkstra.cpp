//堆优化版Dijkstra  t加入s这一步，如果用堆来找t，就可以以降低复杂度       堆实现方法：1.手写堆，很多映射比较复杂   2.优先队列，但不支持修改任意一个元素
/*
3 3
1 2 2
2 3 1
1 3 4
output
3 
*/
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> PII;//堆中维护的是一个pair<距离，编号> 

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;//因为是稀疏图，改用邻接表方式   w:权重  
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	priority_queue<PII, vector<PII>, greater<PII> > heap; //小根堆
	heap.push({0, 1});        //第一个点已知，直接放入
	
	while(heap.size())
	{
		PII t = heap.top(); //找到距离最小的点 
		heap.pop();
		
		int distance = t.first, ver = t.second;
		if(st[ver]) continue; 
		else st[ver] = true; //!
		for(int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({dist[j],j});
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
	 int t = dijkstra();
	 printf("%d\n",t);
	 return 0; 
}
 
 
