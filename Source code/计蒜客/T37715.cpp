//jisuanke 37715 两仪剑法
//DinnerHunt
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b)return gcd(b,a%b);
    else return a;
}
int main()
{
    ios::sync_with_stdio(false);
    int T,a,b;
    cin >> T;
    while(T--)
    {
        cin >> a >> b;
        cout << (long long int)a*b/gcd(a,b);
        if(T) cout << endl;
    }
}