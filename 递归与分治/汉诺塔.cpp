#include<iostream>
#include<cstdio>

using namespace std;

long long Function(int n){
	if(n == 1){
		return 2;
	} else {
		return 3 * Function(n - 1) + 2;
	}
}

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		printf("%lld\n",Function(n));
	}
	return 0;
}
