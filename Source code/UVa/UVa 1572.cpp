//UVa1572
//Self-Assembly 自组合
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int G[52][52];
int ID(char ch1,char ch2){
	return (ch1-'A')*2 + (ch2 =='+'?0:1);
}
void build(char a,char b,char c,char d){
	if(a=='0'||c=='0') return;
	int x = ID(a,b)^1,y = ID(c,d);
	G[x][y]=1;
}
int c[52];
bool dfs(int u){
	c[u] = -1;
	for(int i=0;i<52;i++)if(G[u][i])
	{
		if(c[i]<0) return true;
		if(!c[i]&&dfs(i)) return true;
	}
	c[u] = 1;
	return false;
}
bool topu(){
    memset(c,0,sizeof(c));
	for(int i=0;i<52;i++)if(!c[i])
		if(dfs(i)) return true;
	return false;
}
int main(){
	int n;
	while(scanf("%d",&n)==1&&n){
        memset(G,0,sizeof(G));
		while(n--){
			char str[10];
			scanf("%s",str);
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
					if(i!=j)
						build(str[i*2],str[i*2+1],str[j*2],str[j*2+1]);
		}
		if(topu()) printf("unbounded\n");
		else printf("bounded\n");
	}
	return 0;
}