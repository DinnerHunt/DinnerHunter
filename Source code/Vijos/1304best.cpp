#include<iostream>  
#include<cstring>  
#include<cstdio>  
using namespace std;  
string x;  
int jz,n,a[10001],s=1;  
int pdhw(int n)                 //判断回文
{  
    for(int i=1;i<=n/2;i++)  
        if(a[i]!=a[n-i+1])  
            return 0;  
    return 1;  
}  
int jf(int n)                       //加法
{  
    int c[10001]={0},s=1;  
    for(int i=1;i<=n;i++)  
    {
        c[i]=a[i]+a[n-i+1]+c[i];       
        c[i+1]+=c[i]/jz;  
        c[i]%=jz;
    }
    if (c[n+1]!=0)  
        n++;  
    for(int i=n;i>=1;i--)  
    {  
        a[s]=c[i];  
        s++;  
    }  
    return n;  
}  
int main()  
{  
    cin>>jz>>x;  
    n=x.size();  
    for(int i=1;i<=n;i++)  
    {
        if(x[i-1]<65)           //如果是0-9则见0
            a[i]=x[i-1]-'0';  
        else                    //不然则返回16进制
            a[i]=x[i-1]-55;  
    }  
    while(s<=30)  
    {
        if(pdhw(n)==1)  
        {
            cout<<"STEP="<<s-1;
            return 0;  
        }
        s++;  
        n=jf(n);
    }
    cout<<"Impossible!";
}
