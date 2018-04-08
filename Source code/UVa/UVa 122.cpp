//UVa 122 树的层次遍历 (Trees on the level)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 256+10;

struct node{
	bool have_value;
	int v;
	node *left,*right;
	node():have_value(false),left(NULL),right(NULL){}
};

char s[maxn];
node *root;
bool failed;

node* newnode(){ return new node(); }

void addnode(int v,char *s){
	int n = strlen(s);
	node *u=root;
	for(int i=0;i<n;i++)
		if(s[i]=='L'){
			if(u->left==NULL) u->left=newnode();
			u = u -> left;
		}
		else if(s[i]=='R'){
			if(u->right==NULL) u->right=newnode();
			u = u -> right;
		}
		if(u->have_value) failed=true;
		u->v=v;
		u->have_value=true;
}
void remove_node(node *u){
	if(u==NULL)return;
	remove_node(u->left);
	remove_node(u->right);
	delete u;
}
bool read_input(){
	failed = false;
	remove_node(root);
	root = newnode();
	for(;;){
		if(scanf("%s",s)!=1) return false;
		if(!strcmp(s,"()")) break;
		int v;
		sscanf(&s[1],"%d",&v);
		addnode(v,strchr(s,',')+1);
	}
	return true;
}
bool bfs(vector<int> &ans){
	queue<node*> q;
	ans.clear();
	q.push(root);
	while(!q.empty()){
		node *u = q.front();q.pop();
		if(!u->have_value) return false;
		ans.push_back(u->v);
		if(u->left!=NULL) q.push(u->left);
		if(u->right!=NULL) q.push(u->right);
	}
	return true;

}
int main(){    
	vector<int> ans;
	while(read_input()){
		if(!bfs(ans)) failed=true;
		if(failed) printf("not complete\n");
		else{
			for(int i=0;i<ans.size();i++){
				if(i)
					printf(" ");
				printf("%d",ans[i]);
			}
			printf("\n");
		}
	}                                                                       
	return 0;
}
