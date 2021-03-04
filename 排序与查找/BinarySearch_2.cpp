//二分查找-2.系统自带
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
		int position = lower_bound(arr ,arr + n, target) - arr;//减去初始地址得到下标 
		if(position != n && arr[position] == target){ //考虑target大于所有值以及target在数组中不存在两种情况 
			printf("YES\n");
		}else {
			printf("NO\n");
		}	
	}	
	return 0;
}
