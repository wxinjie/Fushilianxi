//二分查找-  1.自定义（必须是有序序列！）
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100 +10;

int arr[MAXN];


bool BinarySearch(int n,int target){
	int left = 0;
	int right = n - 1;
	while(left <= right){
		int middle = left + (right - left)/2;
		if(arr[middle] < target){
			left = middle + 1;
		}else if(arr[middle] > target){
			right = middle - 1;
		}else{
			return true;
		}
	}
	return false; 
}



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
		if(BinarySearch(n,target)){
			printf("YES\n");
		}else {
			printf("NO\n");
		}
		
		
	}
	
	return 0;
}
