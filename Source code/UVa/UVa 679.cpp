//UVa 679 小球落下 Dropping Balls
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int D,I,number; //完全二叉树深度，小球个数
    scanf("%d",&number);
	for(int j=0;j<number;j++){
        scanf("%d%d",&D,&I);
		int k=1;
		for(int i=0;i<D-1;i++){
			if(I%2){ k=k*2;I=(I+1)/2;}
			else {k=k*2+1;I/=2;}
		}
		printf("%d\n",k);
    }
	return 0;
}