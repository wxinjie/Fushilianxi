//字符串前缀哈希--快速判断两个字符串是否相等  abcabc  :h[0] = 0;h[1] = "a"的哈希值 ；h[2] = "ab"的哈希值......
//思想： 把字符串想成一个p进制的数 ABCD= (1*P^3 + 2*P^2 + 3*P + 4*P^0) mod Q ,Q是一个较小的数，这样就得到了字符串对应的0~Q-1之间的数
//注意：不能映射成0，冲突（a=aa=aaa...)
//不考虑冲突的情况，一般取p = 131或13331 Q  = 2^64
//好处：可以利用前面求得的hash算出任意一个子段的hash      1.....l....r  ------->  l......r = H[r] - h[l] * p^r-l+1  h[i] = h[i-1] * p + str[i]
/*
给定一个长度为n的字符串，再给定m个询问，每个询问包含四个整数l1，r1，l2，r2，判断[l1，r1]和[l2，r2]这两个区间所包含的字符串子串是否完全相同。字符串中只包含大小写英文字母
和数字。字符串位置从1开始编号。
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
ULL h[N], p[N];//p存p的多少次方

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

 

 

 
