#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int ANSWER = 1234567;
typedef pair<int,int> P;
int arr[8],check;
int fx[] = {0,1,2,0,1,2,3,4,5,6}, fy[] = {1,2,3,4,5,6,7,5,6,7}; 
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
	set<int> set;
	queue<P> que;
	que.push(P(id(),1));
	set.insert(id());
	while(!que.empty()){
		P p = que.front();que.pop();
		for(int i=0;i<10;i++){
		    translate(p.first);
			arr[fx[i]] += arr[fy[i]];
			arr[fy[i]] =  arr[fx[i]] - arr[fy[i]];
			arr[fx[i]] -= arr[fy[i]];
			int k = id();
			if(set.count(k)) continue;
			if(k == ANSWER){ printf("%d\n",p.second); return;}
			que.push(P(k,p.second+1));
			set.insert(k);
		}
	}
}
int main(){
	while(scanf("%d %d %d %d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6],&arr[7])==8){
		if(id()==ANSWER) printf("0\n");
		bfs();
	}
	return 0;
}