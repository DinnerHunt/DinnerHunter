//P1454 圣诞夜的极光
//DinnerHunt
#include <cstdio>
#include <iostream>
using namespace std;
char G[105][105];
int fx[12] = {-2,-1,-1,-1,0,0,0,0,1,1,1,2};
int fy[12] = {0,-1,0,1,-2,-1,1,2,-1,0,1,0};
int x,y,ans=0;
void dfs(int m,int n){
    G[m][n]='-';
    for(int i=0;i<12;i++){
        int a=m+fx[i];
        int b=n+fy[i];
        if(a<1||b<1||a>x||b>y) continue;
        if(G[a][b]=='#')
            dfs(a,b);
    }
}
int main(){
    scanf("%d %d",&x,&y);
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
        	cin >> G[i][j];
        	//cout << G[i][j];
        }
        //printf("\n");
    }
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            if(G[i][j]=='#'){
                dfs(i,j);
                ans++;
            }
    printf("%d",ans);
    return 0;
}