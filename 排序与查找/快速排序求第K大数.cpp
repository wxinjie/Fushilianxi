//快速排序 求第K大数  index：n-k
 #include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXN = 1000 + 10;
int arr[MAXN];

int Partition(int left,int right){
	int random = left + rand()%(right - left + 1);//#include<cstdlib>
	swap(arr[left],arr[random]);//#include<algorithm>
	while(left < right){
		while(left < right && arr[left] <= arr[right]){
			right--;
		}
		swap(arr[right],arr[left]); 
		while(left < right){
		while(left < right && arr[left] <= arr[right]){
			left++;
		}
		swap(arr[left],arr[right]);
	}
	return left;
	}
}

int QuickSort(int left,int right,int p){
	int position = Partition(left,right);
	if(p < position){
		QuickSort(left,position - 1,p);
	} else if(p > position){
		QuickSort(position + 1,right,p);
	}else{
		return arr[position];
	}
}


int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;++i){
		scanf("%d",&arr[i]);
	}
	int k;
	scanf("%d",&k);
	int answer = QuickSort(0,n-1,n-k);
	printf("%d",answer);
	printf("\n");
	return 0;
} 
