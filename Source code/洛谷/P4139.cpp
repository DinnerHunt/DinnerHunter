#include <cstdio>
using namespace std;
const int maxd = 10000005;
int phi[maxd],pd[maxd],pri[maxd],cnt;
void init(){
 for(int i=2;i<maxd;i++)
   {
       if(!pd[i])
       {
           pri[cnt++]=i;
           phi[i]=i-1;
       }
       for(int j=0;j<cnt&&i*pri[j]<maxd;j++)
       {
           pd[i*pri[j]]=1;
           if(!(i%pri[j]))
		{
			phi[i*pri[j]]=phi[i]*pri[j];
			break;
		}
		else phi[i*pri[j]]=phi[i]*(pri[j]-1);
       }
   }
}
int pow(int x,int y,int mod){
	long long mul=1,temp=x;
	for(;y;y/=2)
	{
		if(y&1) mul = (mul*temp)%mod;
		temp = (temp*temp)%mod;
	}
	return mul;
}
int exu(int x){
	if( x == 1) return 0;
	return pow(2,exu(phi[x])+phi[x],x);
}
int main(){
    init();
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		printf("%d\n",exu(x));
	}
	return 0;
}