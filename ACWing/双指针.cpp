/*˫ָ����
for(i = 0,j = 0; i < n; i++){
	while(j < i && check(i,j)) j++;
	//ÿ����ľ����߼�
}

˫ָ���㷨����ĵ���;��������forѭ���Ż��� O��n�� 
*/
//˫ָ���㷨�������Ӧ�ã���һ���ַ����е�ÿ�������������
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
 
