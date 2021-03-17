/*
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
OUTPUT
6 4 6 5
*/
#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int head, e[N], ne[N], idx;// head:头结点，e:第k个结点的值，ne:第k个结点的next指针，idx：下一个可用结点 

void init()
{
	head = -1;
	idx = 0;
}

void add_to_head(int x) //新元素插入头结点 
{
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx++;
}

void add(int k, int x) //x插入到下标为k的结点后面 
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++; 
 } 
 
void remove(int k)	//将下标是k的点的后面结点删掉
{
	ne[k] = ne[ne[k]]; 
 } 

int main()
{
	int m;
	cin >> m;
	init();
	while(m--)
	{
		int k, x;
		char op;
		cin >> op;
		if(op == 'H')
		{
			cin >> x;
			add_to_head(x);
		}
		else if(op == 'D')
		{
			cin >> k;
			if(!k) head = ne[head];
			remove(k - 1);
		}
		else 
		{
			cin >> k >> x;
			add(k - 1, x);
		}
	}
	
	for(int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
	cout << endl;
	
	return 0;
}
