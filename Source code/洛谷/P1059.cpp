//P1059 luogu
#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main(){
	int n,x;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x ;
		if(!s.count(x))
			s.insert(x);
	}
	cout << s.size() << endl;
	for(set<int>::iterator it = s.begin();it!=s.end(); ++it){
		if(it!=s.begin())
			cout << " ";
		cout << *it;
	}
	return 0;
}