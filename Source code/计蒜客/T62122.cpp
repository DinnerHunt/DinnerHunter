#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 466666;
struct Trie{
	int ch[maxd][26];
	int cnt[maxd];
	int num;
	void init(){
		memset(ch[0],0,sizeof(ch[0]));
		cnt[0] = 0;
		num = 0;
	}
	int newnode()
	{
		++num;
		memset(ch[num],0,sizeof(ch[num]));
		cnt[num] = 0;
		return num;
	}
	void insert(char *s)
	{
		int u = 0;
		for(int i=0;s[i];++i)
		{
			if(!ch[u][s[i]-'a'])
				ch[u][s[i]-'a'] = newnode();
			u = ch[u][s[i] - 'a'];
			++cnt[u];
		}
	}
	int query(char *s)
	{
		int u = 0;
		for(int i=0;s[i];++i)
		{
			if(!ch[u][s[i]-'a'])
				return 0;
			u = ch[u][s[i]-'a'];
		}
		return cnt[u];
	}
}
int main(){
	trie.init();
	
	return 0;
}