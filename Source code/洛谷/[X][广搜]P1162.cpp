//P1162 luogu
//DinnerHunt
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> P;
queue<P> que;
int arr[35][35];
int arr2[35][35];
int number;
int fx[4]={0,0,-1,1},fy[4]={1,-1,0,0};
void bfs(int x,int y){
	arr[x][y]=1;
	que.push(P(x,y));
	while(que.size())
	{
		P p=que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			int x2=p.first+fx[i],y2=p.second+fy[i];
			if(x2>0&&x2<=number&&y2>0&&y2<=number&&arr[x2][y2]==0)
			{
				arr[x2][y2]=1;
				que.push(P(x2,y2));
			}
		}
	}
}
int main(){
	cin >> number;
	for(int i=1;i<=number;i++)
		for(int j=1;j<=number;j++){
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
		}
	
	for(int i=1;i<=number;i++)
		for(int j=1;j<=number;j++){
			if((i==1||j==1||i==number||j==number)&&arr[i][j]==0)
			bfs(i,j);
		}
	for(int i=1;i<=number;i++){
		for(int j=1;j<=number;j++){
			if(j!=1)cout << " ";
			if(arr[i][j]==0)
				cout << 2;
			else 
				cout << arr2[i][j];
		}
	cout <<endl;
    }
	return 0;
}