//����Ѱַ��
#include<iostream>
#include<cstring>

using namespace std;

const int N = 200003, null =  0x3f3f3f3f;//null����x��Χ�� 

int h[N];

int find(int x) //����ֵ���������壺���x�ڹ�ϣ���У�����x���±ꣻ��� x���ڹ�ϣ���У�����xӦ�ò����λ�� 
{
	int k = (x % N + N) % N;
	while(h[k] != null && h[k] != x)
	{
		k++;
		if(k == N) k = 0;
	}
	return k;
 } 
 
int main()
{
	int n;
	scanf("%d", &n);
	char op[2];
	int x;
	memset(h, null, sizeof(h));
	while(n--)
	{	
		scanf("%s%d", op, &x);
		int k = find(x);
		if(op[0] == 'I')
		{
			h[k] = x;
		}
		else
		{
			if(h[k] != null) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
