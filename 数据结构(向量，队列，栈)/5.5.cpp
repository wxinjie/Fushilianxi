#include<iostream>
#include<cstdio>
#include<string>
#include<stack>

using namespace std;

int main(){
	string str;
	while(cin >> str){
		stack<int> brackets;
		string answer(str.size(),' '); //设为输入长度个空格
		for(int i = 0; i < str.size(); ++i){
			if(str[i] == '('){
				brackets.push(i);		//压入左括号的下标 
			} else if(str[i] == ')'){
				if(!brackets.empty()){
					brackets.pop();
				}else {
					answer[i] = '?';    //右括号不能匹配 
				}
			}
		} 
		while(!brackets.empty()){
			answer[brackets.top()] = '$';
			brackets.pop();
		}
		cout << str << endl;
		cout << answer << endl;
	}
	
	
	return 0;
}
