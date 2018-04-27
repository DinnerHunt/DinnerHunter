#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxd = 100005;
int arr[maxd],len;
int find(int l,int r,int k){
    while(l<=r){
        int mid = (l+r) >> 1;
        if(arr[mid] < k) r = mid-1;
        else l=mid+1;
    }
    return l;
}
int main(){
	string str;
	cin >> str;
	arr[0] = str[0]-'a';
	for(int i=1;i<str.length();i++){
	    //printf("%c \n",arr[len]+'a');
		if(str[i]-'a'<= arr[len])
			arr[++len] = str[i]-'a';
		else
		{
			len = find(0,len,str[i]-'a');
			arr[len] = str[i] - 'a';
		}
	}
	for(int i=0;i<=len;i++)
		printf("%c",arr[i]+'a');
	return 0;
}