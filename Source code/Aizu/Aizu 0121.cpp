#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int ANSWER = 1234567;
typedef pair<int,int> P;
vector<int> st[ANSWER];
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
void bfs(int s){
	queue<P> que;
	que.push(P(s,1));
	st.push_back();
	while(!que.empty()){
		P p = que.front();que.pop();
		translate(p.first);
        int old[8];
        memcpy(old,arr,sizeof(arr));
		int b = find();
		for(int i=0;i<4;i++){
            memcpy(arr,old,sizeof(arr));
			int a = b+fx[i];
            if((a==4&&i==0)||(a==3&&i==1)) continue;
			if(a<0||a>=8) continue;
			arr[b] += arr[a];
			arr[a] = arr[b] - arr[a];
			arr[b] -= arr[a];  
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
		int k = id();
        if(k==ANSWER) printf("0\n");
		bfs(k);
	}
	return 0;
}