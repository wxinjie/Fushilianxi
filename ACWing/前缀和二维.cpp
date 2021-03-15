//前缀和拓展到二维 (背公式思想) 右下角矩形面积 =  Sx2,y2 - Sx2,y1-1 - Sx1-1,y2 + Sx1-1,y1-1
//s[i][j]推导： for for s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]; 
#include<iostream>
#include<cstdio>

using namespace std;

const int N = 1010;

int n,m,q;
int a[N][N],s[N][N];//a[][]存输入数组 s[][]存前缀和 

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d",&a[i][j]);
			
	for(int i = 1; i <= n; i++)				//求前缀和 
		for(int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
			
	while(q--){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]); //算子矩阵的和 
	} 
	return 0;
			 
}
