//UVa 10603
//Fill 倒水问题
//DinnerHunt
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Node{
	int v[3],dist;
	bool operator < (const Node& rhs) const{
		return dist > rhs.dist;
	}	
};
const int maxn = 200+5;
int vis[maxn][maxn],cap[3],ans[maxn];	//判重数组，杯子大小

void updata_ans(const Node& u){
	for(int i=0;i<3;i++){
		int d = u.v[i];
		if(ans[d] < 0||u.dist<ans[d]) ans[d] = u.dist;
	}
}
void solve(int a,int b,int c,int d){
	cap[0] = a;cap[1] = b;cap[2] = c;
	memset(vis,0,sizeof(vis));
	memset(ans,-1,sizeof(ans));
	priority_queue<Node> q;
	Node start;				//当前 杯子的状态
	start.dist = 0;
	start.v[0] = 0;
	start.v[1] = 0;
	start.v[2] = c;
	q.push(start);

	vis[0][0]=1;
	while(!q.empty()){
		Node u = q.top();q.pop();
		updata_ans(u);
		if(ans[d] >=0 ) break;	//如果有杯子出现了d值,则查找结束
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(i!=j){					
					if(u.v[i]==0||u.v[j]==cap[j]) continue;				//将i中的水倒入j中去
					int amount = min(cap[j],u.v[i]+u.v[j]) - u.v[j];	//流动的水量
					Node u2;											//下一个状态
					memcpy(&u2,&u,sizeof(u));
					u2.dist = u.dist+amount;
					u2.v[i] -= amount;
					u2.v[j] += amount;
					if(!vis[u2.v[0]][u2.v[1]]){							//判断是否重复
						vis[u2.v[0]][u2.v[1]] =1;
						q.push(u2);
					}
				}
	}
    while(d>=0){
    	if(ans[d]>=0){
    		printf("%d %d\n",ans[d],d);
    		return;
    	}
    	d--;
    }
}
int main(){
	int T,a,b,c,d;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		solve(a,b,c,d);
	}
	return 0;
}