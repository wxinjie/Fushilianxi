//哈希查找 2.内定义
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int MAXN = 100 + 10;
const int RANGE = 1e6;
int arr[MAXN];

unordered_map<int, bool> hashTable;             //<元素类型，是否出现过> 


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		hashTable[arr[i]] = true;
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		int target;
		scanf("%d", &target);
		if (hashTable[target]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}


	}

	return 0;
}
