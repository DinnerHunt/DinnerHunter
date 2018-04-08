#include<cstdio>
#include<cstring>
using namespace std;
int arr[10][10],flag[10][10];
int n,x,y,ans;
int fx[8] = {1,1,1,0,-1,-1,-1,0},fy[8] ={1,0,-1,-1,-1,0,1,1};
inline int abs(int x){
	return x<0?-x:x;
}
inline int max(int x,int y){
	return x<y?y:x;
}
void dfs(int a,int b,int sum){
	if(a==x){
		ans = max(ans,sum);
		return;
	}
	int f = 1;
	for(int i=0;i<8;i++)
		if(a+fx[i]>=0&&a+fx[i]<x&&b+fy[i]>=0&&b+fy[i]<y)
		if(flag[a+fx[i]][b+fy[i]])
		{
			f=0;
			break;
		}
	if(f){
		flag[a][b]=1;
		dfs(a+((b+1)/y),(b+1)%y,sum+arr[a][b]);
		flag[a][b]=0;
	}
	dfs(a+((b+1)/y),(b+1)%y,sum);
}
int main(){
	scanf("%d",&n);
	while(n--){
		ans=0;
		scanf("%d %d",&x,&y);
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++)
				scanf("%d",&arr[i][j]);
		dfs(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}