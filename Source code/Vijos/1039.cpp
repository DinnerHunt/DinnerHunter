//Vjios 1039 最小差距
#include<bits/stdc++.h>
using namespace std;
int a[15];
int n;
int abs(int x){ return (x<0?-x:x); }
int work1(){
    if (a[1]==0) swap(a[1],a[2]);
    int s1=0,s2=0;
    for (int i=1;i<=n/2+1;i++) s1=s1*10+a[i];
    for (int i=n;i>=n/2+2;i--) s2=s2*10+a[i];
    return abs(s1-s2);
}
int work2(){
    int book[15];
    int s1,s2;
    int ans=(1<<31)-1;
    for (int i=2;i<=n;i++)
        if (a[i-1]){
            s1=a[i],s2=a[i-1];
            memset(book,0,sizeof(book));
            book[i]=book[i-1]=1;
            int l=1,r=n;
            for (int j=1;j<=(n-2)/2;j++){
                while (book[l]) l++;
                while (book[r]) r--;
                book[l]=book[r]=1;
                s1=s1*10+a[l];s2=s2*10+a[r];
            }
            ans=min(ans,abs(s1-s2));
      }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        if (n==2) { printf("%d\n",a[2]-a[1]);continue; }
        if (n%2==1) printf("%d\n",work1()); else printf("%d\n",work2());
    }
}