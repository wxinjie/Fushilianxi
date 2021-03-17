#include<iostream>
#include<cstdio>

using namespace std;

int value(int A[]){
	int sum = 0;
	for(int i = 0; i < 5; i++) sum += A[i];
	for(int i = 0; i < 3; i++){
		for(int j = i + 1; j < 4; j++){
			for(int k = j + 1; k < 5; k++){
				if((A[i] + A[j] + A[k]) % 10 == 0){
					return (sum - A[i] - A[j] - A[k]) % 10;
				} 
			}
		}
	}
	return -1;
}

int main() {
	int n;
	scanf("%d",&n);
	int A[5];
	while(n--){
		for(int i = 0; i < 5; i++) scanf("%d",&A[i]);
		printf("%d\n",value(A));
	}
	return 0;
}
