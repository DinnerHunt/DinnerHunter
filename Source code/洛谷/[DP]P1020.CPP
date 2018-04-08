//P1020 luogu
//DinnerHunt
#include<bits/stdc++.h>
using namespace std;
int k,b,Ans,e[100005],Num2[100005];
struct Node{
    int l;
}d[100005],Num[100005];
bool operator < (const Node& x,const Node& y){
    return x.l > y.l;
}
int main(){
    while(scanf("%d",&Num[++k].l) == 1);
    k -= 1;
    for(int i=1;i<=k;i++){
        Num2[i] = Num[i].l;
    }
    e[1] = Num2[1];Ans = 1;
    d[1].l = Num[1].l;b = 1;
    for(int i=2;i<=k;i++){
        int p = upper_bound(d + 1,d + b + 1,Num[i]) - d;
        d[p].l = Num[i].l;
        b = b > p ? b:p;
    }
    for(int i=2;i<=k;i++){
        int q=lower_bound(e+1, e+Ans+1, Num2[i]) - e;
        e[q]=Num2[i]; 
        Ans = Ans > q ? Ans:q;
    }
    printf("%d\n%d\n",b,Ans);
    return 0;
}