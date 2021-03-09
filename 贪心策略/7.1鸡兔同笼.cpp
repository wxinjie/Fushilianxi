#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		if(n % 2 != 0){
			printf("0 0\n");
		} else {
			int minnumber = n/4;
			if(n % 4 == 2){
				minnumber++; 
			}
			int maxnumber = n/2;
			printf("%d %d\n",minnumber,maxnumber);
		}
	}
	return 0;
}
