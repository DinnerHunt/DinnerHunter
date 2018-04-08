//T37825 jisuanke 单词拼接
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> G[26];
int flag[26],in[26],out[26],n,ans,fl;
void bfs(int x){
	queue<int> que;
	que.push(x);
	flag[x] =1;
	while(!que.empty())
	{
		int k = que.front();
		que.pop();
		for(int i=0;i<G[k].size();i++)
			if(!flag[G[k][i]])
			{
				flag[G[k][i]]=1;
				que.push(G[k][i]);
			}
	}
}
int main(){
	string a;
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a;
		G[a[0]-'a'].push_back( a[a.length()-1-'a']);
		out[a[0]-'a']++;
		in[a[a.length()-1]-'a']++;
	}
    int l=0;
    while(!out[l]) l++;
	bfs(l);
	for(int i=0;i<=25;i++)
	{
        int k = in[i] - out[i];
		if(k==0) continue;
		if((k==-1||k==1)&&ans<2) ans++;
		else{
			fl=1;
			break;
		}
	}
     
    for(int i=0;i<26;i++){
        if(in[i]||out[i])
           cout << i << " " << flag[i] << endl; 
    }
	if(fl) cout << "impossible";
	else if (ans == 2) cout << "Euler path";
	else cout << "Euler loop";
	return 0;
}