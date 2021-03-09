#include<iostream>
#include<cstdio>

using namespace std;

long long jiecheng(int n){
	if(n == 0){
		return 1;
	} else {
		return jiecheng(n - 1) * n;
	}
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		printf("%lld\n",jiecheng(n));
	} 
	return 0;
} 
