//luogu P3368
//DinnerHunt
#include <cstdio>
using namespace std;
const int maxn = 1e6;
int tree[maxn];
int c[maxn];
int n,m;
int lowbit(int x){
    return x&-x;
}
void change(int x,int k){
    for(;x<=n;x+=lowbit(x))
        tree[x]+=k ;
}
int query(int x){
    int ans=0;
    for(;x;x-=lowbit(x))
        ans += tree[x];
    return ans;
}
int main(){
    scanf("%d %d",&n,&m);
    int a,x,y,k;					
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&x);
        if(a==1){			//区间修改操作
            scanf("%d %d",&y,&k);
            change(x,k);
            change(y+1,-k);
        }
        else {
            printf("%d\n",c[x]+query(x));
        }
    }

    return 0;
}