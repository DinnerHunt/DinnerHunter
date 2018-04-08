//Uva101 木头问题 The Blocks Problem
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
const int maxn = 30;
vector<int> arr[maxn];
void find_block(int x, int& p, int& h){	//找到数所在的位置
	for( p = 0 ; p < n; p++)
		for( h = 0; h < arr[p].size() ; h++)
			if(arr[p][h] == x) return ;
}
void clear_above(int p,int h){			//将位置p，高度h上的数全部清除
	for(int i=h+1; i < arr[p].size(); i++){
		int b = arr[p][i];
		arr[b].push_back(b);
	}
	arr[p].resize(h+1);
}
void pile_onto(int p,int h,int p2){		//将位置p，高度h及h以上的整体挪到位置p2上
	for(int i = h ; i<arr[p].size() ; i++)
		arr[p2].push_back(arr[p][i]);
	arr[p].resize(h);
}
void print(){						//格式化输出
  	for(int i=0;i<n;i++){
  		printf("%d:",i);
  		for(int j=0;j<arr[i].size();j++)
  			printf(" %d",arr[i][j]);
  		printf("\n");
  	}
}
int main(){
	int x,y;
	cin >> n;
	string s1,s2;

	for(int i=0;i<n;i++) arr[i].push_back(i);
	while(cin >> s1 >> x >> s2 >> y){
		int px,py,hx,hy;	//分别存储x木头的所在位置和高度
		find_block(x, px, hx);	
		find_block(y, py, hy);	
		if(px == py) continue; //非法指令
		if(s2 == "onto") clear_above(py,hy);
		if(s1 == "move") clear_above(px,hx);
		pile_onto(px,hx,py);
        
	}
	print();
	return 0;
}