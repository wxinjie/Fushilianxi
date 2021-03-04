//哈希查找：1.自定义
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100 +10;
const int RANGE = 1e6; 
int arr[MAXN];

bool hashTable[RANGE]; //哈希表 用最简单的H（value) = value 


int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;++i){
		scanf("%d",&arr[i]);
		hashTable[arr[i]] = true;
	}
	//sort(arr,arr+n);
	int m;
	scanf("%d",&m);
	while(m--){
		int target;
		scanf("%d",&target);
		if(hashTable[target]){  
			printf("YES\n");
		}else {
			printf("NO\n");
		}		
	}
	return 0;
}
