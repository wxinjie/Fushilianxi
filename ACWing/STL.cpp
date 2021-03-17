/* stl:
vector 变长数组，倍增思想 
	size() 返回元素个数
	empty() 返回是否为空
	clear() 清空
	front()  back()
	push_back() pop_back()
	begin() end()   for(vector<int>::iterator i = a.begin(); i != a.end(); i++) cout << *i << ' '; 
	[] 
	支持比较运算，按字典序
pair<name, name> name; 存储二元组 
	pair<int, string> p;  
	第一个元素   p.first; 
	第二个元素   p.second;
	支持比较运算，以first为第一个关键字，以second为第二个关键字（字典序）
	pair<int, pair<int, int>> p; 
string 字符串， 
	substr(a,b), 返回从下标a开始长度为b的子串   b不写则到最后一个字符为止 
	c_str()  返回存储字符串数组的首位  printf("%s", a.c_str()); 
	size()
	empty()
	clear() 
queue 队列 
	size() 
	push(), 向队尾插入一个元素 
	front(),返回队头元素 
	back() 返回队尾元素 
	pop()	弹出队头元素 
priority_queue 优先队列（堆） 默认是大根堆 小根堆定义：priority_queue<int, vector<int>, greater<int>> heap; 
	push(), 插入 
	top(), 返回堆顶元素 
	pop() 弹出堆顶元素 
stack 栈 
	empty()
	size() 
	push(), 向栈顶插入一个元素 
	pop(),  弹出栈顶元素 
	top()  返回栈顶元素 
deque 双端队列  
	size()
	empty()
	clear()
	front()
	back()
	push_back()/pop_back()
	push_front()/pop_front() 
	[]
	begin()/end() 
set, map, multiset, multimap 基于平衡二叉树（红黑树），动态维护有序序列 
	size()
	empty()
	clear()
	begin()
	end()
	set/multiset set不能有重复元素，如果插入重复元素会被忽略,multiset可以重复
		insert()插入一个元素
		find()  查找一个数 
		count() 返回某一个数的个数
		erase()
			(1)输入是一个数，删除所有x
			(2)输入一个迭代器，删除这个迭代器
		lower_bound(x) 返回大于等于x的最小的数的迭代器 
		upper_bound(x) 返回大于x的最小的数的迭代器 
	map,multimap
		insert() 插入的数是一个pair 
		erase()	输入的参数是pair或者迭代器
		find()
		[]
		lower_bound() / upper_bound()	 
unordered_set, unordered_map, unordered_multiset, unordered_multimap 基于哈希表实现 ,和上面类似，增删改查的复杂度都是O（1），不支持lower_bound() upper_bound() ,迭代器的++ -- 

bitset 压位 与bool相比只占八分之一空间
	bitset<10000> s;
	~ & | ^ 
	>> , <<
	== !=
	[]
	count()返回有多少个1
	any() 判断是否至少有一个1
	none() 判断是否全为0
	set() 把所有位置成1
	set(k, v) 将第k位变成v
	reset() 把所有位变成0
	flip() 等价于~
	flip(k) 把第k位取反  
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
