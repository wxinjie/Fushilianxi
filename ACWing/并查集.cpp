/*
���鼯��
1.���������Ϻϲ�
2.ѯ������Ԫ���Ƿ���ͬһ������
˼�룺����������ÿһ�����ϣ������ı�ž��ǵ�ǰ���ϵı�ţ�ÿһ���㶼�洢���ĸ��ڵ���˭ p[x]��ʾx�ĸ��ڵ㡣
����1������ж������� if(p[x] == x)
����2�������x�ļ��ϱ�ţ���while(p[x] != x) x = p[x];
����3����κϲ��������ϣ�p[x]��x�ļ��ϱ�ţ�p[y]��y�ļ��ϱ�š�p[x] = y 
·��ѹ���Ż����ҵ�x�ĸ�����·���ϵ����н�㶼ָ������ 
*/ 

//һ����n���������1~n-1���ʼÿ��������һ�������С�����m�β����� 1.M a b :�����Ϊa��b�����������ڼ��Ϻϲ� 2.Q a b ��ѯ�ʱ��Ϊa��b���������Ƿ���ͬһ�������� 
/*
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
yes
no
yes
*/
#include<iostream>

using namespace std;

const int N = 100010;

int n, m, p[N];

int find(int x)	//����x�����ڽڵ�+·��ѹ�� 
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x]; 
 } 

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) p[i] = i; 
	
	while(m--)
	{	
		char op[2];
		int a, b;
		scanf("%s %d%d",op, &a, &b);
		if(op[0] == 'M')
		{
			p[find(a)] = find(b);
		}
		else
		{
			if(find(a) == find(b)) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;	
 } 
 
