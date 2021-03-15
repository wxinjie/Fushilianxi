#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
//判断是否有A >= B 
bool cmp(vector<int> &A, vector<int> &B){
	if(A.size() != B.size()) return A.size() > B.size();
	for(int i = A.size() - 1; i >= 0; i--)
		if(A[i] != B[i])
			return A[i] > B[i];
	return true;//A=B
}

vector<int> sub(vector<int> &A, vector<int> &B){
	vector<int> c;
	int t = 0;
	for(int i = 0, t = 0; i < A.size(); i++){
		t = A[i] - t;
		if(i < B.size()) t -= B[i];
		c.push_back((t + 10) % 10);
		if(t < 0) t = 1;
		else t = 0;
	}
	while(c.size() > 1 && c.back() == 0) c.pop_back(); // 去前导0 
	return c;
} 

int main(){
	string a,b;
	cin >> a >> b;
	vector<int> A, B;
	
	for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
	
	
	if(cmp(A, B)){
		vector<int> c = sub(A,B);
		for(int i = c.size() - 1; i >= 0; i--) printf("%d",c[i]); 
	} else {
		vector<int> c = sub(B,A);
		printf("-");
		for(int i = c.size() - 1; i >= 0; i--) printf("%d",c[i]); 
	} 
	
	return 0;
}
