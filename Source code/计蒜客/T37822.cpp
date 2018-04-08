//jisuanke T37822 回收元件
//DinnerHunt
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 6005;
vector<int> G[maxn];
int n,d[maxn],a,b,c,d;
struct node{
	int lx,ly,rx,ry;
}arr[maxn];
void topu(){
	queue<int> que;
	for(int i=1;i<=n;i++){
		if(!d[i])
			que.push(i);
	}
	while(!que.empty()){
		int k = que.front();
		cout << k;
		que.pop();
		for(int i=0;i<=G[k].size();i++){
			int l = G[k][i];
			d[l]--;
			if(!d[l])
				que.push(l);
		}
	}
}
int cmp (const node &a,const node &b){
	if(b.lx < a.rx&&b.lx>a.lx)
		if(b.ly>a.ry)
		{
			G[a][b]=1;
			d[b]++;
		}
		else
		{
			G[b][a]=1;
			d[a]++;
		}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++){
		in >> a >> b >> c >> d;
		if(a>c){
			arr[i].lx=c;
			arr[i].ly=d;
			arr[i].rx=a;
			arr[i].ry=b;
		}
		else {
			arr[i].lx=a;
			arr[i].ly=b;
			arr[i].rx=c;
			arr[i].ry=d;
		}
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(i!=j) cmp(arr[i],arr[j]);
	topu();
	return 0;
}