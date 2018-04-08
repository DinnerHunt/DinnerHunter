//UVa12096 集合栈计算机 The SetStak Computer
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define ALL(x) x.begin(),x.end()		//所有内容光
#define INS(x) inserter(x,x.begin())	//插入迭代器

typedef set<int> Set;
map<Set,int> IDcache; 		//把集合映射成ID
vector<Set> Setcache;		//根据ID取集合

//查找给定ID，如果没有则分配一个新的ID
int ID(Set x){
	if(IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x); //添加新集合
	return IDcache[x] = Setcache.size() - 1;
}

int main(){
	int T;		//几次测试
	cin >> T;
	while(T--){
		stack<int> s;	//题目中的栈
		int n;		//几条命令
		cin >> n;
		for(int i = 0; i < n;i++){
			string op;	
			cin >> op;	
			if(op[0] == 'P') s.push(ID(Set()));			//加入空集
			else if(op[0] == 'D') s.push(s.top());		//复制顶层的集合
			else{
				Set x1 = Setcache[s.top()];s.pop();	//取出第一层的集合
				Set x2 = Setcache[s.top()];s.pop();	//取出第二层的集合
				Set x;
				if(op[0] == 'U') set_union (ALL(x1),ALL(x2),INS(x));	//求x1,x2的并集，插入x
				if(op[0] == 'I') set_intersection(ALL(x1),ALL(x2),INS(x));	//求x1,x2的交集，插入x
				if(op[0] == 'A') {x = x2; x.insert(ID(x1));}			//将x1插入x2
				s.push(ID(x));						//将x压入栈
			}
			cout << Setcache[s.top()].size() << endl;	//根据ID查找集合输
		}
		cout << "***" <<endl;
	}
	return 0;
}