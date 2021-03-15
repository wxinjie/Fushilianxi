//��ɢ���������� ֵ��Ƚϴ� 10^9 �� �����Ƚ��� 10^5����  �����ܿ�һ����˴������ �����Խ���10^5����ӳ�䵽��0��ʼ��������Ȼ��
//eg�� a[](����): 1 3 100 2000 500000
//                0 1  2    3    4 
//�ؼ��� 1.a[]�п������ظ�Ԫ�� ��ȥ�أ� 2.������x��ɢ�����ֵ �����֣�

/*ȥ�ش��룺
vector<int> alls; //�洢���д���ɢ����ֵ
sort(alls.begin(), alls.end()); //������ֵ����
alls.erase(unique(alls.begin(), alls.end()), alls.end());//ȥ���ظ�Ԫ��
*/

/*�������x��Ӧ����ɢ����ֵ �ҵ��������ҵ�һ�����ڵ���x��λ�� 
int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1; //ӳ�䵽1��2��...n 
}
*/

//����ͣ� ���޳����ᣬ��ʼÿ������ֵΪ0������n�β�����ÿ�ν�ĳһλ�� x�ϵ�����c������m��ѯ�ʣ�ÿ��ѯ���������[l, r]֮����������ĺ͡�
//ps��������᷶Χ������10^5�����������ǰ׺�������㣬ֻ��ÿ��ִ�� a[x] += c ���ٶ�a[]��һ��ǰ׺�ͼ��� 
//��ɢ���ⷨ��ÿ���Ƚ�xӳ���k��Ȼ��a[k] += c     ���l��rҲ��ɢ����Ϊkl,kr   ��a[kl] + ... + a[kr] (�±����ӳ����ֵ)

/*
3 3
1 2
3 6
7 5
1 3
4 6
7 8
output
8
0
-8
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;//pair��ÿһ���� 

const int N = 3e5 + 10;

int n, m;
int a[N], s[N]; //s��ǰ׺��

vector<int> alls;
vector<PII> add,query; 

int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while(l < r)
	{
		int mid = l + (r - l) / 2;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;//+1ӳ�䵽��1��ʼ����Ȼ�� 
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) 
	{
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x);
	}
	
	for(int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		alls.push_back(l);
		alls.push_back(r);		//��ʱ���������õ����±궼������alls 
	}
	
	//ȥ��
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end()); 
	
	//ִ�мӷ� 
	for(int i = 0; i < add.size(); i++)
	{
		int x = find(add[i].first);
		a[x] += add[i].second;
	}
	
	//Ԥ����ǰ׺��
	for(int i = 1; i <= alls.size(); i++)  s[i] = s[i - 1] + a[i];
	
	//����ѯ��
	for(int i = 0; i < query.size(); i++)
	{
		int l = find(query[i].first), r = find(query[i].second);
		printf("%d\n",s[r] - s[l - 1]);
	 } 
	 
	return 0;
 } 


 

 





















 
