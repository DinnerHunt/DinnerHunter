//UVa11853 
//战场 Paintball
//DinnerHunt
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 1000 + 1;
const double W = 1000;

int x[maxn], y[maxn], r[maxn];            //障碍物的x坐标 y坐标 半径范围
int n;
double left,right;

bool intersect(int a,int b) {             //判断是否有交点
   return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])) < r[a]+r[b];
}
void check(int u)                         
{
   if(x[u] < r[u]) left = min(left, y[u] - sqrt(r[u]*r[u] - x[u]*x[u]));   //如果与左边有交点 则把左边与圆相交的点的下方   r为最长边 x为点到左边的距离 求点y
   if(x[u]+r[u] > W) right = min(right,y[u] - sqrt(r[u]*r[u] - (W-x[u])*(W-x[u]) ) ) ;
}                                                                    //同上 W-x[u] 是r 到右边的距离
int vis[maxn];
//top to bottom
bool dfs(int u)
{
   if(vis[u]) return false;              //是否访问过    
   vis[u] = 1;
   if(y[u] < r[u]) return true;           //如果与下边有相交
   for(int v = 0; v < n; v++){   
      if(intersect(u,v) && dfs(v)) return true;    //如果有交点 并且
   }
   check(u);
   return false;
}


int main()
{
   while(~scanf("%d",&n)) {                        //n个障碍物
      bool ok = true;                              //地图是否是联通的
      memset(vis,0,sizeof(vis));          
      left = right = W;                            //初始化左右边界
      for(int i = 0; i < n; i ++){
         scanf("%d%d%d",x+i,y+i,r+i);
      }
      for(int i = 0; i < n; i ++) {
         if(r[i]+y[i]>=W && dfs(i)) {ok = false; break;}    //如果覆盖了战场的上边界
      }
      if(ok) printf("0.00 %.2lf 1000.00 %.2lf\n",left,right);
      else printf("IMPOSSIBLE\n");
   }
   return 0;
}