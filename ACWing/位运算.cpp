//λ���� n�Ķ����Ʊ�ʾ�е�kλ�Ǽ� ˼·��1.�Ȱѵ�kλ���Ƶ����һλ n >> k 2.����λ�Ǽ�: x & 1
#include<iostream>

using namespace std;

int main()
{
	int n = 10;
	for(int k = 3; k >= 0; k--) cout << (n >> k & 1);
	return 0;
} 

//lowbit(x):����x�����һλ1    x = 101000  lowbit(x) = 1000  lowbit�����߼� x & -x ��  -x = ~x + 1    ->  x & (~x + 1)
//Ӧ�ã�ͳ��x���������ж���1 
