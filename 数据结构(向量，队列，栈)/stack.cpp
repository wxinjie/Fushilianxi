#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;
stack<int> myStack;

int main(){
	printf("the size of myStack:%d\n",myStack.size());
	for(int i = 0; i < 10; ++i){
		myStack.push(i);
	}
	printf("the top of myStack: %d\n",myStack.top());
	printf("the size of myStack: %d\n",myStack.size());
	int sum = 0;
	while(!myStack.empty()){
		sum += myStack.top();
		myStack.pop();
	}
	printf("%d\n",sum);
	if(myStack.empty()){
		printf("mystack is empty!\n");
	}
	return 0; 
}
