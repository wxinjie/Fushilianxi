//向量动态管理：1.产生新向量，长度翻倍 2.旧向量中的值迁移至新向量 3.删除旧向量 

#include<iostream>
#include<cstdio>
#include<vector>
 
using namespace std;

vector<int> myVector;

int main(){
	for(int i = 0; i < 5; ++i){
		myVector.push_back(i);	//从尾部逐一插入元素 
	}	
	myVector.insert(myVector.begin(),3,15); //头部插入3个15
	myVector.pop_back();
	for(int i = 0; i < myVector.size(); ++i){
		printf("%d ",myVector[i]);
	}
	printf("\n");
	printf("the 5th element of myVector:%d\n",myVector[4]);
	printf("the size of myVector: %d\n",myVector.size());
	myVector.erase(myVector.begin() + 5,myVector.end()); //删除第五个元素后续的元素
	vector<int>::iterator it;	//定义迭代器
	for(it = myVector.begin(); it != myVector.end(); it++){
		printf("%d ",*it);			//遍历向量 
	} 
	printf("\n");
	myVector.clear();	
	return 0;
}
