//UVa540 团体队列 Team Queue
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
const int maxt = 1000 + 10;

int main ()
{
    int t, kase = 0;
    while(scanf("%d", &t)!=EOF && t){
       	printf("Scenario #%d\n",++kase);
		map<int, int> team;	 //记录团队编号
		for(int i = 0; i < t; i++){
			int n,x;
			scanf("%d", &n);
			while(n--) { scanf("%d", &x); team[x] = i; }
		}
		//模拟
		queue<int> q,q2[maxt];	//q代表团队队列，q2[i]是成员队列
		for(;;){
			int x;
			char cmd[10];
			scanf("%s",cmd);
			if(cmd[0]=='S') break;		//STOP
			else if(cmd[0] == 'D'){		//DEQUEUE 出队
				int t = q.front();		//第一个人是哪个团队的
				printf("%d\n", q2[t].front());
				q2[t].pop();	//团队的第一人出队；
				if(q2[t].empty()) q.pop();	//如果t全体出队
			}
			else if(cmd[0] == 'E'){
				scanf("%d",&x);
				int t = team[x];	//获取团队的编号
				if(q2[t].empty()) q.push(t);
				q2[t].push(x);
			}
		}
		printf("\n");
	}
	return 0;
}