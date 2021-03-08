#include<iostream>
#include<cstdio>
#include<string>
#include<stack>

using namespace std;

int main(){
	string str;
	while(cin >> str){
		stack<int> brackets;
		string answer(str.size(),' '); //��Ϊ���볤�ȸ��ո�
		for(int i = 0; i < str.size(); ++i){
			if(str[i] == '('){
				brackets.push(i);		//ѹ�������ŵ��±� 
			} else if(str[i] == ')'){
				if(!brackets.empty()){
					brackets.pop();
				}else {
					answer[i] = '?';    //�����Ų���ƥ�� 
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
