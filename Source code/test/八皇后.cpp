int n;
int ans = 0;
bool a[20]; //列占用情况
bool x1[20]; //左下-右上 占用情况
bool y1[20]; //左上-右下占用情况

void dfs(int deep){
	if(deep >= n){
		ans++;
		return;
	}
	for(int i=0;i<n;i++){//枚举当前行的所有列情况
		if(!x1[i+deep]&&!y1[i-deep+n]&&!a[i]){
			x1[deep+i] = true;
			y1[i-deep+n] = true;
			a[i] = true;
			dfs(deep+1);
			a[i] = false;
			y1[i-deep+n] = false;
			x1[deep+i] = false;
		}
	}
}

int main(){
	scanf("%d",&n);
	memset(a,false,sizeof(a));
	memset(x1,false,sizeof(x1));
	memset(y1,false,sizeof(y2));
	dfs(0);
	printf("%d",ans);
	return 0;
}