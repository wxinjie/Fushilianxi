#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 1000000;
const int MAXM = 10000;
int nextTable[MAXM];
int pattern[MAXM];
int text[MAXN];

void GetNextTable(int m){ 
	int j = 0;
	nextTable[j] = -1;
	int t = nextTable[j];
	while(j < m){
		if(t == -1 || pattern[j] == pattern[t]){
			t++;
			j++;
			nextTable[j] = t;
		}else {
			t = nextTable[t];  
		}
	}
	return ;
}


int KMP(int n, int m){
	GetNextTable(m);
	int i = 0; //当前文本串匹配的下标
	int j = 0; //当前模式串匹配的下标
	while(i < n && j < m){
		if(j == -1 || text[i] == pattern[j]){
			i++;
			j++;
		}else {
			j = nextTable[j]; //当前字符匹配失败 
		}
	}
	if(j == m){
			return i - j + 1; 
		}else {
			return -1;
		}  
}

int main(){
	int CaseNumber;
	scanf("%d",&CaseNumber);
	while(CaseNumber--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; ++i){
			scanf("%d",&text[i]);
		}		
		for(int j = 0; j < m; ++j){
			scanf("%d",&pattern[j]);
		}
		printf("%d\n",KMP(n,m));
	}
	
	return 0;
}
