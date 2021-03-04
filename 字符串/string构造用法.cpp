//string 构造基本用法
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
	string s0 = "abc def";
	string s1;
	string s2(s0);
	string s3(s0,1,4);
	string s4("jkljkljkl");
	string s5("abc def",3);
	string s6(6,'j');
	
	cout << "s0: " << s0 << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << "s5: " << s5 << endl;
	cout << "s6: " << s6 << endl;
	
	
	
	return 0;
}
