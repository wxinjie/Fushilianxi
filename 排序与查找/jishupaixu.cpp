//�������򡪡�������������	 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


const int MAXN = 1e6 + 10;
const int RANGE = 5e5;
int arr[MAXN];
int number[MAXN];                 //��������

int main() {
	int n, m;
	while (scanf("%d%d", &n,&m) != EOF) {
		memset(number, 0, sizeof(number));//�������
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			number[arr[i] + RANGE]++;
		}
		int index = 0;                    //�ش�
		for (int i = 0; i < MAXN; ++i) {
			while (number[i]--) {
				arr[index++] = i - RANGE; 
			}
		}
		for (int i = n-1; i >= n - m; --i) {
			if (i == n - m) {

				printf("%d\n", arr[i]);
			}
			else {
				printf("%d ", arr[i]);
			}
		}
	}
	return 0;
}

