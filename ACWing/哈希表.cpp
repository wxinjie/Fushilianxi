/*
��ϣ��   1.�洢�ṹ,�����ͻ��ʽ������Ѱַ����������    2.�ַ�����ϣ��ʽ
*/
//����n�β�����ά��һ������ �� I x������һ����x     Q x��ѯ����x�Ƿ��ڼ����г��ֹ�      n<=10^5    -10^9 =< x <= 10^9 

//������ 
/*5
I 1
I 2
I 3
Q 2
Q 5
output
yes
no
*/
#include<iostream> 
#include<cstring>
using namespace std;

const int N = 1e5 + 3;
/*
for(int i = 100000; ; i++)
	{
		bool flag = true;
		for(int j = 2; j * j <= i; j++)
		{
			if(i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout << i << endl;
			break;
		}
	}
*/

int h[N], e[N], ne[N], idx;//h:�� 

void insert(int x)
{
	int k = (x % N + N) % N;//+N��Ϊ���ý���������
	e[idx] = x, ne[idx] = h[k], h[k] = idx++; 
}

bool find(int x)
{
	int k = (x % N + N) % N;
	for(int i = h[k]; i != -1; i = ne[i])
		if(e[i] == x)
			return true;
	
	return false; 
 } 

int main()
{
	int n;
	scanf("%d", &n);
	memset(h, -1, sizeof(h));
	
	while(n--)
	{
		char op[2];
		int x;
		scanf("%s%d", op, &x);
		if(op[0] == 'I') insert(x);
		else
		{
			if(find(x)) puts("yes");
			else puts("no");
		}
	}
 } 
