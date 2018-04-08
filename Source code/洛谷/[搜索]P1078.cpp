//P1078 文化之旅
//DinnerHunt
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1000*100;
int N,K,M,S,T,country[120],culture[120][120],G[120][120],arr[120],ans=maxn;
inline int min(int x,int y){
    return x<y?x:y;
}
void dfs(int x,int spend){
    if(x==T)
    {
     	ans = min(spend,ans);
     	return;
    }
    if(spend>maxn) return;
    for(int i=1;i<=N;i++){
        if(G[x][i]==-1) continue;
        int flag = 0;
        for(int j=1;j<=K;j++)
            if(culture[country[i]][j]&&arr[j]){flag =1;break;};
        if(flag) continue;
        arr[country[i]] = 1;
        dfs(i,spend+G[x][i]);
        arr[country[i]] =-1;
 	}
}
int main(){
    scanf("%d %d %d %d %d",&N,&K,&M,&S,&T);
    for(int i=1;i<=N;i++) {scanf("%d",&country[i]);}
    for(int i=1;i<=K;i++)
        for(int j=1;j<=K;j++){
            scanf("%d",&culture[i][j]);
            if(i==j) culture[i][j]=1;
        }
    memset(G,-1,sizeof(G));
    int a,b,c,d;
    for(int i=1;i<=M;i++){
        scanf("%d %d %d",&a,&b,&c);
        d = (G[a][b] == -1?c:G[a][b]);
        G[a][b] = min(d,c);
        G[b][a] = min(d,c);
    }
    arr[country[S]]=1;
    dfs(S,0);
    if(ans == maxn) printf("-1");
    else printf("%d",ans);
    return 0;
}
