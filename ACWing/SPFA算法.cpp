//SPFA�㷨����bellman-ford���Ż���dist[b]ֻ����dist[a]����С������²��п��ܱ�С   ***һ�������Ч�ʱ�����dijkstraЧ��Ҫ�ߣ�������������˾�ֻ�ܻ����Ż���dijkstra 
/*
queue  <-- 1
while ���в���
	t <-- q.front
	q.pop()
	����t�����г��� t->b(w)
	queue <--b 
*/

//����һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի�,���б�Ȩ��Ϊ��ֵ�����бߵĳ��ȶ���1����ı��Ϊ1~n�����1�ŵ㵽n�ŵ����̾��룬�����޷���1�ŵ��ߵ�n�ŵ㣬���-1 
//��һ��n��m ������m��ÿ�а�����������x�� y�� z����ʾx��y֮�����һ������ߣ��߳�Ϊz��
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
int h[N], w[N], e[N], ne[N], idx;//��Ϊ��ϡ��ͼ�������ڽӱ�ʽ   w:Ȩ��  
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
	queue<int> q;//�洢���д����µĵ� 
	q.push(1);
	st[1] = true;//st�浱ǰ���Ƿ��ڶ�����
	while(q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false; 
		
		//����t�������ڱ�
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])//��j���ڶ�����ʱ�ż��� 
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
	//��ʼ��
	memset(h, -1 ,sizeof h);
	
	//����m����
	while(m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);//���ڽӱ�棬�ر�����ν�����ȶ��лᱣ֤ѡ��С�� 
	 } 
	 int t = spfa();
	 if(t == -1) puts("impossible");
	 else printf("%d\n",t);
	 return 0; 
}
 
 
 
