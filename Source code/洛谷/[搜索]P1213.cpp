//P1213 时钟
//DinnerHunt
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef pair<int,string>
int flag[350000];
inline int qy(int x,int y){
	return x-x/y*y;
}
int arr[9]{
	110110000,
	111000000,
	011011000,
	100100100,
	010111010,
	001001001,
	000110110,
	000000111,
	000011011
}
int check(int x){
	int y = 0;
	while(x){
		y=y*10+qy(qy(x,10),4);
		x/=10;
	}
	while(y){
		x=x*10+qy(x,10);
		y/=10;
	}
	return x;
}
int id(int x){
	int y=0;
	while(x){
		y=y*4+qy(x,10);
		x/=10;
	}
	return y;
}
int hex(int x){
	int y=0;
	while(x){
		y=y*10+qy(x,4);
		x/=4;
	}
	return y;
}
void bfs(int x){
	queue<P> q;
	q.push(P(x,""));
	while(!q.empty()){
		P p = que.front();
		que.pop();
		for(int i=0;i<9;i++)
		{
			int y = check(p.first+arr[i]);
			int z = id(y);
			if(y==111111111){
				int len = p.second.length();
				for(int i=0;i<len;i++)
					cout << str[i] << " ";
				printf("%c",'1'+i);
				return ;
			}
			if(!arr[y]){
				arr[y] = 1;
				que.push(P(y,p.second+('1'+i)));
			}
		}
	}
}
int main(){
	int k=0,l;
	for(int i=0;i<9;i++){
		scanf("%d",&l);
		k=k*10+l/4;
	}
	flag[id(k)]=1;
	bfs(k);
	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
int b[10000];
void out()
{
    for(int i=1;i<=9;i++)
    	if(b[i]>0)
    		for(int j=1;j<=b[i];j++)
    			cout<<i<<" ";
}
int main()
{
	int a[100];
    for(int i=1;i<=9;i++)
    {
    	cin>>a[i];
     	a[i]=a[i]/3;
    }
    for(int p1=0;p1<=3;p1++)
    	for(int p2=0;p2<=3;p2++)
    		for(int p3=0;p3<=3;p3++)
    			for(int p4=0;p4<=3;p4++)
    				for(int p5=0;p5<=3;p5++)
    					for(int p6=0;p6<=3;p6++)
    						for(int p7=0;p7<=3;p7++)
    							for(int p8=0;p8<=3;p8++)
    								for(int p9=0;p9<=3;p9++)
    									if((p1+p2+p4)%4==(4-a[1])%4&&(p1+p2+p3+p5)%4==(4-a[2])%4&&(p2+p3+p6)%4==(4-a[3])%4&&(p1+p4+p5+p7)%4==(4-a[4])%4&&
    (p1+p3+p5+p7+p9)%4==(4-a[5])%4&&(p3+p5+p6+p9)%4==(4-a[6])%4&&(p4+p7+p8)%4==(4-a[7])%4&&(p5+p7+p8+p9)%4==(4-a[8])%4&&
    (p6+p8+p9)%4==(4-a[9])%4)
    {										b[1]=p1;
										    b[2]=p2;
										    b[3]=p3;
										    b[4]=p4;
										    b[5]=p5;
										    b[6]=p6;
										    b[7]=p7;
										    b[8]=p8;
										    b[9]=p9;
    										out();
    }
}
*/