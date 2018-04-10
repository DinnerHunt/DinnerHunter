#include<iostream>  
#include<string.h>  
#include<string>  
#include<cstdio>  
#include<algorithm>  
#include<queue>  
#define N 25  
using namespace std;  
int map[N][N];  
int sx,sy,m,n;  
int minx;  
int dx[]={0,0,1,-1};  
int dy[]={-1,1,0,0};  
void dfs(int x,int y,int step )  
{  
    if(step>10) return;  
    for(int i=0;i!=4;++i)  
    {  
      if(map[x+dx[i]][y+dy[i]]!=1)  
      {  
          int x1=x,y1=y;  
          while(map[x1+dx[i]][y1+dy[i]]!=1)  
          {  
              x1=x1+dx[i];  
              y1=y1+dy[i];  
              if(x1<0||x1>=n||y1<0||y1>=m) break;  
              if(map[x1][y1]==3)  
              {  
                  minx=min(minx,step+1);  
                  return;  
              }  
          }  
          if(x1>=0&&x1<n&&y1>=0&&y1<m)  
          {  
              map[x1+dx[i]][y1+dy[i]]=0;  
              dfs(x1,y1,step+1);  
              map[x1+dx[i]][y1+dy[i]]=1;  
          }  
      }  
    }  
}  
int main()  
{  
    while(cin>>m>>n)  
    {  
        memset(map,0,sizeof(map));  
        if(n==0&&m==0) break;  
         for(int i=0;i<n;++i)  
                for(int j=0;j<m;++j)  
                {  
                    cin>>map[i][j];  
                    if(map[i][j]==2) sx=i,sy=j;  
                }  
                minx=11;  
                dfs(sx,sy,0);  
                if(minx==11) cout<<"-1"<<endl;  
                else         cout<<minx<<endl;  
    }return 0;  
}  