#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#define lson pid<<1
#define rson pid<<1|1
using namespace std;
const int maxd = 50005;
struct Tree{
	int sum;
	int num;
	int len;
	int rflag;
	int lflag;
}tree[4*maxd];
int n,ant,ans,last;
struct node{
	int l,r,pos,flag;
	bool operator < (const node &other) const {
	    if(pos == other.pos) return flag > other.flag;
		return pos < other.pos;
	}
}x[maxd*2];			//存边
int a[maxd],b[maxd],c[maxd],d[maxd];		//存点坐标
int Arrx[maxd*2],Arry[maxd*2],idx[maxd*2],idy[maxd*2]; // 离散化数组
map<int,int> mp1,mp2;		//离散化映射

void up(int pid,int l,int r)
{
	if(tree[pid].sum)
	{
		tree[pid].num = 1;
		tree[pid].len = idx[r]-idx[l];
		tree[pid].lflag = tree[pid].rflag = 1;
	}
	else if(l==r)
	{
		tree[pid].len = 0;
		tree[pid].num = 0;
		tree[pid].lflag = tree[pid].rflag = 0;
	}
	else
	{
	    int mid = (l+r)/2;
		tree[pid].len = tree[lson].len + tree[rson].len ;
		tree[pid].num = tree[lson].num + tree[rson].num;
		if(tree[lson].rflag&&tree[rson].lflag) tree[pid].num--;
		tree[pid].lflag = tree[lson].lflag;
		tree[pid].rflag = tree[rson].rflag;
	}
}
void add(int pid,int l,int r,int x,int y,int value)
{
	if(x<=l&&r<=y)
	{
		tree[pid].sum += value;
		up(pid,l,r);
		return;
	}
	int mid = (l+r)/2;
	if(x<=mid) add(lson,l,mid,x,y,value);
	if(y>mid) add(rson,mid+1,r,x,y,value);
	up(pid,l,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){				// 读点
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
        Arrx[i*2] = a[i];
        Arrx[i*2+1] = c[i];
        Arry[i*2] = b[i];
        Arry[i*2+1] = d[i];
    }
    sort(Arrx,Arrx+n*2);
    sort(Arry,Arry+n*2);
    int k = unique(Arrx,Arrx+n*2)-Arrx;	 //去重
    int k1 = unique(Arry,Arry+n*2)-Arry; 
    for(int i=0;i<k;i++)				//离散映射
    {
        mp1[Arrx[i]] = i+1;
        idx[i+1] = Arrx[i];
    }
    for(int i=0;i<k1;i++)
    {
        mp2[Arry[i]] = i+1;
        idy[i+1] = Arry[i];
    }
    for(int i=0;i<n;i++)
    {		
		x[ant].l=mp1[a[i]] , x[ant].r = mp1[c[i]], x[ant].pos = mp2[b[i]] ,x[ant++].flag=1;
		x[ant].l=mp1[a[i]] , x[ant].r = mp1[c[i]], x[ant].pos = mp2[d[i]] , x[ant++].flag=-1;
    }
	sort(x,x+ant);
    for(int i=0;i<ant;i++)
        printf("%d %d\n",x[i].l,x[i].r);
	for(int i=0;i<ant;i++)
	{
		add(1,1,k,x[i].l,x[i].r,x[i].flag);
		while(x[i].pos == x[i+1].pos&&x[i].flag == x[i+1].flag)
		{
			i++;
			add(1,1,k,x[i].l,x[i].r,x[i].flag);
		}
		printf("%d\n",tree[1].len);
		ans += abs(tree[1].len - last);
		last = tree[1].len;
		ans += tree[1].num*2*(idy[x[i+1].pos] - idy[x[i].pos]);
	}
	printf("%d\n",ans);
	return 0;
}