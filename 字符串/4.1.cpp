#include<iostream>
#include<cstdio>
#include<string>


using namespace std;

const int MAXN = 100;
int arr[MAXN];

int main(){
	int t;
	scanf("%d",&t);
	string str;
	while(t--){
		cin >> str;
		for(int i = 0; i < str.size(); ++i){
			arr[str[i] - 'a']++;
		}
		int number = 0;
		for(int j = 0; j < MAXN; ++j){
			if(arr[j] == 1){
				printf("%c\n",j + 'a');
				break;
			}else {
				number++;
			}
		}
		if(number == MAXN){
			printf("NO\n");
		}
		
	}
	
	return 0;
} 
