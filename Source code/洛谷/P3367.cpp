//luogu P3367
//DinnerHunt
#include <iostream>
using namespace std;
int fa[200000],n,m;
int k,a,b;
void init(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
}
int gf(int x){
	if(fa[x]==x) return x;
	return fa[x] = gf(fa[x]);
}
int same(int x,int y){
	return gf(x) == gf(y);
}
void until(int x,int y){
	fa[gf(x)] = gf(y);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m ;
	init();
	for(int i=1;i<=m;i++){
		cin >> k >> a >> b;
		if(k==1){
			if(!same(a,b))
				until(a,b);
        }
		else
			if(same(a,b))
				cout << "Y" << endl;
			else 
                cout << "N" << endl;
	}
	return 0;
}
