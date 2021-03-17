//开放寻址法
#include<iostream>
#include<cstring>

using namespace std;

const int N = 200003, null =  0;//null不在x范围内 

int h[N];

int find(int x) //返回值有两个含义：如果x在哈希表中，返回x的下标；如果 x不在哈希表中，返回x应该插入的位置 
{
	int k = (x % N + N) % N;
	
	return k;
 } 
 
int main()
{
	memset(h, 0x3f, sizeof(h));
	cout << null << endl;
	cout << h[101] << endl;
	printf("**%d",find(101));
	return 0;
}
