//最长连续不重复子序列
/*
5
1 2 2 3 5
output
3
*/
/*
朴素做法：
for(int i = 0; i < n; i++)
	for(int j = 0; j <= i; j++)
		if(check(i,j))
		{
			res = max(res, i - j + 1);
	  	}
	  	
优化思路：i,j都具有单调性，只能往右
j：j往左走最远能到什么地方
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
/*双指针总结：
 1.对于一个序列，两个指针维护一段区间
 2.对于两个序列，维护某种次序，比如归并排序中维护两个有序序列的操作
 */ 











 
