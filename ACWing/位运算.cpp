//位运算 n的二进制表示中第k位是几 思路：1.先把第k位右移到最后一位 n >> k 2.看个位是几: x & 1
#include<iostream>

using namespace std;

int main()
{
	int n = 10;
	for(int k = 3; k >= 0; k--) cout << (n >> k & 1);
	return 0;
} 

//lowbit(x):返回x的最后一位1    x = 101000  lowbit(x) = 1000  lowbit背后逻辑 x & -x ：  -x = ~x + 1    ->  x & (~x + 1)
//应用：统计x二进制中有多少1 
