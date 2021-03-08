#include<iostream>
#include<cstdio>

using namespace std;

int GCD(int a, int b){
	if(b == 0){
		return a;
	} else {
		GCD(b, a % b);
	}
}

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b) != EOF){
		printf("%d\n",GCD(a,b));
	} 
	return 0;
}
