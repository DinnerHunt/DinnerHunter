#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
int arr1[5],arr2[5];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       	scanf("%dday%d:%d:%d",&arr1[1],&arr1[2],&arr1[3],&arr1[4]);
        scanf("%dday%d:%d:%d",&arr2[1],&arr2[2],&arr2[3],&arr2[4]);
        LL ans =0;
        if(arr2[4]<arr1[4])  arr2[4]+=60,arr2[3]--;
        ans+=arr2[4]-arr1[4];
        if(arr2[3]<arr2[3])  arr2[3]+=60,arr2[3]--;
        ans+=60*(arr2[3]-arr1[3]);
        if(arr2[2]<arr2[2])  arr2[2]+=24,arr2[1]--;
        ans+=60*60*(arr2[2]-arr1[2]);
        ans+=24*60*60*(arr2[1]-arr1[1]);
        printf("%lld\n",ans);
    }

    return 0;
}