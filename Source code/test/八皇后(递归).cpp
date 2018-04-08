#include <iostream>
#include <cmath>
using namespace std;
int queenPos[100];
int N;
void NQueen(int k){
	int i;
	if(k==N)
	{
		for(i=0;i<N;i++)
			cout <<queenPos[i]+1<< " ";
			cout << endl;
			return;
	}
	for(i=0;i<N;i++)		//判断列
	{
		int j;
		for(j=0;j<k;j++)	//判断和之前行是否会冲突
		{		//列相等的情况 ，或者 行与列之差等于行与行之差 则斜对角会被吃
			if(queenPos[j] == i || abs(queenPos[j] - i) == abs(k-j))	
				break;
		}
		if(j==k)	//不冲突
		{
			queenPos[k] = i;	//第
			NQueen(k+1);
		}
	}
}
int main(){
    N=6;
    NQueen(0);
    return 0;
}