//UVa140 
//Bandwidth 带宽
//DinnerHunt
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 10;
int id[256],little[MAXN];
int main(){
	char input[100];
	while(scanf("%s",input)==1&&input[0]!='#'){
		int n=0;
		for(char ch = 'A';ch<='Z';ch++)
			if(strchr(input,ch)!=NULL){
				id[ch] = n++;
				little[id[ch]] = ch;
			}
		int len = strlen(input),k=0,d;
		vector<int> a,b;
		for(int i=0;i<len;i++){
			if(input[i]==':') d=id[input[i-1]],k=1;
			else if(input[i]==';') k=0;
			else if(k) {
				a.push_back(d);
				b.push_back(id[input[i]]);
			}
		}
		int p[MAXN],bestp[MAXN],pos[MAXN],ans=n;
		for(int i=0;i<n;i++) p[i]=i;
		do{
			for(int i=0;i<n;i++) pos[p[i]] = i;
			int md=0;
			for(int i=0;i<a.size();i++)
			md = max(md,abs(pos[a[i]]-pos[b[i]]));
			if(md<ans){
				ans = md;
				memcpy(bestp,p,sizeof(p));
			}
		}while(next_permutation(p,p+n));
		for(int i =0;i<n;i++) printf("%c ",little[bestp[i]]);
		printf("-> %d\n",ans);
	}
	return 0;
}