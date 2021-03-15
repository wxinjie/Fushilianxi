//����Ͳ������н���������ϲ���һ��
//�ⷨ�� 1.��������˵����� 2.ɨ�裬ά��һ������ ����������� 1�����ڲ������ö�  2���н�����һ���������棺��ed���� 
//                                                                               3���޽��� ������ǰά������������𰸣�����ά������Ϊ��ǰ���� 
/*
5
1 2
2 4
5 6
7 8
7 9
output
3
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
	vector<PII> res;
	sort(segs.begin(), segs.end());
	
	int st = -2e9, ed = -2e9;//��ʼԤ�踺���� 
	for(int i = 0; i < segs.size(); i++)
	{
		if(ed < segs[i].first)
		{
			if(st != -2e9) res.push_back({st, ed});//��ǰά�������Ҷ˵��ϸ�С�ڵ�ǰɨ���������˵㲢�Ҳ��ǳ�ʼ���ʱ������ǰά���������� 
			st = segs[i].first;
			ed = segs[i].second; 
		}
		else ed = max(ed, segs[i].second);//�н���������edΪ�ϴ���Ǹ� 
	}
	if(st != -2e9) res.push_back({st, ed});//��ֹsegs�ǿյ�
	segs = res; 
		
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		segs.push_back({l, r});
	}
	
	merge(segs);
	
	cout << segs.size() << endl;
	
	return 0;
}
 
