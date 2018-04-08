//P1051 luogu
//DinnerHunt
#include <bits/stdc++.h>
using namespace std;
struct node{
	string name;
	int score,grade,money=0;
	bool ganbu,baimao,lunwen;
	node(string name="",int score=0,int grade=0,bool ganbu=false,bool baimao=false, bool lunwen=false):
	name(name),score(score),grade(grade),ganbu(ganbu),baimao(baimao),lunwen(lunwen){}
    void getmoney(){
		if(score>80&&lunwen)
			money+=8000;
		if(score>85&&grade>80)
			money+=4000;
		if(score>90)
			money+=2000;
		if(score>85&&baimao)
			money+=1000;
		if(grade>80&&ganbu)
			money+=850;
	}
}arr[100];
	
int main(){
	int number,sum=0,max=0,id;
	cin >> number;
	for(int i=0;i<number;i++){
		cin >> arr[i].name >> arr[i].score>> arr[i].grade;
		char x,y;
		int a;
		cin >> x >> y >> a;
		if(x=='Y')
			arr[i].ganbu=true;
		if(y=='Y')
			arr[i].baimao=true;
		if(a>0)
			arr[i].lunwen=true;
		arr[i].getmoney();
		sum+=arr[i].money;
		if(arr[i].money>max){
			max = arr[i].money;
			id = i;
		}
	}
	cout <<arr[id].name << endl;
	cout << max << endl;
	cout << sum ;
	return 0;
}