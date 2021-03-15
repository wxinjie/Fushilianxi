#include<iostream>
#include<cstdio>
#include<vector>
 
using namespace std;

vector<int> mul(vector<int> &A, int b){
	vector<int> c;
	int t = 0;
	for(int i = 0; i < A.size() || t; i++){
		if(i < A.size())	t += A[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	while(c.size() > 1 && c.back() == 0) c.pop_back();	
	return c;
}

int main(){
	string a;
	int b;
	cin >> a >> b;
	vector<int> A;
	for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');	
	
	vector<int> c = mul(A,b); 
	for(int i = c.size() - 1; i >= 0; i--) printf("%d",c[i]);
	return 0;
}
