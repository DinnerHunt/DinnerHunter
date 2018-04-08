//UVa 400  Unix ls 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxcol = 60;	//每行的最长字符数
const int maxn = 100 + 5;	//文件数
string filenames[maxn];

void print(const string& s, int len, char extra){
	cout << s;
	for(int i = 0;i < len-s.length(); i++)
		cout << extra;
}

int main(){
	int n;
	while(cin >> n){
		int M = 0;
		for(int i = 0; i < n; i++){
			cin >> filenames[i];
			M = max(M, (int)filenames[i].length()); //保存最大的值
		}
		int cols = (maxcol - M) / (M + 2) + 1;	//多少列
		int rows = (n - 1) / cols + 1;			//多少行
		print("", 60 , '-');
		cout << "\n";
		sort(filenames, filenames+n);
		for(int r = 0; r < rows; r++) {
			for(int c = 0;c < cols; c++) {
				int idx = c * rows + r;
				if(idx < n) print(filenames[idx], c == cols-1 ? M : M+2, ' ');
			}
			cout << "\n";
		}	
	}
	return 0;
}