// 1120 vijos
// DinnerHunt
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
    int x,y,num;
    bool operator < (const node &a)const{
        return num < a.num;
    }
};
priority_queue<node> que;

int main(){
    int width,length,time,n,env=0;
    cin >> length >> width >> time;
    for(int i=1;i<=length;i++)
        for(int j=1;j<=width;j++){
            cin >>n ;
            if(n){
                que.push((node){i,j,n});
            }
        }
    int x =0,y=0;
    while(que.size()){
        struct node nod = que.top();
        que.pop();
        if(x==0&&y==0){
            if(time-nod.x-nod.x>0)
            {
                time -= nod.x+1;
                env += nod.num;
                x=nod.x;y=nod.y;
            }
            else
                break;
        }
        else{
            if(time-abs(x-nod.x)-abs(y-nod.y)-nod.x>0)
            {
                time = time - abs(x-nod.x)-abs(y-nod.y)-1;
                env+=nod.num;
                x = nod.x;
                y = nod.y;
            }
            else
                break;
        }
    }
    cout << env;
    return 0;
}