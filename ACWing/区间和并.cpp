//区间和并，将有交集的区间合并成一个
//解法： 1.按区间左端点排序 2.扫描，维护一个区间 出现三种情况 1）在内部：不用动  2）有交集，一部分在外面：将ed更新 
//                                                                               3）无交集 ：将当前维护区间输出到答案，更新维护区间为当前区间 
/*
5
1 2
2 4
5 6
7 8
7 9
output
3
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
	vector<PII> res;
	sort(segs.begin(), segs.end());
	
	int st = -2e9, ed = -2e9;//初始预设负无穷 
	for(int i = 0; i < segs.size(); i++)
	{
		if(ed < segs[i].first)
		{
			if(st != -2e9) res.push_back({st, ed});//当前维护区间右端点严格小于当前扫描区间的左端点并且不是初始情况时，将当前维护区间加入答案 
			st = segs[i].first;
			ed = segs[i].second; 
		}
		else ed = max(ed, segs[i].second);//有交集，更新ed为较大的那个 
	}
	if(st != -2e9) res.push_back({st, ed});//防止segs是空的
	segs = res; 
		
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		segs.push_back({l, r});
	}
	
	merge(segs);
	
	cout << segs.size() << endl;
	
	return 0;
}
 
