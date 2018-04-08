//P1767 家族_NOI导刊 2010普及(10) 
//DinnerHunt
#include <cstdio>
#include <string>
using namespace std;
int n,m,k,G[105][205];
int fx[4]={1,-1,0,0},fy[4]={0,0,1,-1};
char ch;
string str;
void dfs(int x,int y){
	G[x][y]=0;
	for(int i=0;i<4;i++)
		if(G[x+fx[i]][y+fy[i]])
			dfs(x+fx[i],y+fy[i]);
}
int main(){
	scanf("%d",&n);
	ch = getchar();
	for(int i=0;i<n;i++){
		getline(cin,str);
		for(int j=0;j<s.size();j++)
			if(str[j]>='a'&&str[j]<='z')
				G[i][j] = 1;
	}
	for(int i=0;i<105;i++)
		for(int j=0;j<205;j++){
			dfs(i,j);
			k++;
		}
			
    printf("%d",k);
	return 0;
		
}