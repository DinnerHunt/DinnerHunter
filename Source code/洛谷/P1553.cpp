//P1533 luogu
//DinnerHunt
#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
int main(){
    stack<char> s;
    char c,op=' ';
    string ss;
    getline(cin,ss);
    stringstream in(ss);
    bool f=true;
    while(in>>c){
        if(c>='0'&&c<='9') {
            if(op!='.') s.push(c);
            else {
                if(!(c=='0'&&f)) s.push(c);
                if(c!='0') f=false;
            }
        }
        else{
            op=c;
            while(!s.empty()&&s.top()=='0') s.pop();
            if(s.empty()) cout<<0;
            while(!s.empty()) {
                cout<<s.top();
                s.pop();
            }
            cout<<op;
        }
    }
    while(!s.empty()&&s.top()=='0') s.pop();
    if(op!='%') if(s.empty()) cout<<0;
    while(!s.empty()) {
        cout<<s.top();
        s.pop();
    }
    return 0;
}