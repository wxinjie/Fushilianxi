#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main(){
	unsigned int number;
	while(scanf("%d",&number) != EOF){
		stack<int> arr;
		while(number != 0){
			arr.push(number % 2);
			number /= 2;
		}
		while(!arr.empty()){
			printf("%d",arr.top());
			arr.pop();
		}
		printf("\n");
	}
	return 0;
}
