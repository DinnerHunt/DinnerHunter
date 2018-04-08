//P1184 高手之在一起
//DinnerHunt
#include <cstdio>
#include <string>
#include <iostream>
#include <set>
using namespace std;
set<string> st;
int main(){
	int x,y,ans=0;
	string str;
	scanf("%d %d",&x,&y);
    getline(cin,str);
	for(int i=0;i<x;i++){
		getline(cin,str);
		st.insert(str);
	}
	for(int i=0;i<y;i++){
		getline(cin,str);
		if(st.count(str)) ans++;
	}
	printf("%d",ans);
	return 0;
}