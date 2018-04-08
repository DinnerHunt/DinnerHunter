//UVa 1595 对称轴 Symmetry 
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int x[N],y[N],n,mx;
 
bool isOk(int i){
	for(int j=0;j<n;j++)
		if(y[i]==y[j]&&x[i]+x[j]==mx*2) return true;
	return false;
}

int main(){
	int number,ml,mr,a,flag;
	scanf("%d",&number);
		while(number--){
			flag = 1;
			ml = mr = 0;
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				scanf("%d %d",&a,&y[i]);
				x[i]=a*2;
				if(x[i]>x[mr]) mr = i;
				if(x[i]<x[ml]) ml = i;
			}
			mx = (x[ml]+x[mr]) / 2;
			for(int i = 0;i<n;i++)
				if(!isOk(i)){flag = 0;break;} 
			if(flag)
				printf("YES\n");
			else 
				printf("NO\n");
		}
	return 0;
}