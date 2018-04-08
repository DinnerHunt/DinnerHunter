//P1603 luogu
//DinnerHunt
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
string o;
string pw[7];
bool mmp(string x,string y){
    return x<y;
}
int main(){
    for(int i=0;i<=6;i++){
        cin>>o;
        if(o=="one" or o=="One")pw[i]="01";
        else if(o=="two" or o=="Two")pw[i]="04";
        else if(o=="three" or o=="Three")pw[i]="09";
        else if(o=="four" or o=="Four")pw[i]="16";
        else if(o=="five" or o=="Five")pw[i]="25";
        else if(o=="six" or o=="Six")pw[i]="36";
        else if(o=="seven" or o=="Seven")pw[i]="49";
        else if(o=="eight" or o=="Eight")pw[i]="64";
        else if(o=="nine" or o=="Nine")pw[i]="81";
        else if(o=="ten" or o=="Ten")pw[i]="00";
        else if(o=="eleven" or o=="Eleven")pw[i]="21";
        else if(o=="twelve" or o=="twelve")pw[i]="44";
        else if(o=="thirteen" or o=="Thirteen")pw[i]="69";
        else if(o=="fourteen" or o=="Fourteen")pw[i]="96";
        else if(o=="fifteen" or o=="Fifteen")pw[i]="25";
        else if(o=="sixteen" or o=="Sixteen")pw[i]="56";
        else if(o=="seventeen" or o=="Seventeen")pw[i]="89";
        else if(o=="eighteen" or o=="Eighteen")pw[i]="24";
        else if(o=="nineteen" or o=="Nineteen")pw[i]="61";
        else if(o=="twenty" or o=="Twenty")pw[i]="00";
        else if(o=="a" or o=="A")pw[i]="01";
        else if(o=="both" or o=="Both")pw[i]="04";
        else if(o=="another" or o=="Another")pw[i]="01";
        else if(o=="first" or o=="First")pw[i]="01";
        else if(o=="second" or o=="Second")pw[i]="04";
        else if(o=="third" or o=="Third")pw[i]="09";
        else pw[i]="00";
        o="0";
    }
    sort(pw,pw+7,mmp);
    for(int i=0;i<=6;i++){
        if(pw[i]=="00" and a==0)continue;
    else if(pw[i]=="01" and a==0){
            cout<<1;a++;
        }
    else if(pw[i]=="04" and a==0){
            cout<<4;a++;
        }
    else if(pw[i]=="09" and a==0){
            cout<<9;a++;
        }
    else {
        cout<<pw[i];a++;}
    }
    if(a==0)cout<<0;
    return 0;
}