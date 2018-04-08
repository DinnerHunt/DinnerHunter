#include <iostream>
#include <set>
using namespace std;
set<int> a,b;
int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n;
	while(n--){
		cin >> k;
		if(a.count(k)){
			if(b.count(k))
				b.erase(k);
        }
		else{
			a.insert(k);
			b.insert(k);
		}
	}
	set<int>::iterator it = b.begin();
	cout << *it ;
	return 0;
}