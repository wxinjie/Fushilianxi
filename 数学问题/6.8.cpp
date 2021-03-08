#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MAXN = 10000 + 1;

vector<int> prime;
bool isprime[MAXN];

void initial(){
	for(int i = 0; i < MAXN; ++i){
		isprime[i] = true;
	}
	isprime[0] = false;
	isprime[1] = false;
	for(int i = 2; i < MAXN; ++i){
		if(!isprime[i]){
			continue;
		}
		prime.push_back(i);
		for(int j = i * i; j < MAXN; j+=i){
			isprime[j] = false;
		}
	}
	return ;
}

int main(){
	initial();
	int n;
	int p = 0;
	while(scanf("%d",&n) != EOF){
		for(int i = 0; i < prime.size() && prime[i] < n;++i){
			if(prime[i] % 10 == 1){
				printf("%d ",prime[i]);
				p++;
			}
		}
		if(p == 0){
			printf("-1");
		}
		printf("\n");
	}
}
