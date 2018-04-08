#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> P;
queue<P> que; 
vector<int> vet;
struct node{
	int num,id;
}arr[1010][1010];
int env,x,y,flag;
int fx[4]={0,0,1,-1},fy[4]={1,-1,0,0};
void bfs(int x1,int y1){
	env = 1;
    arr[x1][y1].id=vet.size();
	flag = arr[x1][y1].num;
	que.push(P(x1,y1));
	while(que.size()){
        x1=que.front().first;y1=que.front().second;
        que.pop();
		for(int i=0;i<4;i++)
		{
			int x2=x1+fx[i],y2=y1+fy[i];
			if(x2>0&&x2<=x&&y2>0&&y2<=x&&arr[x2][y2].id==-1&&arr[x2][y2].num^flag)
			{
				env++;
				arr[x2][y2].id=vet.size();
				que.push(P(x2,y2));
			}
		}
		flag^=1;
	}
	vet.push_back(env);
}
int main(){
    char ch;
	cin >> x >> y;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x;)
		{
			cin >> ch;
            if(ch=='\n')continue;
            arr[i][j].num = ch - '0';
			arr[i][j].id = -1;
            j++;
            
		}
    }
	for(int i=1;i<=x;i++)
		for(int j=1;j<=x;j++)
		{
			if(arr[i][j].id==-1)
				bfs(i,j);
		}
	int n,m;
	for(int i=0;i<y;i++)
	{
		if(i)cout<< endl;
		cin >> n >> m;
		cout << vet[arr[n][m].id];
	}
	return 0;
}