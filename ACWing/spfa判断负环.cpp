//spfa�жϸ�����  ��һ��cnt[]����¼�����ı���    ÿ��ִ��dist[b] = dist[t] + w ʱ ���£�cnt[x] = cnt[t] + 1;
//����һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի�����Ȩ����Ϊ�������ж�ͼ���Ƿ���ڸ�Ȩ��·��
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
int h[N], w[N], e[N], ne[N], idx;//��Ϊ��ϡ��ͼ�������ڽӱ�ʽ   w:Ȩ��  
int dist[N], cnt[N];//cnt:���� 
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
	//����Ҫ��ʼ���ˣ���Ϊ��ò��Ǿ���ľ���ֵ 
	queue<int> q;//�洢���д����µĵ� 
	for(int i = 1; i <= n; i++) //������һ����һ�ŵ㿪ʼ�����԰����е�ӽ�ȥ 
	{
		st[i] = true;
		q.push(i);
	}
	
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
				cnt[j] = cnt[t] + 1;
				if(cnt[j] >= n) return true; 
				if(!st[j])//��j���ڶ�����ʱ�ż��� 
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
	//��ʼ��
	memset(h, -1 ,sizeof h);
	
	//����m����
	while(m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);//���ڽӱ�棬�ر�����ν�����ȶ��лᱣ֤ѡ��С�� 
	 } 
	 if(spfa()) puts("Yes");
	 else puts("No");
	 return 0; 
} 
