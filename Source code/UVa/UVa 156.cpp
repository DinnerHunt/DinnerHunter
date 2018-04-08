//UVa 156 Ananagrams 反片语
#include <iostream>
#include <vector>	
#include <map>			
#include <string>		//字符串长度
#include <algorithm>	//排序
using namespace std;

map<string,int> cnt;		//做映射
vector<string> words;		//存储不定量的单词数
string repr(const string& s){	//同一格式化字符串
	string ans=s;	
	for(int i=0;i<ans.length();i++)
		ans[i] = tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
}
int main(){
	int n=0;
	string s;
	while(cin >> s){
		if(s[0]=='#')
			break;
		words.push_back(s);
		string r =repr(s);
		if(!cnt.count(r)) cnt[r]=0;	//如果该集合中未出现过该字符串，新建一个映射
		cnt[r]++;				//出现一次加一次
	}
	vector<string> ans;			//存储只出现过一次的单词
	for(int i=0;i<words.size(); i++){
		if(cnt[repr(words[i])]==1) ans.push_back(words[i]);	//如果该单词格式化后映射表只有1，则存入ans
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout  << ans[i] << endl;
	return 0;
}