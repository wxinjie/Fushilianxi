//Trie:��Ч�Ĵ洢�Ͳ����ַ������ϵ����ݽṹ
//I x:�򼯺��в���һ���ַ���x		Q x:��ѯһ���ַ����ڼ����г����˶��ٴ� 			����N������		�ַ���������СдӢ����ĸ
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

int son[N][26];//ÿ�������ӽ�������26����
int cnt[N];//�Ե�ǰ���Ϊ��β���ַ����ж��ٸ�
int idx;//��ǰ�õ����±꣬�±���0�ĵ㣬���Ǹ���㣬���ǿս��
char str[N];

void insert(char str[])
{
	int p = 0;
	for(int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if(!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}//	P����ָ�����һ����ĸ����λ�� 
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
 
