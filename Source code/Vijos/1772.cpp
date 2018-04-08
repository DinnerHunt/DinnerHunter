//vijos 1772 巧妙填数
#include <cstdio>
#include <cstring>
using namespace std;

void ok(int i,int j,int h){
	if(i==j||j==h||i==h)
		return;
	int sum = i*100+j*10+h;
    if(sum > 333)
        return;
	int x = 2*sum;
	int y = 3*sum;
	int arr[10];
	memset(arr,0,sizeof(arr));
	arr[i]++;arr[j]++;arr[h]++;
	arr[x/100%10]++;arr[x%100/10]++;arr[x%10]++;
	arr[y/100%10]++;arr[y%100/10]++;arr[y%10]++;
	for(int i=0;i<10;i++){
		if(arr[i]>1||arr[0]>0)
            return ;
	}
	printf("%d %d %d\n",sum,x,y);
}

int main(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=9;j++)
			for(int h=1;h<=9;h++)
				ok(i,j,h);
	return 0;
}
