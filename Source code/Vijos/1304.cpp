//vijos 1304 回文数
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 10000+10;
char str[maxn];
char str2[maxn];
char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
map<char,int> mp;
void init(){
	for(int i=0;i<=16;i++)
		mp[arr[i]]=i;
	int len = strlen(str);
	int i=0,j=len-1;
	while(i<j){
		char ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
}
void add(int n){
	int len = strlen(str),s=0,m;
	for(int i=0;i<len;i++){
	    m=mp[str[i]]+mp[str[len-1-i]]+s;
	    s = m/n;
	    str2[len-1-i]= arr[m%n];
	}
	if(s)
		str[len] = s ;
	strcpy(str,str2);
}

bool ishuiwen(){
	int len = strlen(str);
	int i=0,j=len-1;
	while(i<=j){
		if(str[i++]!=str[j--]){
			return false;
		}
	}
	return true;
}
int main(){
	int n,i=0;
	scanf("%d",&n);
	scanf("%s",str);
	init();
	while(i<=30){
		if(ishuiwen(strlen(str))){
			printf("STEP=%d",i);
			i=0;break;
		}
		add();
		i++;
	}
	if(i==31)
		printf("Impossible!");
	return 0;
}