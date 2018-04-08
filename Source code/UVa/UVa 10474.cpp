//UVa 10474 大理石在哪里
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10000;			//最大数量
int main(){
	int x,y,z,cout=0,arr[maxn];		//x y 为个数和查询次数
	while(scanf("%d%d",&x,&y)!=EOF&&x){
		for(int i=0;i<x;i++) scanf("%d",&arr[i]);	//数组存储石头
		sort(arr,arr+x);				//排序
        printf("CASE# %d:\n",++cout);	//输出测试组数
		while(y--){
			scanf("%d",&z);			//查询的时候
			int p=lower_bound(arr,arr+x,z)-arr;		//查找大于或等于z的第一个数与第一个数的距离
			if(arr[p]==z) printf("%d found at %d\n",z,p+1);	//如果p与z相等，则说明找到了
			else printf("%d not found\n", z);
		}
	}
	return 0;
}
