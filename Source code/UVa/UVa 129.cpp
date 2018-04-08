//UVa 129
//kRYPTON fACTOR 困难的串=
//DinnerHunt
#include <cstdio>
using namespace std;
int m,n,cnt;
int arr[100];
int dfs(int cut){
    if(cnt++ == m) {
    	for(int i = 0; i < cut; i++) {
      		if(i % 64 == 0 && i > 0) printf("\n");
      		else if(i % 4 == 0 && i > 0) printf(" ");
      		printf("%c", 'A'+arr[i]); // 输出方案
    }
    printf("\n%d\n", cut);
    return 0;
  }
    for(int i = 0;i<n;i++){
        arr[cut] = i;
        int ok = 1;
        for(int j=1;j*2<=cut+1; j++){
            int equal = 1;
            for(int k= 0;k<j;k++)
                if(arr[cut-k] != arr[cut-k-j]) {equal = 0;break;}
            if(equal){ok=0;break;}
        }
        if(ok) if(!dfs(cut+1)) return 0;
    }
    return 1;
}
int main(){
    while(scanf("%d %d",&m,&n)==2&&n&&m){
        cnt = 0;
        dfs(0);
    }
    return 0;
}