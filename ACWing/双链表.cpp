//����ģ��˫���� l[N]  r[N]   0�Ŵ���head 1�Ŵ���end
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
output
6 4 6 5
*/
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int m;
int l[N], r[N], e[N], idx;

//��ʼ����0��ʾ��˵㣬1��ʾ�Ҷ˵� 
void init()
{	
	r[0] = 1;
	l[1] = 0;
	idx = 2; 
 } 

//�ڵ�k������ұ߲���x 
void add(int k, int x)
{
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	r[k] = idx;
	l[r[idx]] = idx++;	
}

//���±���k�ĵ�ĺ�����ɾ��
void remove(int k)
{
	r[l[k]] = r[k];
	l[r[k]] = l[k];
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
			add(0, x);
		}
		else if(op == 'D')
		{
			cin >> k;
			if(!k) r[0] = r[r[0]], l[r[0]] = 0;
			remove(r[k + 1]);            //???
		}
		else 
		{
			cin >> k >> x;
			add(k + 1, x);
		}
	}
	
	for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
	cout << endl;
	
	
	return 0;
}
