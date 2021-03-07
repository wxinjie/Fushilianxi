#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct Animal{
	int number;
	int order;
	Animal(){
	}
	Animal(int n, int o): number(n), order(o) {
	}
};

queue<Animal> cats;
queue<Animal> dogs;

int main(){
	int n;
	scanf("%d",&n);
	int order = 0;
	for(int i = 0; i < n; ++i){
		int event;
		scanf("%d",&event);
		if(event == 1){
			int number;
			scanf("%d",&number);
			if(number > 0){
				dogs.push(Animal(number,order++)); 
			}else{
				cats.push(Animal(number,order++)); 
			}
		} else{
			int type;
			scanf("%d",&type);
			if(type == 0 && !dogs.empty() && !cats.empty()){
				if(dogs.front().order < cats.front().order){
					printf("%d ",dogs.front().number);
					dogs.pop();
				} else {
					printf("%d ",cats.front().number);
					cats.pop();
				}
			} else if(type == 0 && dogs.empty() && !cats.empty()){
				printf("%d ",cats.front().number);
				cats.pop();
			} else if(type == 0 && !dogs.empty() && cats.empty()){
				printf("%d ",dogs.front().number);
				dogs.pop();
			} else if(type == 1 && !dogs.empty()){
				printf("%d ",dogs.front().number);
				dogs.pop();
			} else if (type == -1 && !cats.empty()){
				printf("%d ",cats.front().number);
				cats.pop();
			}
		}
	}
	printf("\n");
	return 0;
}
