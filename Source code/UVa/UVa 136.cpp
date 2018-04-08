//Uva136 丑数 Ugly Numbers
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef long long LL;
const int coedd[3] = {2, 3, 5};

//丑数均为 1 的 2，3，5倍

int main(){	
	priority_queue<LL, vector<LL>, greater<LL> > pq;	//创建一个递增的优先队列
	set<LL> s;					//创建一个集合
	pq.push(1);					//集合中添加1，队列中添加1
	s.insert(1);
	for(int i = 1; ; i++ ){		
		LL x = pq.top();		//取出当前最小的一个
		pq.pop();				//删除最小的这个
		if(i == 1500) {	//取出的是第1500个时
			cout << "The 1500'th ugly number is " << x << ".\n";
			break;	
		}
		for(int j = 0; j < 3; j++){		//将取出来的数分别乘以2，3，5
			LL x2 = x * coeff[j];	
			if(!s.count(x2)) { s.insert(x2); pq.push(x2);}	//如果集合中不存在这个数，则加入队列和集合

		}
	}
	return 0;
}