//luogu P1036 选数
//DinnerHunt
#include <cstdio>
#include <cstring>
using namespace std;
int arr[25],flag[25],ans=0,n,k;
bool prime(long long x){
    if(x<2) return false;
    if(x==2) return true;
    if(!(x%2)) return false;
    for(register int i = 3;i*i<=x;i+=2)
        if(!(x%i))
            return false;
    return true;
}
/*
void dfs(int d,int cnt,int sum){
	if(cnt == k)
	{
		if(prime(number)) ans++;
		return;
	}
	if(d>n) return;
	dfs(d+1,cnt+1,sum+arr[d]);
	dfs(d+1,cnt,sum);
	}
*/
void dfs(int d,int h,long long number){		//h用来剪枝，如果小于h的枝叶则不考虑
	if(d==k){
        //printf("%lld\n",number);
		if(prime(number)) ans++;
		return;
	}
	for(int i=h;i<n;i++){
		flag[i] = 1;
		dfs(d+1,i+1,number+arr[i]);
		flag[i] = 0;
	}
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	dfs(0,0,0);
    printf("%d",ans);
	return 0;
}