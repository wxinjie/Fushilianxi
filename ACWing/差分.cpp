//ǰ׺�Ͳ��     a��b��ǰ׺�ͣ�b��a�Ĳ�֣��� ai = bi + bi-1 +...+ b1  (a1 = b1 ,a2 - a1 = b2,...);  
//����Ҫ�� al-arȫ������c����al + c, al+1 + c,...ar + c
//�ⷨ��bl + c(�������ò����aʱal֮������������c)��Ȼ��br+1 - c(����ar֮������ղż��ϵ�c�ͱ���������)
//����ֻ���޸���������ֻ��Ҫ��O(1)��ʱ��������е�һ����ȫ������ĳ����ֵ
/*
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
output:
3 4 5 3 4 2
*/
#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N],b[N];
int n,m;

void insert(int l, int r, int c){
	b[l] += c;
	b[r + 1] -= c;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	
	for(int i = 1; i <= n; i++) insert(i, i, a[i]);
	
	while(m--){
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		insert(l,r,c);
	} 
	for(int i = 1; i <= n; i++) b[i] += b[i - 1];
	for(int i = 1; i <= n; i++) printf("%d ",b[i]);
} 
