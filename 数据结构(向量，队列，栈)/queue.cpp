//queue ��� ���� �п� ���ʶ���
#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main(){
	queue<int> myQueue;
	
	for(int i = 0; i < 5; ++i){
		myQueue.push(i);	//��� 
	}	
	int sum = 0;
	while(!myQueue.empty()){	//�п� 
		sum += myQueue.front();	//���ʶ���Ԫ�� 
		myQueue.pop();			//���� 
	}
	printf("%d\n",sum);
	return 0;
} 
