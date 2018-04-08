#include <iostram>
#include <string>
using namespace std;
int arr[200];
int main(){
	int number;
	while(cin >> number){
		int i=0;
		while(number){
			arr[i]=number%2;
			number/=2;
			i++;
		}
		i--;
		while(i!<0)
			printf("%d",arr[i]);
		printf("\n");
	}
	return 0;
}