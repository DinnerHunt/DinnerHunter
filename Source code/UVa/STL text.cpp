#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
vector<int> fill_random_int(int cnt) {
	vector<int > v;
	for(int i=0;i < cnt; i++){
		v.push_back(rand());
	}
	return v;
}
void test_sort(vector<int>& v){
	sort(v.begin(),v.end());
	for(int i = 0; i< v.size()-1; i ++)
		assert(v[i] <= v[i+1]);
} 
int main(){
	vector<int> v;
	fill_random_int(v,1000000);
	test_sort(v);
	return 0;
}