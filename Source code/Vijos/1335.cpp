//vjios 1335 数独
#include <cstdio>
#include <cstring>
using namespace std;
int arr[9][9],tr[9];
int main(){
	int number,flag,i,j;
	scanf("%d",&number);
	while(number--){
		flag = 1;

		memset(tr,0,sizeof(tr));

		for(i=0;i<9;i++)
			for(j=0;j<9;j++){
				scanf("%d",&arr[i][j]);
				tr[arr[i][j]-1]++;
			}
		int sum1 = 0,sum=0;

		for(i=0;i<9;i++){			//判断每行每列是否和为45；
			int sum1 = 0,sum=0; 
			for(j=0;j<9;j++){
				sum += arr[i][j];
				sum1 += arr[j][i];
			}
			if(sum!=45||sum1!=45){
				flag=0;
			}
		}

		sum =0 ;
		for(i=0;i<3;i++)		//预防例2情况出现
			for(j=0;j<3;j++){
				sum+=arr[i][j];
			}
		if(sum!=45){
			flag=0;
		}

		for(int i=0;i<9;i++){	//预防数不全，但和为45的情况出现
			if(tr[i]!=9)
				flag=0;
		}

		if(flag)
			printf("Right\n");
		else
			printf("Wrong\n");
	}
	return 0;
}