#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;
set<string> st; 
string s1,s2,str1,str2,mp[10],has[10];
int ans=11,n;
typedef pair<int,string> P;
inline int min(int x,int y){
    return x<y?x:y;
}
bool bfs(){
	st.insert(s1);
	queue<P> que;
	que.push(P(0,s1));
	while(!que.empty()){
		P p= que.front();
		str1 = p.second;
		for(int i=0;i<n;i++){
			int pos = str1.find(mp[i],0);
			while(pos!=string::npos){
				str2 = str1;
				str2.replace(pos,mp[i].length(),has[i]);
				if(str2==s2) return p.first+1;
				pos = str1.find(mp[i],pos+1);
				if(st.count(str2)) continue;
				st.insert(str2);
				que.push(p.first+1,str2);
			}
		}
	}
	return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    while(cin >> str1 >> str2){
        mp[n] = str1;
        has[n++] = str2;
    }
    dfs(0,s1);
    
    if(bfs()) cout << "NO ANSWER!";
    return 0;
}