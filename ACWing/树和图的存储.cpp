//����ͼ�Ĵ洢  ����һ�������ͼ���޻���ͨͼ��ֻ��ͼ���ɣ�ͼ��Ϊ����ͼ������ͼ �洢��ʽ���ڽӾ����ڽӱ�
//�������ģ�����һ���������а���n����㣨���1~n)��n - 1������ߡ����������ģ������������ɾ����ʣ�������ͨ���е��������ֵ��
//���Ķ��壺������ָ���е�һ����㣬����������ɾ����ʣ�������ͨ���е��������ֵ��С����ô����ڵ㱻��Ϊ��������
//�����һ������n��n-1�б�ʾa��b���ڱ� 
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
int h[N], e[M], ne[M], idx;//h��ÿ�����������ͷ��e��ÿ������ֵ��ne��nextָ��
bool st[N];//�����Щ�ڵ������ 
int ans = N;//��� 

void add(int a, int b)	//�����aָ��b�ı� 
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++; 
}

//��uΪ���������е������ 
int dfs(int u)
{
	st[u] = true;//��ǵ�ǰ���ѱ�������
	
	int sum = 1, res = 0;//sum��¼��ǰ�������  res��¼ÿ����ͨ������ֵ 
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];//��ǰ�ڵ���ͼ�еı���Ƕ���
		if(!st[j]) 
		{
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		} 
	 } 
	 
	 res = max(res, n - sum); //���������е�������Ƚ�ѡ�����ֵ
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

 
