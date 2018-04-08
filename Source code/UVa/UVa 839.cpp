//UVa 839 天平 Not so Moblie
#include <iostream>

using namespace std;

bool solve(int& W){			//因为传值 所以只需返回是否平行，而无需返回变量
	int W1,D1,W2,D2;
	bool b1=true,b2=true;
	cin >> W1 >> D1 >> W2 >> D2;
	if(!W1) b1=solve(W1);		//W1 = 子叶 W1+W2
	if(!W2) b2=solve(W2);		//W2 = 子叶的 W1+W2
	W = W1+W2;				//会递归的改变下列的值
	return b1&&b2&&(W1*D1==W2*D2);
}

int main(){
	int T,W;
	cin >> T;
	while(T--){
		if(solve(W)) cout << "YES\n"; else cout <<"NO\n";
		if(T) cout << "\n";
	}
	return 0;
}