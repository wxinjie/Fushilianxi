#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

const int MAXN = sqrt(1e9) + 1;

vector<int> prime;
bool isprime[MAXN];

void Initial(){
	for(int i = 0; i < MAXN; ++i){
		isprime[i] = true;
	}
	isprime[0] = false;
	isprime[1] = false;
	for(int i = 0; i < MAXN; ++i){
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
	Initial();
	int n;
	while(scanf("%d",&n) != EOF){
		int count = 0;
		for(int i = 0; i < prime.size() && prime[i] < n; ++i){
			while(n % prime[i] == 0){
				count++;
				n /= prime[i];
			} 
		}
		if(n > 1){
			count++;
		}
		printf("%d\n",count);
	}
	
	
	
	return 0;
}
