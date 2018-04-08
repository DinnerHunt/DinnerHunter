//P1341 luogu
//DinnerHunt
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 400;
int G[maxn][maxn];
int list[maxn];
int n;
int ca(char ch){
	if(ch<='z'&&ch>='a') return ch-'a'+27;
	return ch - 'A' + 1;
}
int print(int x){
	if(x<=26) printf("%c",'A'+x-1);
	else printf("%c",'a'+x-27);
}
void addstr(int a,int b){
	G[a][b] = 1;
	G[b][a] = 1;
	list[a]++;
	list[b]++;
}
void Eular(int x){
	print(x);
	for(int i=1;i<=52;i++)
		if(G[x][i]){
			G[x][i]--;
			G[i][x]--;
			Eular(i);
	}
		
}
int main(){
	char str[3];
	scanf("%d",&n);
	memset(G,0,sizeof(G));
	for(int i=0;i<n;i++){
		scanf("%s",str);
		addstr(ca(str[0]),ca(str[1]));
	}
	int cnt=0,p=0;
	for(int i=1;i<=52;i++)
		if(list[i]&1)
		{
			if(!p) p=i;
			cnt++;
		}
	if(cnt!=0&&cnt!=2)
	{
		printf("No Solution");
		return 0;
	}
	if(!cnt)
		for(int i=1;i<=52;i++)
			if(list[i]){
				p=i;
				break;
			}
	Eular(p);
	return 0;
}