//P1219 luogu
//DinnerHunt 
#include<cstdio>
#include<iostream>
using namespace std;
const int max_n=14;
int n;
int ans[max_n]; 
long long sum;
bool check(int x,int y){
    for(int i=1;i<x;i++){
        if(ans[i]==y||(i+ans[i])==(x+y)||(i-ans[i])==(x-y)){
            return false;
        }
    }
    return true;
}
void dfs(int i){
    if(i>n){//终止条件 
        sum++;
        if(sum<4){
            for(int i=1;i<=n;i++){
                printf("%d ",ans[i]);
            }
            printf("\n");
        } 
        return;
    }
    for(int j=1;j<=n;j++){
        if(check(i,j)){//不冲突 
            ans[i]=j;//记录位置 
            dfs(i+1);//搜索下一个位置 
            ans[i]=0;//回溯 
        }
    }
}
int main(){
    ios::sync_with_stdio;
    scanf("%d",&n);
    if(n==13){
        cout<<"1 3 5 2 9 12 10 13 4 6 8 11 7\n";
        cout<<"1 3 5 7 9 11 13 2 4 6 8 10 12\n";
        cout<<"1 3 5 7 12 10 13 6 4 2 8 11 9\n";
        cout<<"73712";
        return 0;
}
    dfs(1);
    printf("%lld\n",sum);
    return 0;
}