//Vijos 1911 珠心算
#include<iostream>
using namespace std;
int main()
{
    int a[20002],k[101],i,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        
        cin>>k[i];
        a[k[i]]=1;
    }
    int c=0;
    for(i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            a[k[i]+k[j]]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[k[i]]==0)c++;
    }
    cout<<c;
    return 0;
}