//UVa 1596 更新字典 Updating a Dictionary
#include <bits/stdc++.h>
using namespace std;
map<string,string> mp;
set<string> jia;
set<string> jian;
set<string> cheng;

void read(string &str, int flag){
	string s,s1;
	str=str.substr(1,str.length()-1);
	for(int i=0;i<str.length();i++){
		if(str[i]==':'){
			s1=s;
            s="";
		}
		else if((str[i]==','||str[i]=='}')&&s!=""){
			if(!flag){
				mp[s1]=s;
			}
			else{
				if(mp.count(s1)){
					if(mp[s1]!=s){
						cheng.insert(s1);
					}
					mp.erase(s1);
				}
				else {
					jia.insert(s1);
				}
			}
            s="";
		}
		else {
			s = s+str[i];
		}
	}
}
void check(){
	for(map<string ,string >::iterator it = mp.begin(); it !=mp.end();it++){
		jian.insert(it->first);
	}
	if(!(jia.size()+jian.size()+cheng.size())){
		cout <<"No changes" << endl;
	}
	else{
		if(jia.size()){
			cout << "+";
			for(set<string>::iterator it = jia.begin();it!=jia.end();it++){
				if(it!=jia.begin())
					cout << ",";
				cout << (*it);
			}
			cout <<endl;
		}
		if(jian.size()){
			cout << "-";
			for(set<string>::iterator it = jian.begin();it!=jian.end();it++){
				if(it!=jian.begin())
					cout << ",";
				cout << (*it);
			}
			cout <<endl;
		}
		if(cheng.size()){
			cout << "*";
			for(set<string>::iterator it = cheng.begin();it!=cheng.end();it++){
				if(it!=cheng.begin())
					cout << ",";
				cout << (*it);
			}
			cout <<endl;
		}
	}	
}
void print(){
	for(map<string,string>::iterator it = mp.begin();it!=mp.end();it++){
		cout << it->first << ":" << it -> second << " ";
	}
}
void clear(){
    jia.clear();
    jian.clear();
    cheng.clear();
    mp.clear();
}
int main(){
	int number;
	string str1,str2;
	cin >> number;
	while(number--){
		cin >> str1 >> str2;
		read(str1,0);
		//print();
		read(str2,1);
		check();
        clear();
        cout << endl;
	}
	return 0;
}