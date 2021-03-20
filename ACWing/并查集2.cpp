//并查集2：附加格外信息：每个集合（连通块）内的个数
/*
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5
OUTPUT
Yes
2
3
*/
#include<iostream>

using namespace std;

const int N = 100010;

int n, m, p[N], size[N];

int find(int x)
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x]; 
 } 
 
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		p[i] = i;
		size[i] = 1;
	}
	while(m--)
	{
		char op[2];
		int a, b;
		scanf("%s", op);
		if(op[0] == 'C')
		{
			scanf("%d%d", &a, &b);
			size[find(b)] += size[find(a)];
			p[find(a)] = find(b);
		}
		else if(op[1] == '1')
		{
			scanf("%d%d", &a, &b);
			if(find(a) == find(b)) printf("Yes\n");
			else printf("No\n");
		}
		else
		{
			scanf("%d", &a);
			printf("%d\n",size[find(a)]); 
		}
	}
	return 0;
}
