//P1177 luogu
//DinnerHunt
#include <iostream>
using namespace std;
int data[100010],temp[100010];
void quick_sort(int left,int right){
    if(left==right)
        return;
    int mid = (left+right)/2;
    quick_sort(left,mid);
    quick_sort(mid+1,right);
    int x=left,y=mid+1,loc=left;
    while(x<=mid||y<=right){
            if(x<=mid && (y>right||data[x]<=data[y])){
                temp[loc]=data[x];
                x++;
            }
            else{
                temp[loc]=data[y];
                y++;
            }
            loc++;
        }
        for(int i=left;i<=right;i++){
            data[i]=temp[i];
        }
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> data[i];
    quick_sort(0,n-1);
    for(int i=0;i<n;i++){
        if(i) cout << " ";
        cout << data[i];
    }
    return 0;
}