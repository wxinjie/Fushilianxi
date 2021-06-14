#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int e[N], l[N], r[N], idx, n;

void init()
{
	r[0] = 1;
	l[1] = 0;
	idx = 2;
}

void head_add(int x)
{
	e[idx] = x;
	r[idx] = r[0];
	l[r[idx]] = idx;
	r[0] = idx;
	l[idx] = 0;
	idx ++; 
}

void add(int k, int x)
{
	e[idx] = x;
	r[idx] = r[k];
	l[r[idx]] = idx;
	r[k] = idx;
	l[idx] = k;
	idx ++;
}

void del(int k)
{
	l[r[k]] = l[k];
	r[l[k]] = r[k];
}

int main()
{
	cin >> n;
	init();
	while(n--)
	{
		char op;
		cin >> op;
		int k, x;
		if(op == 'H')
		{
			cin >> x;
			head_add(x);
		}
		else if(op == 'D')
		{
			cin >> k;
			if(k == 0)
			{
				r[0] = r[r[0]];
				l[r[0]] = 0;
			}
			del(r[k + 1]);
		}
		else
		{
			cin >> k >> x;
			add(k + 1, x);
		}
	}
	
	for(int i = r[0]; i != 1; i = r[i]) printf("%d ", e[i]);
	return 0;
}












