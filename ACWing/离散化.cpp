//离散化（整数） 值域比较大 10^9 ， 个数比较少 10^5个数  不可能开一个如此大的数组 ，可以将这10^5个数映射到从0开始的连续自然数
//eg： a[](有序): 1 3 100 2000 500000
//                0 1  2    3    4 
//关键： 1.a[]中可能有重复元素 （去重） 2.如何算出x离散化后的值 （二分）

/*去重代码：
vector<int> alls; //存储所有待离散化的值
sort(alls.begin(), alls.end()); //将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());//去掉重复元素
*/

/*二分求出x对应的离散化的值 找到从左至右第一个大于等于x的位置 
int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1; //映射到1，2，...n 
}
*/

//区间和： 无限长数轴，初始每个坐标值为0，进行n次操作，每次将某一位置 x上的数加c，进行m次询问，每次询问求出区间[l, r]之间的所有数的和。
//ps：如果数轴范围有限如10^5，则可以利用前缀和来计算，只需每次执行 a[x] += c ，再对a[]求一遍前缀和即可 
//离散化解法：每次先将x映射成k，然后将a[k] += c     最后将l、r也离散化化为kl,kr   求a[kl] + ... + a[kr] (下标就是映射后的值)

/*
3 3
1 2
3 6
7 5
1 3
4 6
7 8
output
8
0
-8
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;//pair存每一对数 

const int N = 3e5 + 10;

int n, m;
int a[N], s[N]; //s存前缀和

vector<int> alls;
vector<PII> add,query; 

int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while(l < r)
	{
		int mid = l + (r - l) / 2;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;//+1映射到从1开始的自然数 
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) 
	{
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x);
	}
	
	for(int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		alls.push_back(l);
		alls.push_back(r);		//此时把所有能用到的下标都放入了alls 
	}
	
	//去重
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end()); 
	
	//执行加法 
	for(int i = 0; i < add.size(); i++)
	{
		int x = find(add[i].first);
		a[x] += add[i].second;
	}
	
	//预处理前缀和
	for(int i = 1; i <= alls.size(); i++)  s[i] = s[i - 1] + a[i];
	
	//处理询问
	for(int i = 0; i < query.size(); i++)
	{
		int l = find(query[i].first), r = find(query[i].second);
		printf("%d\n",s[r] - s[l - 1]);
	 } 
	 
	return 0;
 } 


 

 





















 
