//P1087 luogu
//DinnerHunt
#include <iostream>
using namespace std;
string str,key="";
char dg(int l,int r){
	if(l==r){							//这是终止条件 如果只剩一个字符串的时候 也就是l和r相等的时候(当前节点没有儿子时)
        char x = (str[l]=='1'?'I':'B');  //如果当前字符是0 则是个B串，是1则是个I串 
        key+=x;							//加上最小字符串的串值（B,I）;
		return x;						//这个串是什么串 返回上去
	}
	int mid = (l+r)/2;
	char a=dg(l,mid);					//递归的方式，分别求左儿子和右儿子
	char b=dg(mid+1,r);						
	if(a==b)							//如果儿子相等 则当前串和儿子相同
	{
		key+=a;
		return a;
	}
	key+="F";							//如果不等 则当前串为F串
	return 'F';
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
int main(){
	ios::sync_with_stdio(false);
	int n;								//这里的N可以无视
	cin >> n;
	cin >> str;							//读取字符串
	dg(0,str.length()-1);				//递归的分析字符串
	cout << key;
	return 0;
}