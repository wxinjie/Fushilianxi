//利用归并排序特点求逆序数：（只修改一行number = middle+1-i）即可
 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 1000 + 10;
int arr[MAXN];
int temp[MAXN];
int number;

void Combine(int left, int middle, int right) {
	int i = left;
	int j = middle + 1;
	int k = left;
	while (i <= middle && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			number += middle + 1 - i;
			temp[k++] = arr[j++];
		}
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}
	while (i <= middle) {
		temp[k++] = arr[i++];
	}
	for (k = left; k <= right; ++k) {
		arr[k] = temp[k];
	}

}


void MergeSort(int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		MergeSort(left, middle);
		MergeSort(middle + 1, right);
		Combine(left, middle, right);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	number = 0;
	MergeSort(0, n - 1);
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("%d\n", number);
	return 0;
}
