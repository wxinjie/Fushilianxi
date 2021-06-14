#include<iostream>

using namespace std;

const int N = 1e5 + 10;

struct Student{
	int ai;
	int bi;
	int ci;
	int di;//开始打饭时间 
}student[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &student[i].ai, &student[i].bi, &student[i].ci);
	}
	int ed = 0;
	for(int i = 0; i < n; i++)
	{
		if(ed <= student[i].ai)
		{
			student[i].di = student[i].ai;
			ed = student[i].ai + student[i].bi;
		}
		else if((ed - student[i].ai) > student[i].ci)
		{
			student[i].di = -1;
		}
		else
		{
			student[i].di = ed;
			ed += student[i].bi;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		printf("%d", student[i].di);
		if(i < n - 1) printf(" ");
	}
	
	return 0;
	
}
