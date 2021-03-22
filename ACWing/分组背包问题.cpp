//���鱳�����⣺N����Ʒ������ΪV�ı�����ÿ����Ʒ�����ɸ���ͬһ���ڵ���Ʒ���ֻ��ѡһ����ÿ����Ʒ�������vij����ֵ��wij i����ţ�j�����ڱ��
//���� N V N�У���һ��si��ʾ��i����Ʒ������si�� 

/*

													ֻ��ǰi����Ʒ��ѡ�����������������j������ѡ�� 
											���� 
													
		״̬��ʾ f��i��j�� ��ά��ʾ 
											���� ��Max�����⣩�� Min������ 
DP 
  
		״̬���� 	���ϻ��֣�1~i-1,i��  1.���� 2.��©     f[i][j] = max(f[i - 1][j] , f[i - 1][j - v[i,k]] + w[i,k]);  v[i,k]:��i���k�� 
*/  
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		for(int j = 0; j < s[i]; j++)
			cin >> v[i][j] >> w[i][j];
	}
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= 0; j--)
			for(int k = 0; k < s[i]; k++)
				if(v[i][k] <= j) 
					f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
	cout << f[m] << endl;
	
	return 0;
}
 










