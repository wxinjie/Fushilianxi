//���ֲ���-2.ϵͳ�Դ�
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100 +10;

int arr[MAXN];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;++i){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int m;
	scanf("%d",&m);
	while(m--){
		int target;
		scanf("%d",&target);
		int position = lower_bound(arr ,arr + n, target) - arr;//��ȥ��ʼ��ַ�õ��±� 
		if(position != n && arr[position] == target){ //����target��������ֵ�Լ�target�������в������������ 
			printf("YES\n");
		}else {
			printf("NO\n");
		}	
	}	
	return 0;
}
