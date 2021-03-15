//前缀和差分     a是b的前缀和，b是a的差分，即 ai = bi + bi-1 +...+ b1  (a1 = b1 ,a2 - a1 = b2,...);  
//现在要求 al-ar全部加上c，即al + c, al+1 + c,...ar + c
//解法：bl + c(这样利用差分求a时al之后的数都会加上c)，然后br+1 - c(这样ar之后的数刚才加上的c就被抵消掉了)
//以上只需修改两个数，只需要用O(1)的时间给数组中的一段数全部加上某个数值
/*
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
output:
3 4 5 3 4 2
*/
#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N],b[N];
int n,m;

void insert(int l, int r, int c){
	b[l] += c;
	b[r + 1] -= c;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	
	for(int i = 1; i <= n; i++) insert(i, i, a[i]);
	
	while(m--){
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		insert(l,r,c);
	} 
	for(int i = 1; i <= n; i++) b[i] += b[i - 1];
	for(int i = 1; i <= n; i++) printf("%d ",b[i]);
} 
