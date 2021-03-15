#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
//A/B 商r 从最高位开始算！ 
vector<int> div(vector<int> &A, int b, int &r){
	vector<int> c;
	r = 0;
	for(int i = A.size() - 1; i >= 0; i--){
		r = r * 10 + A[i];
		c.push_back(r / b);
		r %= b; 
	}
	reverse(c.begin(), c.end());//大整数运算默认从低位开始存，这里改成默认形式 
	while(c.size() > 1 && c.back() == 0) c.pop_back();	
	return c;
}

int main(){
	string a;
	int b;
	cin >> a >> b;
	vector<int> A;
	for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');	
	int r;
	vector<int> c = div(A,b,r); 
	for(int i = c.size() - 1; i >= 0; i--) printf("%d",c[i]);
	printf("\n%d",r); 
	return 0;
}
