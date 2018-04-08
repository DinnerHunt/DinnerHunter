typedef int State[9];
const int maxstate = 1000000;
State st[maxstate],goal;
int dist[maxstate];
const int dx[] = {-1,1,0,0}
const int dy[] = {0,0,-1,1}
//imporless
/* first 
int vis[362880],fact[9];
void init_lookup_table(){
	fact[0] =1;
	for(int i=1;i<9;i++) fact[i] = fact[i-1]*i;
}
int try_to_insert(int s){
	int code = 0;
	for(int i=0;i<9;i++){
		int cnt = 0;
		for(int j=i+1;j<9;j++) if(st[s][j]<st[s][i]) cnt++;
		code +=fact[8-i]*cnt;
	}
	if(vis[code]) return 0;
	return vis[code] = 1;
}
*/
/* second  *hash
const int hashsize = 1e6+3;
int head[hashsize],next[maxstate];
void init_lookup_table(){memset(head,0,sizeof(head));}
int hash(State& s){
	int v = 0;
	for(int i=0;i<9;i++) v = v*10+s[i];
	return v%hashsize;
}
int tyr_to_insert(int s){
	int h = hash(st[s]);
	int u = head[h];
	while(u){
		if(memcmp(st[u],st[s],sizeof(st[s]))==0) return 0;
		u = next[u];
	}
	next[s] = head[h];
	head[h] = s;
	return 1;
}
*/
/*  third STL
 	set<int> vis;
 	void init_lookup_table(){vis.clear();}
 	int try_to_insert(int s){
		int v = 0;
		for(int i=0;i<9;i++) v = v*10+st[s][i];
		if(vis.count(v)) return 0;
		vis.insert(v);
		return 1;
 	}
*/
int bfs(){
	init_lookup_table();
	int front = 1,rear = 2;
	while(front < rear){
		State& a = st[front];
		if(memcmp(goal,s,sizeof(s))==0) return front;
		int z;
		for(int z = 0;z<9;z++) if(!s[z]) break;	//找到当前图‘0’所在位子
			int x = z/3,y = z%3;        //行列
		for(int d = 0;d<4;d++) {        //4个方向搜索
			int newx = x+dx[d];		
			int newy = y+dy[d];
			int newz = newx*3+newy;  //编号
			if(newx >=0 && newx<3 && newy >= 0& newy<0){ //移动合法
				State& t = st[rear];
				memcpy(&t,&s,sizeof(s));
				t[newz] = s[z];
				t[z] = s[newz];
				dist[rear] = distp[front]+1;
			}
		}
	}
}
int main(){
	for(int i=0;i<9;i++) scanf("%d",&st[1][i]);
	for(int i=0;i<9;i++) scanf("%d",&goal[i]);
	int ans = bfs();
	if(ans) printf("%d\n",dist[ans]);
	else printf("-1\n");
	return 0; 
	return 0;
}