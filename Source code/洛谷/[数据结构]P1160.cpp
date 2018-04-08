//P1160 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int r[100005],l[100005];		//左节点 右节点
int main(){
	ios::sync_with_stdio(false);
	int n,k,p,f=1;
	cin >> n;
	for(int i=2;i<=n;i++){
		cin >> k >> p;
		if(p==0&&k==f)
			f=i;
		if(p==0){		//插入左边
			r[l[k]] = i;
			l[i] = l[k];
			r[i] = k;
			l[k] = i;
		}
		else {
			l[r[k]] = i;
			r[i] = r[k];
			l[i] = k;
			r[k] = i;
		}
	}
	cin >> n;
	for(int i=2;i<=n;i++){		//删除节点
		cin >> k;
		if(!l[k]&&!r[k]) continue;
		r[l[k]] = r[k];
		l[r[k]] = l[k];
		l[k] = 0;
		r[k] = 0;
	}
	while(r[f]){
		cout << f <" ";
		f = r[f];
	}
	return 0;
}