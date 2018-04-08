//UVa 572 Oil Deposits
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100 + 10;

int arr[maxn][maxn],n,x,y;

void dfs(int x,int y){
	arr[x][y]='*';
	for(int i=-1;i<1;i++){
		for(int j=-1;j<1;j++){
			int nx=x+i,ny=y+j;
			if(nx>=0&&nx<x&&ny>=0&&ny<=y&&arr[nx][ny]=='@')
				dfs(nx,ny);
		}
	}
}
int main(){
	while(cin >> x >> y){
		n=0;
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++)
				cin >> arr[x][y];
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++)
				if(arr[x][y]=='@'){
					dfs(x,y);
					n++;
				}
		cout << n << endl;	
	}
	return 0;
}