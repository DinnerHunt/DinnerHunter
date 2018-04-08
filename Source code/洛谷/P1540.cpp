#include <iostream>
#include <set>
#include <queue>
using namespace std;
queue<int> que;
set<int> set;
int main(){
	int n,m,env=0,x;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> x;
		if(!set.count(x)){
			env++;
			set.insert(x);
			que.push(x);
		}
		if(que.size()>n){
			set.erase(que.front());
			que.pop();
		}
	}
	cout << env;
	return 0;
}