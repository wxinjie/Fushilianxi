//Trie:高效的存储和查找字符串集合的数据结构
//I x:向集合中插入一个字符串x		Q x:查询一个字符串在集合中出现了多少次 			共有N个操作		字符串仅包含小写英文字母
/*
5
I abc
Q abc
Q ab
I ab
Q ab
output
1
0
1
*/
#include<iostream>

using namespace std;

const int N = 100010;

int son[N][26];//每个结点的子结点最多连26条边
int cnt[N];//以当前结点为结尾的字符串有多少个
int idx;//当前用到的下标，下标是0的点，既是根结点，又是空结点
char str[N];

void insert(char str[])
{
	int p = 0;
	for(int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if(!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}//	P最终指向最后一个字母所在位置 
	cnt[p]++;
 } 
 
int query(char str[])
{
	int p = 0;
	for(int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if(!son[p][u]) return 0;
		p = son[p][u];
	}
	return cnt[p];
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		char op[2];
		cin >> op >> str;
		if(op[0] == 'I') insert(str);
		else cout << query(str) << endl;
	}
	return 0;
}
 
