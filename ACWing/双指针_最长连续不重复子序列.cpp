//��������ظ�������
/*
5
1 2 2 3 5
output
3
*/
/*
����������
for(int i = 0; i < n; i++)
	for(int j = 0; j <= i; j++)
		if(check(i,j))
		{
			res = max(res, i - j + 1);
	  	}
	  	
�Ż�˼·��i,j�����е����ԣ�ֻ������
j��j��������Զ�ܵ�ʲô�ط�
*/
#include<iostream>

using namespace std;

const int N = 1e5;

int n;
int a[N], s[N];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	int res = 0;
	for(int i = 0,j = 0; i < n; i++)
	{
		s[a[i]]++;
		while(s[a[i]] > 1)
		{
			s[a[j]]--;
			j++;
		}
		res = max(res, i - j + 1);
	}
	cout << res << endl;
	
	return 0;
}
/*˫ָ���ܽ᣺
 1.����һ�����У�����ָ��ά��һ������
 2.�����������У�ά��ĳ�ִ��򣬱���鲢������ά�������������еĲ���
 */ 











 
