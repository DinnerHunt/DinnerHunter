#include <iostream>
using namespace std;
int is=0;
char arr[105][105];
int flag[105][105];
string str="yizhong";
int fx[8]={1,1,1,0,0,-1,-1,-1},fy[8]={-1,0,1,-1,1,-1,0,1};
bool dfs(int x,int y,int k,int l)
{
	if(k==7)
		return 1;
    int x1=x+fx[l],y1=y+fy[l];
    if(arr[x1][y1]==str[k]){
        if(dfs(x1,y1,k+1,l)){
            flag[x1][y1] = 1;
            return 1;
        }
    }
    return 0;
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin >> arr[i][j];

		}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]=='y'){
                for(int k=0;k<8;k++)
                    if(dfs(i,j,1,k)) flag[i][j]=1;
            }
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(flag[i][j])
                cout << arr[i][j];
            else
                cout << "*";
		cout << endl;
	}
	return 0;
}