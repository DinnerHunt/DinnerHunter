//P1205 方块转换
//DinnerHunt
#include <cstdio>
using namespace std;
int n;
char G[15][15],A[15][15],B[15][15];
void nightzore(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			B[i][j] = G[n-1-j][i];
}
void oneeightzore(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			B[i][j] = G[n-1-i][n-1-j];
}
void twosevenzore(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			B[i][j] = G[j][n-1-i];
}
void fz(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			B[i][j] = G[i][n-1-j];
}
bool check(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(A[i][j]!=B[i][j])
                return false;
    return true;
}
int main(){
	char ch;
	scanf("%d",&n);
    ch = getchar();
	for(int i=0;i<n;i++)
			fgets(G[i],60,stdin);
	for(int i=0;i<n;i++)
			fgets(A[i],60,stdin);
	if(check()){
		printf("%d",6);
		return 0;
	}
	nightzore();
	if(check()){
		printf("%d",1);
		return 0;
	}
	oneeightzore();
	if(check()){
		printf("%d",2);
		return 0;
	}
	twosevenzore();
	if(check()){
		printf("%d",3);
		return 0;
	}
	fz();
	if(check()){
		printf("%d",4);
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			G[i][j] = B[i][j];
	nightzore();
	if(check()){
		printf("%d",5);
		return 0;
	}
	oneeightzore();
	if(check()){
		printf("%d",5);
		return 0;
	}
	twosevenzore();
	if(check()){
		printf("%d",5);
		return 0;
	}
	printf("7");
	return 0;
}