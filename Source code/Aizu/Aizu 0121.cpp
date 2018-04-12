#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int ANSWER = 1234567;
map<int,int> mp;
int arr[8],check;
int fx[]={-1,1,-4,4};
int find(){
	for(int i=0;i<8;i++)
		if(!arr[i]) return i;
}
int id(){
	int ans=0;
	for(int i=0;i<8;i++)
		ans = ans * 10 + arr[i];
	return ans;
}
void translate(int ans){
	for(int i=7;i>=0;i--)
		arr[i] = ans%10,ans/=10; 
}
void bfs(){
	queue<int> que;
	que.push(ANSWER);
	mp[ANSWER] = 1;
	while(!que.empty())
	{
		int p = que.front();que.pop();
		translate(p);
		int a = find();
		for(int i=0;i<4;i++)
		{
			int b = a + fx[i];
			if(b<0||b>7||(b==4&&i==0)||(b==3&&i==1)) continue;
			swap(arr[a],arr[b]);
			int k = id();
            swap(arr[a],arr[b]);
			if(mp[k]) continue;
			mp[k]=mp[p]+1;
			que.push(k);
		}
	}
}
int main(){
	bfs();
	while(scanf("%d %d %d %d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6],&arr[7])==8)
	{
		printf("%d\n",mp[id()]-1);
	}
	return 0;
}