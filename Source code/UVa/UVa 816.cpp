//UVa Abbott的复仇 Abbott's Revenge
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;


struct Node{
	int r,c,dir;//dir朝向(0~3)分别标识N,E,S,W
	Node(int r,int c, int dir):r(r),c(c),dir(dir){}
};

const int maxn = 10;
const char* dirs = "NESW";					//顺时针旋转
const char* turns = "FLR";

int has_edge[maxn][maxn][4][3];
int d[maxn][maxn][4];
Node p[maxn][maxn][4];
int r0,c0,dir,r1,c1,r2,c2;

int dir_id(char c){ return strchr(dirs, c) - dirs; }
int turn_id(char c) { return strchr(turns,c) - turns; }

const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

bool inside(int r,int c){				//判断是否越界
	return r >= 1 && r<=9 && c >=1 && c <=9;
}

bool read_case(){
	char s[99],s2[99];
	if(scanf("%s%d%d%s%d%d",s,&r0,&c0,s2,&r2,&c2)!=6)
}

Node walk (const Node& u,int turn){		//转弯
	int dir = u.dir;
	if(turn == 1) dir = (dir+3) %4;	//顺时针
	if(turn == 2) dir = (dir+1) %4;	//逆时针
	return Node(u.r+dr[dir],u.c+dc[dir],dir);
}

int main(){
	while(read_case()){
		sovle();
	}
	return 0;
}