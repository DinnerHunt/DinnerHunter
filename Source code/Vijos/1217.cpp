//Vijos 1217 兵乓球
#include <iostream>
#include <cmath>
using namespace std;
char arr[100000];

void oput(int cap,int type){
	int w=0,l=0;
	for(int i=0;i<cap;i++){
		if(letter[i]=='W')
			w++;
		if(letter[i]=='L')
			l++;
		if(((w==type||l==type)&&(abs(l-w)>=2))||((w>type||l>type)&&(abs(l-w)==2))){
			cout << w << ':' << l;
			w=0,l=0;
			cout << endl;
		}
	}
	cout << w << ':' << l;
}

int main(){
	char ch;
	int i=0;
	while(scanf("%c",&ch)==1&&ch!='E'){
		if(ch=='\n')
			continue;
		arr[i++]=ch;
	}
	oput(i,11);
	cout << endl << endl;
	oput(i,21);
	return 0;
}