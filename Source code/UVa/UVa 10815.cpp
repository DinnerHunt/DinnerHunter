//UVa10815 安迪的第一个字典 Andy's First Dictionary
#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;
set<string> dict;		//集合
int main(){
	string s,buf;
	while(cin >> s){		//读取一个字符串
	for(int i=0;i<s.length();i++)
		if(isalpha(s[i])) s[i] = tolower(s[i]);			//将其中字母转化成小写，其余转为空格
		else s[i] = ' ';								
	stringstream ss(s);									//将字符串写进字符串流中
	while(ss >> buf ) dict.insert(buf);					//从流中读取字符串，存入集合数组
	}
	for(set<string> :: iterator it = dict.begin();it != dict.end();it++)	//用迭代器输出集合中的内容
		cout << *it << "\n";
	return 0;
}