//P1043 数字游戏
//DinnerHunt
#include <cstdio>
using namespace std;
const int maxn = 100000;
inline int min(int x,int y){
    return x<y?x:y;
}
inline int max(int x,int y){
    return x>y?x:y;
}
inline int mod(int x){
    if(x<0) x+=maxn;
    return x%10;
}
inline int pow(int x){
    int k=1;
    for(int i=0;i<=x;i++)
        k*=9;
    return k;
}
int n,m,arr[55],mx=0,mi = maxn;
void dfs(int d,int s,int sound,int x){  //当前深度,当前点的位置，环的第几部分，当前的值
    int a = 0;
    if(x*pow(m-d)<=mx&&x>=mi) return;
    if(d==m){
        for(int i=s;i-sound<=n;i++){
            a+=arr[(i-1)%n+1];
        }
        x*= mod(a);
        mi = min(mi,x);
        mx = max(mx,x);
        return;
    }
    for(int i=s;i-sound<=n-d;i++){
        a+=arr[(i-1)%n+1];
        dfs(d+1,i+1,sound,x*mod(a));
    }
    return;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
}
    for(int i=0;i<n;i++)
        dfs(1,i+1,i,1);
    printf("%d\n%d",mi,mx);
    return 0;