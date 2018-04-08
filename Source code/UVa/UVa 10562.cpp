//UVa 10562
//Underaw the Trees 看图写树
//DinnerHunt
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
const int maxn = 200+10;
int n;
char buf[maxn][maxn];
void dfs(int r,int c){
	printf("%(",buf[r][c]);
	if(r+1<n&&buf[r+1][c]=='|'){	//该节点有子树
		int i = c;
		while(i-1>=0&&buf[r+2][i-1]=='-') i--;
		while(buf[r+2][i] == '-' && buf[r+3][i] != '\0'){
			if(!isspace(buf[r+3][i])) dfs(r+3,i);
			i++;
		}
	}
	printf(")");

}
void solve(){
	n = 0;
	for(;;){
		fgets(buf[n],maxn,stdin);
		if(buf[n][0] == '#') break;
		else n++;
	}
	printf("(");
	if(n){
		for(int i=0;i<strlen(buf[0]);i++)
			if(buf[0][i] != ' '){ dfs(0,i);break; }
	}
	printf(")\n");
}
int main(){
	int T;
	fgets(buf[0],maxn,stdin);
	fgets(buf[0],"%d",&T);
	while(T--) solve();
	return 0;
}