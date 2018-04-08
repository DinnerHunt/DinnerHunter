//P1379 八数码难题
//lob
#include<iostream>
#include<string>
#include<cstdio>
#include<queue>
#include<vector>
#include<set>
using namespace std;
string str;
typedef pair<string,int> P;
vector<int> arr[10];
void init(){
	arr[0].push_back(1);
	arr[0].push_back(3);
	arr[1].push_back(0);
	arr[1].push_back(4);
	arr[1].push_back(2);
	arr[2].push_back(1);
	arr[2].push_back(5);
	arr[3].push_back(0);
	arr[3].push_back(4);
	arr[3].push_back(6);
	arr[4].push_back(1);
	arr[4].push_back(3);
	arr[4].push_back(5);
	arr[4].push_back(7);
	arr[5].push_back(2);
	arr[5].push_back(4);
	arr[5].push_back(8);
	arr[6].push_back(3);
	arr[6].push_back(7);
	arr[7].push_back(4);
	arr[7].push_back(6);
	arr[7].push_back(8);
	arr[8].push_back(7);
	arr[8].push_back(5);
}
int bfs(){
	queue<P> que;
	set<string> st;
    st.insert(str);
	que.push(P(str,0));
	while(!que.empty()){
		string s = que.front().first;
        int k = que.front().second;
        que.pop();
		int i;
		for(i=0;i<9;i++)
			if(s[i]=='0') break;
		for(int j=0;j<arr[i].size();j++){
			string s1 = s;
			s1[i] = s1[arr[i][j]];
			s1[arr[i][j]] = '0';
			if(st.count(s1)) continue;
			st.insert(s1);
			if(s1=="123804765")return k+1;
			que.push(P(s1,k+1));
		}
	}
}
int main(){
	init();
	cin >> str;
    if(str=="123804765")
        printf("0");
    else
    printf("%d",bfs());
	return 0;
}