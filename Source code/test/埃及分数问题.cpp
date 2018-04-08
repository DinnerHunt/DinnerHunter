// 埃及分数问题
// 迭代加深搜索
// 在无法确定深度或没有明显上限的情况下使用
// 从小到大遍地深度maxn值
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long LL;
int a,b,maxd;
LL v[maxn],ans[maxn];


LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
const int maxn = 100+5;
inline int get_first(LL a,LL b){//返回满足1/c <= a/b的最小c
	return b/a+1;	
}
bool batter(int d){				//如果当且解更优，则替换ans
	for(int i=d;i>=0;i--) if(v[i] != ans[i]){
		return ans[i] == -1 || v[i] < ans[i];
	}
	return false;
}
//当前深度d 分母不能小于from,分数之和正好为aa/bb
bool dfs(int d,int from,LL aa, LL bb){
	if(d == maxd){
		if(bb%aa) return false;	//如果最后一个不是1/bb 则为错误答案
		v[d] = bb/aa;
		if(better(d)) memcpy(ans,v,sizeof(LL) *(d+1)); 
		return true;
	}
	bool ok = false;
	from = max(from,get_first(aa,bb));
	for(int i=from;;i++){
		//剪枝 如果剩下的部分全是1/i,加起来仍然不超过aa/bb 则无解
		if(bb * (maxd+1-d) <= i*aa) break;
		v[d] = i;
		LL b2 = bb*i;
		LL a2 = aa*i - bb;
		LL g = gcd(a2,b2);
		if(dfs(d+1,i+1,a2/g,b2/g)) ok = true;
	}
	return ok;
}


int main(){
	int kase = 0;
	while(cin >> a >> b){
		int ok = 0;
		for( maxd=0;maxd <= 100;maxd++){
			memset(ans,-1,sizeof(ans));
			if(dfs(0,get_first(a,b),a,b)) {ok =1;break;}
		}
		printf("Case %d: ",++kase);
		if(ok){
			printf("%d/%d=",a,b);
			for(int i=0;i<maxd;i++) printf("1/%d+",ans[i]); 
			printf("1/%d\n",ans[maxd]);
		}
		else 
			printf("No solution.\n");
	}
	return 0;
}