//��ȫ���������һ���Ż���һά���飩 
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	
	for(int i = 1; i <= n; i++)
		for(int j = v[i]; j <= m; j++)
			f[j] = max(f[j], f[j - v[i]] + w[i]);// !!! �����Ǻ�01��������������ĵط���01Ҫ����i- 1�㣬��ȫ�����Ż���Ҫ����i�㣬��ʱj��v[i]��ʼ��j - v[i]�Ѿ�������ˣ����ڵ�i�㣬�պú��� 
			
	cout << f[m] << endl;
	return 0;
}
