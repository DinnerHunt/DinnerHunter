//P1449 luogu
//DinnerHunt
#include <iostream>
#include <cctype>
#include <stack>
using namespace std;
stack<int> stk;
int main(){
	ios::sync_with_stdio(false);
	char ch;
	int k=0;
	while(cin >> ch){
		if(ch == '@') break;
		if(ch=='.')
		{
			stk.push(k);
			k=0;
		}
		else if(isdigit(ch))
		{
			k = k * 10 + (ch-'0');
		}
		else
		{
			int a = stk.top(); stk.pop();
			int b = stk.top(); stk.pop();
			switch(ch)
			{
				case '+':
					stk.push(a+b);
					break;
				case '-':
					stk.push(b-a);
					break;
				case '*':
					stk.push(a*b);
					break;
				case '/':
					stk.push(b/a);
					break;
				case '%':
					stk.push(b%a);
					break;
			}

		}
	}
	cout <<stk.top();
	return 0;
}