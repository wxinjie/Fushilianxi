//queue 入队 出队 判空 访问队首
#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main(){
	queue<int> myQueue;
	
	for(int i = 0; i < 5; ++i){
		myQueue.push(i);	//入队 
	}	
	int sum = 0;
	while(!myQueue.empty()){	//判空 
		sum += myQueue.front();	//访问队首元素 
		myQueue.pop();			//出队 
	}
	printf("%d\n",sum);
	return 0;
} 
