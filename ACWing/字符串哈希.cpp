//�ַ���ǰ׺��ϣ--�����ж������ַ����Ƿ����  abcabc  :h[0] = 0;h[1] = "a"�Ĺ�ϣֵ ��h[2] = "ab"�Ĺ�ϣֵ......
//˼�룺 ���ַ������һ��p���Ƶ��� ABCD= (1*P^3 + 2*P^2 + 3*P + 4*P^0) mod Q ,Q��һ����С�����������͵õ����ַ�����Ӧ��0~Q-1֮�����
//ע�⣺����ӳ���0����ͻ��a=aa=aaa...)
//�����ǳ�ͻ�������һ��ȡp = 131��13331 Q  = 2^64
//�ô�����������ǰ����õ�hash�������һ���Ӷε�hash      1.....l....r  ------->  l......r = H[r] - h[l] * p^r-l+1  h[i] = h[i-1] * p + str[i]
/*
����һ������Ϊn���ַ������ٸ���m��ѯ�ʣ�ÿ��ѯ�ʰ����ĸ�����l1��r1��l2��r2���ж�[l1��r1]��[l2��r2]�������������������ַ����Ӵ��Ƿ���ȫ��ͬ���ַ�����ֻ������СдӢ����ĸ
�����֡��ַ���λ�ô�1��ʼ��š�
8 3
aabbaabb
1 3 5 7
1 3 6 8
1 2 1 2
output
yes 
no
yes
*/
#include<iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 131;

int n, m;
char str[N];
ULL h[N], p[N];//p��p�Ķ��ٴη�

ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	scanf("%d%d%s", &n, &m, str + 1);
	
	p[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + str[i];
	}
	while(m--)
	{
		int l1,r1,l2,r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if(get(l1, r1) == get(l2, r2)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
 } 

 

 

 
