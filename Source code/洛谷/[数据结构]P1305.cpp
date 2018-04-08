//P1305 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int l[1000],r[1000],n,ch;
string str;
void fr(ch){
	if(ch=='*'-'a') return;		//如果是'*'这表示没有子树了
	cout << char(ch+'a'); //先序遍地 先输出结果
	fr(l[ch]);			//遍地左树
	fr(r[ch]);			//遍地右树
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> str;
		if(!i) ch = str[0]-'a';		//储存根节点
		l[str[0]-'a'] = str[1]-'a';		//当前节点的左节点
		r[str[0]-'a'] = str[2]-'a';		//当前节点的右节点
	}
	fr(ch);		//遍地根节点
	return 0;
}