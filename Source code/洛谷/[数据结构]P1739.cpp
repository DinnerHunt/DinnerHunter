//P1739 luogu
//DinnerHunt
#include <iostream>
#include <stack>
using namespace std;
stack<int> stk;
int main(){
	ios::sync_with_stdio(false);
	int flag=0;
	char ch;
	while(cin >> ch){
		if(ch == '@'){
			break;
		}
		else if(ch == '(')
			stk.push(1);
		else if(ch==')'){
			if(stk.empty())
				flag = 1;
			else 
				stk.pop();
		}
	}
	cout << flag?"NO":"YES";
	return 0;
}