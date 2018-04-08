//UVa 673
//平衡的括号 Parentheses Balance
//DinnerHunt
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
stack<char> stk;
int main(){
    int n;
    char ch;
    char str[130];
    scanf("%d",&n);
    ch = getchar();	//多余的回车
    while(n--){
        while(!stk.empty())stk.pop();
        bool flag=true;
        fgets(str,130,stdin);
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='\n')continue;
            if(str[i]=='('||str[i]=='[')
                stk.push(str[i]);
            else{
                if(stk.empty()){
                    flag = false;
                    break;
                }
                char ch = stk.top();
                stk.pop();
                if(!((ch=='('&&str[i]==')')||(ch=='['&&str[i]==']'))){
                    flag = false;
                    break;
                }
            }
        }
        if(flag&&stk.empty()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

2017/12/4

思路

遍地字符串，如果是'['或'('就压入栈 如果是']'或')' 就弹出 如果弹出的括号类型和现在的不匹配 或者 遍地完栈内还有剩
则不合法，否则合法

构造

因为有空字符串的存在，用fgets来读入，用STL的栈来储存，测试数据前记得清空栈