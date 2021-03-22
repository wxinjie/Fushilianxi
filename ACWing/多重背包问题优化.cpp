//���ر��������Ż�
/*
������˼�룺
 1+2+4+8+ ... 2^k + c = s    eg:s=200    1 2 4 ... 64, c = 73  ���ܱ�ʾ��1~200��ÿ����        ����Ʒ���в��s -�� logs���飬��ÿ�������һ��01��������

 �������� NVS���Ӷȵ���������Ż�ΪNVlogS
 */
 
/*
3 5
2
1 2
2 4
1
3 4
1
4 5
output
8
*/
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 25000, M = 2010;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
	cin >> n >> m;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int a, b, s;
		cin >> a >> b >> s;
		int k = 1;
		while(k <= s)
		{
			cnt++;
			v[cnt] = a * k; //���
			w[cnt] = b * k;
			s -= k;
			k *= 2; 
		}
		if(s > 0)
		{
			cnt++;
			v[cnt] = a * s;
			w[cnt] = b * s;
		}
	}
	n = cnt;
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	
	cout << f[m] << endl;
	
	return 0;
	
  }  
