//UVa 12325
//Zombie's Treasure Chest 宝藏
//DinnerHunt
#include <cstdio>
using namespace std;
const int maxn = 1000000;
typedef long long LL;
LL ans;
int size,s1,s2,v1,v2;
inline long long max(long long a,long long b){
	return a>b?a:b;
}
void programmer1(int s,int a,int b,int c,int d,int k){
	for(LL i=0;i<=k;i++){
        LL vss =((s-i*a)/c)*d+i*b;
		ans = max(ans,((s-i*a)/c)*d+i*b);
    }
}
void programmer2(){
	programmer1(size,s2,v2,s1,v1,s1-1);
	programmer1(size,s1,v1,s2,v2,s2-1);
}
int main(){
	int Case = 0;
	scanf("%d",&Case);
	for(int i=1;i<=Case;i++){
        ans =0;
		scanf("%d %d %d %d %d",&size,&s1,&v1,&s2,&v2);
		if(size/s1<maxn)
			programmer1(size,s1,v1,s2,v2,size/s1);
		else if(size/s2<maxn)
			programmer1(size,s2,v2,s1,v1,size/s2);
		else
			programmer2();
		printf("Case #%d: %lld\n",i,ans);
	}
	return 0;
}
