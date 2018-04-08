//UVa 1595 对称轴 Symmetry 
#include <cstdio>
#include <iostream>
#include <set>

using namespace std;
struct node
{
	int x,y;
	node(int x,int y):x(x),y(y){}
	bool operator < (const node& r) const { return x<r.x || x==r.x && y<r.y; } 
};
set<node> SetNode;
int main(){
	int number;
	cin >> number;
	while(number--){
		int n;
		cin >> n;
		int a=0,b=0,x,y,flag=1;
		double Seoul;
		for(int i=0;i<n;i++){
			cin >> x >> y;
			x=x*2;
			if(i==0)
				a=b=x;
			else{
				if(a>x)
					a=x;
				if(b<x)
					b=x;
			} 

			SetNode.insert(node(x,y));
		}
		Seoul=(a+b)/2;
		for(set<node>::iterator it=SetNode.begin();it!=SetNode.end();it++){
			node nd=*it;
			int x = Seoul-nd.x+Seoul;
			int y = nd.y;
			if(!SetNode.count(node(x,y))){
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}