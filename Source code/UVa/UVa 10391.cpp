//UVa 10391 复合词 Compound Words
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;
vector<string > list;
set<string > box;
set<string > book;

int main(){
	string str;
	while(cin >> str)
		box.insert(str);
	for(set<string>::iterator it=box.begin();it!=box.end();it++){
        string str=*it;
		if(str.length()>=2)
			for(int i=1;i<str.length();i++){
				if(box.count(str.substr(0,i))&&box.count(str.substr(i))){
					book.insert(str);
					break;
				}
			}
    }

	for(set<string>::iterator it=book.begin();it!=book.end();it++)
		cout << *it << endl;
	return 0;
}