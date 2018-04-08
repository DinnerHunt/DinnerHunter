//luogu P1085
//DinnerHunt
#include<iostream>
using namespace std;
int main(){
    int i,t[8],x,y;                                     
    for(i=1;i<=7;i++)                              
    {
            cin >> x >> y;                     
            t[i]=a+b;                                          
        }
        int b=0;                                         
        for(i=1;i<=7;i++)                                 
        	if(t[i]>8){
       			b=i;
       			break;
        	}
        cout << b;                                      
        return 0;
}
···