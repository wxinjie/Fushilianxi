//���Ż���Dijkstra  t����s��һ��������ö�����t���Ϳ����Խ��͸��Ӷ�       ��ʵ�ַ�����1.��д�ѣ��ܶ�ӳ��Ƚϸ���   2.���ȶ��У�����֧���޸�����һ��Ԫ��
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

typedef pair<int, int> PII;//����ά������һ��pair<���룬���> 

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;//��Ϊ��ϡ��ͼ�������ڽӱ�ʽ   w:Ȩ��  
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
	
	priority_queue<PII, vector<PII>, greater<PII> > heap; //С����
	heap.push({0, 1});        //��һ������֪��ֱ�ӷ���
	
	while(heap.size())
	{
		PII t = heap.top(); //�ҵ�������С�ĵ� 
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
	//��ʼ��
	memset(h, -1 ,sizeof h);
	
	//����m����
	while(m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);//���ڽӱ�棬�ر�����ν�����ȶ��лᱣ֤ѡ��С�� 
	 } 
	 int t = dijkstra();
	 printf("%d\n",t);
	 return 0; 
}
 
 
