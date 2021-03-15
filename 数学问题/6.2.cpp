#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

string Divide(string str, int x) {		//字符串除法 
	int remainder = 0;
	for(int i = 0; i < str.size(); ++i) {
		int current = remainder * 10 + str[i] - '0';
		str[i] = current / x + '0';
		remainder = current % x;
	}
	int pos = 0;
	while(str[pos] == '0') {		//寻找首个非0下标 
		pos++;
	}
	return str.substr(pos);
}

int main() {
	string str;
	while(cin >> str) {
		vector<int> binary;
		while(str != "") {
			int last = str[str.size() - 1] - '0';
			binary.push_back(last % 2);
			str = Divide(str, 2);
		}
		for(int i = binary.size() - 1; i >= 0; --i){
			printf("%d",binary[i]);
		}
		printf("\n");
	}
	return 0;
}
