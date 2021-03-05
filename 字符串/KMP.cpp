#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 100;
int nextTable[MAXN];

void GetNextTable(string pattern){
	int m = pattern.size();
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


int KMP(string text, string pattern){
	GetNextTable(pattern);
	int n = text.size();
	int m = pattern.size();
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
			return i - j; 
		}else {
			return -1;
		}  
}

int main(){
	string text,pattern;
	cin >> text >> pattern;
	int position = KMP(text,pattern);
	cout << position << endl;
	
	return 0;
}
