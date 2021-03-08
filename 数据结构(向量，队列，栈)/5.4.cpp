#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

stack<long long> sequence;

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i = 0; i < n; ++i){
			long long number;
			scanf("%I64d",&number);
			sequence.push(number);
		}
		while(!sequence.empty()){
			printf("%I64d ",sequence.top());
			sequence.pop();
		}
		printf("\n");
	}
	return 0;
}
