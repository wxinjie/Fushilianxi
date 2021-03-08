#include<iostream>
#include<cstdio>

using namespace std;

int Fast(int a, int b){
	int answer = 1;
	while(b != 0){
		if(b % 2 == 1){
			answer *= a;
			answer %= 1000;
		}
		b /= 2;
		a *=a;
		a %= 1000;
	}
	return answer;
}

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b) != EOF){
		if(a == 0 && b == 0){
			break;
		} else {
			printf("%d\n",Fast(a,b));
		}
	}
	return 0;
}
