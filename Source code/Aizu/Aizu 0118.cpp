<<<<<<< HEAD
#include <iostream>
using namespace std;  
const int maxn = 101;  
char g[maxn][maxn];
int n,m;  
int d[4][2] = {0 , 1 , 1 , 0 , 0 , -1 , -1 ,0};  
void dfs(int si , int sj)  
{  
    char ch = g[si][sj];
    g[si][sj] = '1';  
    for(int i = 0 ; i < 4 ; i ++){  
        int x = si + d[i][0];  
        int y = sj + d[i][1];  
        if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] != ch) continue;  
        dfs(x , y);  
    }  
}  
  
int main()  
{  
    while(cin >> n >> m){  
        if(n == 0 && m == 0) break;  
        string str;  
        for(int i = 0 ; i < n ; i ++){  
            cin >> str;  
            for(int j = 0 ; j < m ; j ++)
                g[i][j] = str[j];  
        }  
        int cnt = 0;  
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(g[i][j] != '1'){  
                    dfs(i , j);  
                    cnt ++;  
                }
        cout << cnt << endl;  
  
    }  
}  
=======
//Aizu 0118
//DinnerHunt
#include <cstdio>
#include <cstring>
using namespace std;
int w,h,fx[4]={0,0,-1,1},fy[4]={1,-1,0,0},ans;
char G[101][101];
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int a=x+fx[i],b=y+fy[i];
		if(a>=0&&a<h&&b>=0&&b<w&&G[a][b]==G[x][y]){
			G[x][y]=0;
			dfs(a,b);
		}
	}
}
int main(){
	while(scanf("%d %d",&w,&h)==2){	
		ans = 0;
		G[0][0]=getchar();
		memset(G,0,sizeof(G));
		for(int i=0;i<h;i++)
			for(int j=0;j<=w;j++)
				scanf("%c",&G[i][j]);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(G[i][j]!=0){
					ans++;
					dfs(i,j);
				}
		printf("%d\n",ans);
	}
	return 0;
}
>>>>>>> 4f5007a35fbada46c92474a74b101bfdba54f701
