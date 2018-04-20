#include <cstdio>
using namespace std;
int n,m;
struct node{
	int x,y;
}arr[20];
int count(int x){
	int s=0;
	for(int i=0;i<m;i++)
		if(x&(1<<i))
			s+=arr[i].x;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d %d",&arr[m-i-1].x,&arr[m-i-1].y);

	return 0;
}