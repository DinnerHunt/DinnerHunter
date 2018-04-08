#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int chinese,math,english,id,sum;
	bool operator <(const node &a){
		if(sum == a.sum){
			if(chinese==a.chinese)
				return id< a.id;
			return chinese > a.chinese;
		}
		return sum > a.sum;
	}
}arr[310];

int main(){
	int number,a,b,c;
	cin >> number;
	for(int i=1;i<=number;i++)
	{
		cin >> arr[i].chinese >> arr[i].math >> arr[i].english;
		arr[i].sum=arr[i].chinese+arr[i].math+arr[i].english;
		arr[i].id=i;
	}
	sort(arr+1,arr+1+number);
	for(int i=1;i<=5;i++)
	{
		cout << arr[i].id << " " << arr[i].sum <<endl;
	}
	return 0;
}