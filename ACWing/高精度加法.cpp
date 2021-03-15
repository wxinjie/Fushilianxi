#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> A;
vector<int> B;

vector<int> add(vector<int> &A, vector<int> &B){
	vector<int> c;
	if(A.size() < B.size()) return add(B,A);
	int t = 0;
	for(int i = 0; i < A.size(); i++){
		t += A[i];
		if(i < B.size()) t += B[i];
		c.push_back(t % 10);
		t /= 10; 
	}
	if(t) c.push_back(t);
	return c;
}

int main(){
	string a,b;
	cin >> a >> b;
	for(int i = a.size() - 1; i >= 0; i--){
		A.push_back(a[i] - '0');
	} 
	for(int i = b.size() - 1; i >= 0; i--){
		B.push_back(b[i] - '0');
	}
	vector<int> c = add(A,B);
	for(int i = c.size() - 1; i >= 0; i--){
		printf("%d",c[i]);
	}
	return 0;
}
