/*双指针框架
for(i = 0,j = 0; i < n; i++){
	while(j < i && check(i,j)) j++;
	//每道题的具体逻辑
}

双指针算法最核心的用途：将两重for循环优化到 O（n） 
*/
//双指针算法最基本的应用：将一个字符串中的每个单词输出出来
#include<iostream>
#include<string.h>

using namespace std; 

int main(){
	char str[1000];
	gets(str);
	int n = strlen(str);
	
	for(int i = 0; i < n; i++)
	{
		int j = i;
		while(j < n && str[j] != ' ') j++; 
		for(int k = i; k < j; k++) cout << str[k];
		cout << endl;
		i = j;
	}
	
	return 0;
}
 
