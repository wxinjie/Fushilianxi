//œﬂ–‘≤È’“
#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 100 +10;

int arr[MAXN];



bool LinearSearch(int n,int target){
	for(int i = 0;i < n;++i){
		if(arr[i] == target){
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
	int m;
	scanf("%d",&m);
	while(m--){
		int target;
		scanf("%d",&target);
		if(LinearSearch(n,target)){
			printf("YES\n");
		}else {
			printf("NO\n");
		}
		
		
	}
	
	return 0;
}
