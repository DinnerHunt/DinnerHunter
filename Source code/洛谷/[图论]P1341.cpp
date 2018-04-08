//P1341 luogu
#include<iostream>
#include <vector>
using namespace std;
vector<int> G[100];
int main(){
	ios::sync_with_stdio(false);
	int n;
	char ch1,ch2;
	cin >> n;
	while(n--){
		cin >> ch1 >> ch2;
		G[ch1-'a'].push_back(ch2-'a');
		G[ch2-'a'].push_back(ch1-'a');
	}
	return 0;
}