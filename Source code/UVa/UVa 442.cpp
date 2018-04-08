//UVa 442 矩形链乘 (Matrix Chain Multiplication)
#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){};
}m[26];
stack<node> stk;
int main(){
	int number;
	string s;
	cin >> number;
	for(int i=0;i<number;i++){
		cin >> s;
		int k=s[0]-'A';
        cin >> m[k].x >> m[k].y;
	}
	string str;
	while(cin >> str){
		int len =str.length();
		bool flag = false;
		int sum = 0;
		for(int i=0;i<len;i++){
			if(isalpha(str[i])) stk.push(m[str[i]-'A']);
			else if(str[i]==')'){
				node a= stk.top();stk.pop();
				node b= stk.top();stk.pop();
				if(b.y!=a.x) {flag = true; break;}
				sum+=b.y*b.x*a.y;
				stk.push(node(b.x,a.y));
			}
		}
		if(flag)
			printf("error\n");
		else
			printf("%d\n",sum);
	}
	return 0;
}