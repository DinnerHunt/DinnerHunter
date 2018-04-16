//P1230 luogu
//DinnerHunt
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int x,y;
	bool operator < (const node &c)
	{
		if(y==c.y)
			return x<c.x;
		return y<c.y
	}
}
int arr[500],m,n,a,b,k;
int main(){
	printf("%d",m-k);
	return 0;
}
