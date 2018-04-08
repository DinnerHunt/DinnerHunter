//string
#include <iostream>
using namespace std;
int n;
string a,b;
void gsh(string &a){
    int i=0,j;
    char ch;
    while(i<a.length()){
        if(a[i]=='*'){
            j=i;
            ch = a[i-1];
            while(a[j]=='*')j++;
            if(a[j]==ch){
                a[i] = ch;
                a.erase(j,1);  
            }
        }
        i++;
    }
}
void cmp(string &a,string &b){
	int i=0,j=0;
	while(i<a.length()||i<b.length()){
		if(a[i]==b[j]){i++;j++;}
		else if(a[i]=='*')
		{	
			char ch = b[j-1];
			while(b[j]==ch)j++;
			i++;
		}
		else{
			break;
		}
	}
	if(i==a.length()&&j==b.length())
		cout << "Yes" <<endl;
	else 
		cout << "No" << endl;
}
int main(){
	
	while(cin >> a >> b){
        gsh(a);
		cmp(a,b);
    }
	return 0;
}