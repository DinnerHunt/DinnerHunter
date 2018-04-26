#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct kkkk{
	char name[500];
	char password[500]; 
}user[500];
struct node{
	int id;
	int leixing;
	char str[100];
}arr[500];
struct jilu{
	int id;
	int money;
	int year,moth,day;
	char str[100];
}table[500];
int len,size,user_number;
int riqi[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
int check(char *x,char*y){
	if(strlen(x)!=strlen(y)) return 0;
	int i;
	for( i =0;i<strlen(x);i++)
		if(x[i]!=y[i])
			return 0;
	return 1;
}
void hs1(){
	int a;
	char str[100];
	if(len<40){				// ！！！！！！！！！！分类上限 
		len++;
		printf("  请输入改分类的种类: (1 - 收入    2-  支出):   ");
		scanf("%d",&a);
		printf("  请输入分类名称:   "); 
		scanf("%s",str);
		arr[len].leixing = a;
		arr[len].id=len;
		strncpy(arr[len].str,str,100);
		if(a==1)
		printf("  添加一种新的收入类型，编号：%d , 分类名称：%s\n",len,str);	
		else 
		printf("  添加一种新的支出类型，编号：%d , 分类名称：%s\n",len,str);
	}
	else  printf("  分类数量已达上限，无法添加！\n");
	printf("  按回车继续！");
	char ch; 
	ch = getchar();
	ch = getchar();
	home(); 
}
void hs2(){
	int id,a;
	char str[100];
	printf("  请输入需要修改分类的编号:  ");
	scanf("%d",&id);
	if(id<=0||id>len) printf("您输入的分类编号不存在，不能操作!\n");
	else {
		printf("  请输入改分类的种类: (1 - 收入    2-  支出):   ");
		scanf("%d",&a);
		printf("  请输入分类的新名称:   "); 
		scanf("%s",str);
		arr[id].leixing = a;
		strncpy(arr[id].str,str,100);
		if(a==1)
			printf("  编号为%d的分类 %s 完成修改,目前属于收入类型\n",id,str);
		else 
			printf("  编号为%d的分类 %s 完成修改,目前属于支出类型\n",id,str);
	} 
	printf("  按回车继续！");
	char ch; 
	ch = getchar();
	ch = getchar();
	home(); 
}
void hs3(){
	printf("分类编号          分类名称          所属种类\n");
	int i;
	for(i=1;i<=len;i++){
	printf("   %2d          	   %10s         ",arr[i].id,arr[i].str);
	if(arr[i].leixing == 1) printf("收入\n");
	else printf("支出\n");
	}
	printf("  按回车继续！");
	char ch; 
	ch = getchar();
	ch = getchar();
	home();
}
void hs4(){
	char str[100];
	int money,id;
	printf("  请输入分类的编号:  ");
	scanf("%d",&id);
	if(id<=0||id>len) printf("  您输入的分类编号不存在，不能操作!\n");
	else{
		size++;
		printf("  输入本次转账记录的描述 : ");
		scanf("%s",str);
		printf("  输入本次转账记录的金额 : ");
		scanf("%d",&money);
		table[size].money=money;
		table[size].day =26;
		table[size].year =2018;
		table[size].moth =4;
		table[size].id = id;
		strncpy(table[size].str,str,100);
		printf("  该次记录已经完成!\n"); 
		
	}
	printf("  按回车继续！");
	char ch; 
	ch = getchar();
	ch = getchar();
	home();
}
void hs5(){
	char ch,str[100];
	int number,id,year,moth,day,money;
	printf("  请输入记录编号: ");
	scanf("%d",&id);
	ch = getchar();
	if(id>0&&id<=size)
	{
		printf("  是否需要修改转账记录的分类 : (y/n)  ");
		scanf("%c",&ch);
		if(ch == 'y')
		{
			printf("  请输入本次记账记录的分类编号 :   ");
			scanf("%d",&number);
			if(number<=0&&number>len){
				printf("  您输入的分类编号不存在，本次操作不计入系统!\n");
				home();
			}
			ch = getchar();
		}
		printf("  是否需要修改转账记录的描述 : (y/n)  ");
		scanf("%c",&ch);
		if(ch == 'y')
		{
			printf("  请输入本次记账记录的描述 :  ");
			scanf("%s",str);
			ch = getchar();
		}
		
		printf("  是否需要修改转账记录的金额 : (y/n)  ");
		scanf("%c",&ch);
		if(ch == 'y')
		{
			printf("  请输入本次记账记录的金额 :   ");
			scanf("%d",&money);
			ch = getchar();
		}
		
		printf("  是否需要修改转账记录的时间 : (y/n)  ");
		scanf("%c",&ch);
		if(ch == 'y')
		{
			printf("  请输入本次记账记录的年份 :   ");
			scanf("%d",&year);
			table[id].year = year;
			ch = getchar();
			printf("  请输入本次记账记录的年份 :   ");
			scanf("%d",&moth);
			if( moth <=0||moth> 12) {
				printf("  您输入的月份不存在，本次操作不计入系统!\n");
				home();
			}
			ch = getchar();
			printf("  请输入本次记账记录的年份 :   ");
			scanf("%d",&day);
			
			if(day <=0 || day> riqi[moth] ){
				printf("  您输入的日期不存在，本次操作不计入系统!\n");
				home();
			}
				ch = getchar();
		}
		
		table[id].id = number;
		strncpy(table[id].str,str,100);
		table[id].money = money;
		table[id].moth = moth;
		table[id].day = day;
		printf("本次记录修改完成！");
	}
	else printf("  您输入的记录编号不存在，不能操作!\n");
	printf("  按回车继续！"); 
	ch = getchar();
	ch = getchar();
	home();
}
void hs6(){
	int id;
	printf("  请输入记录编号: ");
	scanf("%d",&id);
	if(id<=0||id>size) printf("您输入的记账编号不存在，不能操作!\n");
	else {
		int i;
		for(i=id;i<size;i++)
		{
			table[i].day = table[i+1].day;
			table[i].id = table[i+1].id;
			table[i].moth = table[i+1].moth;
			table[i].year = table[i+1].year;
			table[i].money = table[i+1].money;
			strncpy(table[i].str,table[i+1].str,100);
		}
		printf("记录删除成功!!\n");
		size--;
	}
	printf("  按回车继续！"); 
	char ch;
	ch = getchar();
	ch = getchar();
	home();
}
void hs7(){
	
	printf("记录编号          分类名称          金额          记录时间          详情\n");
	int i;
	for(i=1;i<=size;i++)
	{
		printf(" %2d           %10s            %5d          %4d.%2d.%2d          %s\n",i,arr[table[i].id].str,arr[table[i].id].leixing==1?table[i].money:-table[i].money,table[i].year,table[i].moth,table[i].day,table[i].str);
	}
	printf("  按回车继续！"); 
	char ch;
	ch = getchar();
	ch = getchar();
	home();
}
void hs8(){
	int moth;
	char ch;
	printf("  请输入你需要了解的月份:  ");
	scanf("%d",&moth);
	if(moth<=0||moth>12)printf("  您输入的月份不存在，不能操作!\n");
	else{
		int i,j,sum,mun=0;
		printf("类型名称		金额\n");
		for(i=1;i<=len;i++){
			printf("%s            ",arr[i].str);
			sum=0;
			for(j=1;j<=size;j++)
				if(table[j].id==i&&table[j].moth==moth)
					sum+=table[j].money;
			if(arr[i].leixing==1){
				mun+=sum;
				printf("%d\n",sum);
			}
			else
			{
				mun-=sum;
				printf("%d\n",-sum);
			}
		}
		printf("%d月的收支结果为:%d\n  ",moth,mun);
	}
	printf("  按回车继续！"); 
	ch = getchar();
	ch = getchar();
}
void home(){
		system("cls");
		printf("     **********************************     \n");
		printf("     *	  欢迎使用家用记账管理系统    *		\n");
		printf("     *   ==========================   *		\n");
		printf("     *   1. 添加记账分类              *		\n");
		printf("     *   2. 修改记账分类              *		\n");
		printf("     *   3. 显示全部记账分类          *     \n"); 
		printf("     *   4. 添加记账记录              *     \n"); 
		printf("     *   5. 修改记账记录              *     \n"); 
		printf("     *   6. 删除记账记录              *     \n"); 
		printf("     *   7. 显示记账记录              *     \n");
		printf("     *   8. 显示月度开销数据报表      *     \n");
		printf("     *   9. 注销                      *     \n");
		printf("     **********************************     \n");
		printf("  请选择你需要的操作:  ");
		int k; 
		char ch;
		scanf("%d",&k);
		ch = getchar();
		switch(k){
			case 1:
				hs1();
				break;
			case 2:
				hs2();
				break;
			case 3:
				hs3();
				break;
			case 4:
				hs4();
				break;
			case 5:
				hs5();
				break;
			case 6:
				hs6();
				break;
			case 7:
				hs7();
				break;
			case 8:
				hs8();
				break;
				
			case 9:
				printf("  按回车注销 \n");
				ch = getchar();
				return;
			default:
				printf("  请输入正确的编号!!!!\n");
				printf("  按回车继续！");  
				ch = getchar();
				home();
				break;
		}
}
void d1(){
	 char str1[100],str2[100],ch;
	 printf("  请输入账号:  ");
	 scanf("%s",str1);
	 ch = getchar();
	 printf("  请输入密码:  "); 
	 scanf("%s",str2);
	 int i;
	 for(i=1;i<=user_number;i++)
	 	if(check(user[i].name,str1)){
	 		if(check(user[i].password,str2))
	 		{
				printf("  尊敬的%s！,欢迎您！\n",user[i].name);	 
				printf("  按回车返回进入系统主页 ");
				
				//printf("  \n\n\n\n\n测试功能结束!!!\n");
				//printf("  按回车返回登入主页 ");
				ch = getchar();
				ch = getchar();
				//login();
				home();
				login();
			}
			else
			{
				printf(" 密码错误！！！ \n");
				printf("  按回车返回登入界面 ");
				ch = getchar();
				ch = getchar();
				login(); 
			}
		}
	printf("  用户不存在!!!!\n");
	printf("  按回车返回登入界面 ");
	ch = getchar();
	ch = getchar();
	login(); 		
}
void d2(){
	char str1[100],str2[100],str3[100],ch;
	printf("  请输入注册账户名:   ");
	scanf("%s",str1);
	int i;
	for(i=1;i<=user_number;i++)
		if(check(user[i].name,str1))
		{
			printf(" 用户名重复!!!!\n");
			printf(" 按回车返回登入界面 ");
			ch = getchar();
			ch = getchar();
			login(); 	
		}
	ch = getchar();
	printf("  用户名合法！！！\n"); 
	printf("  请输入密码:   ");
	scanf("%s",str2);
	ch = getchar();
	printf("  请再输入密码:   "); 
	scanf("%s",str3);
	ch = getchar();
	if(check(str3,str2)){
		printf("  用户注册成功！！！!\n");
		printf("  按回车返回登入界面 ");
		user_number++;
		strncpy(user[user_number].name,str1,100);
		strncpy(user[user_number].password,str2,100);
		ch = getchar();
		ch = getchar();
		login(); 
	}
	else{
		printf("  用户注册失败！！！！\n");
		printf("  两次密码不一样！！！!\n");
		printf("  按回车返回登入界面 ");
		ch = getchar();
		ch = getchar();
		login(); 
	} 
}
void login(){
	system("cls");
		printf("     **********************************     \n");
		printf("     *	  欢迎使用家用记账管理系统    *		\n");
		printf("     *	           登入界面           *		\n");
		printf("     *                                *     \n");
		printf("     *          1  账户登入           *     \n");
		printf("     *          2  用户注册           *     \n");
		printf("     *          3  退出               *     \n");
		printf("     **********************************     \n");
		printf("  请选择你需要的操作:  ");
		int k; 
		char ch;
		scanf("%d",&k);
		ch = getchar();	
		if(k==1)  d1();
		else if(k==2) d2();
		else {
			printf("  按回车退出系统 \n");
			ch = getchar();
			return;
		}
}  
int main(){
	login(); 
	return 0;
}

