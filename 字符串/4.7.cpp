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
	int i = 0; //��ǰ�ı���ƥ����±�
	int j = 0; //��ǰģʽ��ƥ����±�
	int number = 0;
	while(i < n && j < m){
		if(j == -1 || text[i] == pattern[j]){
			i++;
			j++;
		}else {
			j = nextTable[j]; //��ǰ�ַ�ƥ��ʧ�� 
		}
		if(j == m){
			number++;
			j = nextTable[j]; //�����ַ��ص���ƥ��
			//j = 0;             �������ַ��ص���ƥ�� 
		} 
	}
	return number;
	
}

int main(){
	int caseNumber;
	scanf("%d",&caseNumber);
	while(caseNumber--){
		string pattern,text;
		cin >> pattern >> text;
		printf("%d\n",KMP(text,pattern));
	}
	return 0;
}
