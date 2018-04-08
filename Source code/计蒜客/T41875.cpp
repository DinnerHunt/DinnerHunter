#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1010;
int n;
int tree[maxn][maxn];
void change(int i,int j,int delta){
	for(int x = i;x<=n;x+=x&-x)
		for(int y = j;y<=n;y+=y&-y)
			tree[x][y] += delta;
}
int getsum(int i,int j){
	int ans=0;
	for(int x = i;x;x -= x&-x)
		for(int y = j;y; y-=y&-y)
			ans += tree[x][y];
	return ans;
}
int main(){
	char ch;
	int a,b,c,d,m;
	scanf("%d %d",&n,&m);
	while(m--){
        cin >> ch;
		scanf("%d %d",&a,&b);
		if(ch == 'C'){
			scanf("%d %d",&c,&d);
			change(a,b,1);
			change(a,d+1,-1);
			change(c+1,b,-1);
			change(c+1,d+1,1);
		}	
		else
			printf("%d\n",getsum(a,b));
		
	}
	return 0;
}