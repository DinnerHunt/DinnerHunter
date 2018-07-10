#include <cstdio>
#include <cstring>
using namespace std;
const int maxd = 10000005;
int n,a,b,l,r,next[maxd],c[maxd],ans;
char str[maxd],p[maxd];
int main(){
	scanf("%d %d %d %d %d %s",&n,&a,&b,&l,&r,p);
	c[0] = b,next[0]=-1;
	for(int i=1;i<n;i++)
		c[i] = (c[i-1]+a)%n;
	for(int i=0;i<n;i++)
	{
		if(c[i]>=l&&c[i]<=r)
			if(c[i]%2==0) str[i] = 'A';
			else str[i] = 'T';
		else 
			if(c[i]%2==0) str[i] = 'G';
			else str[i] ='C';
	}
    
	int match = -1;
	for(int i=1;p[i];i++){
		while(match >=0&&p[match+1]!=p[i])
			match = next[match];
		if(p[match+1] == p[i])
			match++;
		next[i] = match;
	}
	match=-1;
	for(int i=0;i<n;i++)
	{
		while(match>=0&&p[match+1]!=str[i])
			match = next[match];
		if(p[match+1] == str[i]){
			match++;
			if(!p[match+1])
				ans++;
		}
	}
	printf("%d",ans);
	return 0;
}