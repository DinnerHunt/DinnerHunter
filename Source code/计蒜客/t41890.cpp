#include <cstdio>
using namespace std;
const int maxd = 100005;
int arr[maxd],vis[maxd];
int main()
{
    int n,a,begin,end;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        arr[i] = (arr[i-1] + a) %mod;
    }
    for(int i=1;i<=n;i++)
    {
    	if(vis[arr[i]])
    	{
    		begin = vis[arr[i]];
    		end = i;
    		printf("%d\n",i - vis[arr[i]]+1);
    		break;
    	}
    	vis[arr[i]] = i;
    }
    for(int i=begin;i<=end;i++){
		if(i!=begin) printf(" ");
		printf("%d",i);   
    }

    return 0;
}