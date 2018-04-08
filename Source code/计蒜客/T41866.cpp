//jisuanke T41866 帕吉的肉钩
//DinnerHunt
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 137032*2;
int arr[maxn],col[maxn],n,m;
void up(int p){
    arr[p] = arr[p<<1]+arr[p<<1|1];
}
void build(int pid,int l,int r){
    if(l==r){
        arr[pid] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(pid<<1,l,mid);
    build(pid<<1|1,mid+1,r);
    up(pid);
}
void down(int p,int l,int r){
    if(col[p])
    {
        int mid = (l+r)/2;
        arr[p<<1] = col[p]*(mid-l+1);
        arr[p<<1|1] = col[p]*(r-mid);
        col[p<<1] = col[p<<1|1] = col[p];
        col[p]=0;

    }

}

void modify(int p,int l,int r,int x,int y,int c){
    if(x<=l&&r<=y){
        arr[p] = (r-l+1) * c;
        col[p] = c;
        return;
    }
    down(p,l,r);
    int mid = (l+r)/2;
    if(x<=mid) modify(p<<1,l,mid,x,y,c);
    if(y>mid) modify(p<<1|1,mid+1,r,x,y,c);
    up(p);
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;;
    build(1,1,n);
    int a,b,c;
    for(int i=1;i<=n;i++){
        cin >> a >> b >> c;
        modify(1,1,n,a,b,c);
    }
    cout << "The total value of the hook is ";
    cout << arr[1] << ".";
    return 0;
}