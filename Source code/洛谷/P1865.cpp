//P1865 A%B Problem
//DinnerHunt
#include<cstdio>
using namespace std;
const int maxn = 1000000;
int prime[maxn],arr[maxn],n,m;
void init(){
    prime[1]=1;
    for(int i=2;i*i<=m;i++)
        if(!prime[i]){
            for(int j=i*i;j<=m;j+=i)
                prime[j]=1;
        }
    for(int i=1;i<=m;i++){
        if(prime[i])
            arr[i] = arr[i-1];
        else 
            arr[i] = arr[i-1]+1;
    }
}
int main(){
    long long x,y;
	scanf("%d %d",&n,&m);
    init();
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&x,&y);
        if(x<1||y>m)
            printf("Crossing the line\n");
        else
            printf("%d\n",arr[y]-arr[x-1]);
    }
	return 0;
}