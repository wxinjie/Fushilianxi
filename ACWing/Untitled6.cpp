//����Ѱַ��
#include<iostream>
#include<cstring>

using namespace std;

const int N = 200003, null =  0;//null����x��Χ�� 

int h[N];

int find(int x) //����ֵ���������壺���x�ڹ�ϣ���У�����x���±ꣻ��� x���ڹ�ϣ���У�����xӦ�ò����λ�� 
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
