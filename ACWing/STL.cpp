/* stl:
vector �䳤���飬����˼�� 
	size() ����Ԫ�ظ���
	empty() �����Ƿ�Ϊ��
	clear() ���
	front()  back()
	push_back() pop_back()
	begin() end()   for(vector<int>::iterator i = a.begin(); i != a.end(); i++) cout << *i << ' '; 
	[] 
	֧�ֱȽ����㣬���ֵ���
pair<name, name> name; �洢��Ԫ�� 
	pair<int, string> p;  
	��һ��Ԫ��   p.first; 
	�ڶ���Ԫ��   p.second;
	֧�ֱȽ����㣬��firstΪ��һ���ؼ��֣���secondΪ�ڶ����ؼ��֣��ֵ���
	pair<int, pair<int, int>> p; 
string �ַ����� 
	substr(a,b), ���ش��±�a��ʼ����Ϊb���Ӵ�   b��д�����һ���ַ�Ϊֹ 
	c_str()  ���ش洢�ַ����������λ  printf("%s", a.c_str()); 
	size()
	empty()
	clear() 
queue ���� 
	size() 
	push(), ���β����һ��Ԫ�� 
	front(),���ض�ͷԪ�� 
	back() ���ض�βԪ�� 
	pop()	������ͷԪ�� 
priority_queue ���ȶ��У��ѣ� Ĭ���Ǵ���� С���Ѷ��壺priority_queue<int, vector<int>, greater<int>> heap; 
	push(), ���� 
	top(), ���ضѶ�Ԫ�� 
	pop() �����Ѷ�Ԫ�� 
stack ջ 
	empty()
	size() 
	push(), ��ջ������һ��Ԫ�� 
	pop(),  ����ջ��Ԫ�� 
	top()  ����ջ��Ԫ�� 
deque ˫�˶���  
	size()
	empty()
	clear()
	front()
	back()
	push_back()/pop_back()
	push_front()/pop_front() 
	[]
	begin()/end() 
set, map, multiset, multimap ����ƽ��������������������̬ά���������� 
	size()
	empty()
	clear()
	begin()
	end()
	set/multiset set�������ظ�Ԫ�أ���������ظ�Ԫ�ػᱻ����,multiset�����ظ�
		insert()����һ��Ԫ��
		find()  ����һ���� 
		count() ����ĳһ�����ĸ���
		erase()
			(1)������һ������ɾ������x
			(2)����һ����������ɾ�����������
		lower_bound(x) ���ش��ڵ���x����С�����ĵ����� 
		upper_bound(x) ���ش���x����С�����ĵ����� 
	map,multimap
		insert() ���������һ��pair 
		erase()	����Ĳ�����pair���ߵ�����
		find()
		[]
		lower_bound() / upper_bound()	 
unordered_set, unordered_map, unordered_multiset, unordered_multimap ���ڹ�ϣ��ʵ�� ,���������ƣ���ɾ�Ĳ�ĸ��Ӷȶ���O��1������֧��lower_bound() upper_bound() ,��������++ -- 

bitset ѹλ ��bool���ֻռ�˷�֮һ�ռ�
	bitset<10000> s;
	~ & | ^ 
	>> , <<
	== !=
	[]
	count()�����ж��ٸ�1
	any() �ж��Ƿ�������һ��1
	none() �ж��Ƿ�ȫΪ0
	set() ������λ�ó�1
	set(k, v) ����kλ���v
	reset() ������λ���0
	flip() �ȼ���~
	flip(k) �ѵ�kλȡ��  
*/ 
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int main()
{
	
 } 
