// 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int maxd = 10000;
struct student{
	int id,sex,year,month,day,age,flag;
	char name[100];
	char address[100];
	char email[100];
	double math,chinese,english;
	long phone;  
}e[maxd],now;
int ash[100000],eid;
int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
void strucpy(int x){
	e[x].id = now.id;
	e[x].sex = now.sex;
	e[x].year = now.year;
	e[x].month = now.month;
	e[x].day = now.day;
	e[x].phone = now.phone;
	e[x].math = now.math;
	e[x].chinese = now.chinese;
	e[x].english = now.english;
	e[x].age = now.age;
	e[x].flag = 1;
	strncpy(e[x].name,now.name,100);
	strncpy(e[x].address,now.address,100);
	strncpy(e[x].email,now.email,100);
}
void insert(){
	strucpy(eid);
	eid++;
}
void home();
int check(char *a,char *b){
	int len1 = strlen(a);
	int len2 = strlen(b);
	int i;
	if(len2 != len1) return 0;
	for(i=0;i<len1;i++)
		if(a[i]!=b[i]) return 0;
	return 1;
}
void hs1(){
	int flag=1;
	char ch;
	printf("	请输入学生的学号 (5位数以内) :");
	while(flag){
		scanf("%d",&now.id);
		if(now.id == -1){
			printf("	录入信息失败！\n");
			printf("	按任意键返回主页");
			ch = getchar();
			ch = getchar();
			home();
		}
		else if(now.id>=100000){
			printf("	!!!!学号数量超过5位!!!!\n");
			printf("	请重新输入 (输入-1 返回主页 ) :");
		}
		else if(ash[now.id]){
			printf("	!!!!学号已存在!!!!\n");
			printf("	请重新输入学号 (输入-1 返回主页) :");
		}
		else
		{
			printf("	学号输入成功！\n\n");
			ash[now.id] = 1;
			flag=0;
		}
	}
	printf("	请输入学生的姓名 : ");
	scanf("%s",now.name);
	flag = 1;
	printf("	请输入学生的年龄  : ");
	while(flag){
			scanf("%d",&now.age);
			if(now.age == -1){
				printf("	录入信息失败！\n");
				printf("	按任意键返回主页 ");
							ch = getchar();
			ch = getchar();
				home();
			}
			else if(now.age>100||now.age<0){
				printf("	!!!!年龄不合法!!!!\n");
				printf("	请重新输入年龄 (输入-1停止录入) :");
			}
			else
			{
				printf("	年龄输入成功！\n\n");
				flag=0;
			}
	}
	printf("	请输入学生的性别 (1.男  2.女) : ");
	flag = 1;
	while(flag)
	{
		scanf("%d",&now.sex);
			if(now.sex == -1){
				printf("	录入信息失败！\n");
				printf("	按任意键返回主页 ");
						ch = getchar();
						ch = getchar();
				home();
			}
			else if(now.sex!=1&&now.sex!=2){
				printf("	!!!!输入信息不合法!!!!\n");
				printf("	请重新输入性别 (输入-1停止录入) :");
			}
			else
			{
				printf("	性别输入成功！\n\n");
				flag=0;
			}
	}
	printf("	请输入学生的出生年月 (例 2000.1.1) : ");
	flag = 1;
	while(flag)
	{
		scanf("%d.%d.%d",&now.year,&now.month,&now.day);
			if(now.year==-1||now.month==-1||now.day==-1){
				printf("	录入信息失败！\n");
				printf("	按任意键返回主页 ");
							ch = getchar();
			ch = getchar();
				home();
			}
			else if(now.month <=0||now.month>12||now.day<=0||now.day>arr[now.month]){
				printf("	!!!!输入信息不合法!!!!\n");
				printf("	请重新输入日期 (输入-1停止录入) :");
			}
			else
			{
				printf("	日期输入成功！\n\n");
				flag=0;
			}
	}
	printf("	请输入学生的家庭地址 : ");
	scanf("%s",now.address);
	printf("	请输入学生的电话 : ");
	scanf("%ld",&now.phone);
	printf("	请输入学生的email : ");
	scanf("%s",now.email);
	printf("	请输入学生的成绩 (语文,数学,英语 例 76,75,74) :");
	flag = 1;
	while(flag)
	{
		scanf("%lf,%lf,%lf",&now.chinese,&now.math,&now.english);
			if(now.chinese==-1||now.math==-1||now.english==-1){
				printf("	录入信息失败！\n");
				printf("	按任意键返回主页 ");
							ch = getchar();
			ch = getchar();
				home();
			}
			else if(now.chinese<0||now.chinese>100||now.math<0||now.math>100||now.english<0||now.english>100){
				printf("	!!!!输入信息不合法!!!!\n");
				printf("	请重新输入成绩 (输入-1停止录入) :");
			}
			else
			{
				printf("	成绩输入成功！\n\n");
				flag=0;
			}
	}
	insert();
	printf("	信息录入成功!!!\n	");
	printf("	该学生信息为:\n");
	printf("	-------------------------------------------------------------------------\n"); 
	printf("	学号 	姓名 		性别 	年龄 		生日 			地址 			邮箱\n");
	printf("	%.2d	%.5s		",now.id,now.name);
	if(now.sex == 1)
	printf("男");
	else printf("女");
	printf("	%.2d	\t%.4d.%.2d.%2d 		%.15s		%.10sqq.com\n",now.age,now.year,now.month,now.day,now.address,now.email);
		printf("	按任意键返回\n 		");
	ch = getchar();
	ch = getchar();
	home();
}
void hs2(){
	char ch;
	int i;
	printf("\n");
	printf("	学号 	姓名 		性别 	年龄 		生日 			地址 			邮箱\n");
	for(i=0;i<eid;i++)
		if(e[i].flag == 1)
		{ 	
			printf("	%.2d	%.5s		",e[i].id,e[i].name);
			if(e[i].sex == 1)
			printf("男");
			else printf("女");
			printf("	%.2d	\t%.4d.%.2d.%2d 		%.15s		%.10sqq.com\n",e[i].age,e[i].year,e[i].month,e[i].day,e[i].address,e[i].email);
		}
	printf("	按任意键返回\n 		");
	ch = getchar();
	ch = getchar();
	home();
}
void hs3(){
	char str[100];
	int i,flag=0;
	int number;
	printf("	请输入需要查询的类别 (1.学号 2.性别) :");
	scanf("%d",&number);
	if(number !=1&&number!=2){
		printf("	请输入正确的查询类别!!\n");
		printf("	按任意键返回主页");
		str[0] = getchar();
		str[0] = getchar();
		home();
	}

	else if(number == 1)
	{
		printf("	请输入需要查询的学号 :");
		scanf("%d",&number);
		for(i=0;i<eid;i++)
			if(e[i].id == number)
			{
				printf("	姓名: %s\n",e[i].name);
				printf("	学号: %d\n",e[i].id);
				printf("	年龄: %d\n",e[i].age);
				printf("	地址: %s\n",e[i].address);
				printf("	邮箱: %s\n",e[i].email);
				printf("	电话: %lld\n",e[i].phone);
				printf("	成绩: 语文.%.5lf, 数学.%.5lf, 英语.%.5lf\n",e[i].chinese,e[i].math,e[i].english);
				printf("	出生日期: %d.%d.%d\n",e[i].year,e[i].month,e[i].day);
				flag=1;
				break;
			}
	}
	else{
		printf("	请输入需要查询的名字 :");
		scanf("%s",str);
		for(i=0;i<eid;i++)
			if(check(str,e[i].name))
			{
				printf("	姓名: %s\n",e[i].name);
				printf("	学号: %d\n",e[i].id);
				printf("	年龄: %d\n",e[i].age);
				printf("	地址: %s\n",e[i].address);
				printf("	邮箱: %s\n",e[i].email);
				printf("	电话: %lld\n",e[i].phone);
				printf("	成绩: 语文.%lf, 数学.%lf, 英语.%lf\n",e[i].chinese,e[i].math,e[i].english);
				printf("	出生日期: %d.%d.%d\n",e[i].year,e[i].month,e[i].day);
				flag=1;
				break;
			}
	}
	if(!flag) 
		printf("	未查询到相关信息\n"); 
	printf("	按任意键返回\n 		");
	str[0] = getchar();
	str[0] = getchar();
	home();
}
void hs4(){
	int number,flag =0;
	char ch;
	printf("	请输入需要删除的学号:");
	scanf("%d",&number);
	for(int i=0;i<eid;i++)
		if(e[i].id == number){
			flag =1;
			e[i].flag = 0;
			ash[number] = 0;
		}
	if(!flag) printf("	学号不存在!\n");
	printf("	按任意键返回\n 		");
	ch = getchar();
	ch = getchar();
	home();
}
void hs5(){
	int flag=1,id,number;
	char ch;
	printf("	请输入需要修改信息的学号：");
	scanf("%d",&id);
	for(int i=0;i<eid;i++)
		if(e[i].id == id)
		{
			flag = 0;
			id = i;
			break;
		}
	if(flag)
	{
		printf("	学号不存在");
		printf("	按任意键返回主页");
		ch = getchar();
		ch = getchar();
		home();
	}
	printf("	请输入需要修改的信息选项 \n");
	printf("	(1.学号 2.姓名 3.年龄 4.性别 5.生日 6.地址 7.电话 8.邮箱 9.成绩) :");
	scanf("%d",&number);
	switch(number){
		case 1:
			printf("	请输入新学生的学号 (5位数以内) :");
			while(flag){
				scanf("%d",&now.id);
				if(now.id == -1){
					printf("	修改信息失败！\n");
					printf("	按任意键返回主页");
					ch = getchar();
					ch = getchar();
					home();
				}
				else if(now.id>=100000){
					printf("	!!!!学号数量超过5位!!!!\n");
					printf("	请重新输入 (输入-1 返回主页 ) :");
				}
				else if(ash[now.id]){
					printf("	!!!!学号已存在!!!!\n");
					printf("	请重新输入学号 (输入-1 返回主页) :");
				}
				else
				{
					printf("	学号修改成功！\n\n");
					e[id].id = now.id;
					ash[e[id].id] = 1;
					flag=0;
				}
			}
		break;

		case 2:
			printf("	请输入学生的姓名 : ");
			scanf("%s",e[id].name);
			printf("	姓名修改成功！\n\n");
		break;
		case 3:
		printf("	请输入学生的年龄 : ");
		flag = 1;
		while(flag){
				scanf("%d",&now.age);
				if(now.age == -1){
					printf("	修改信息失败！\n");
					printf("	按任意键返回主页 ");
					home();
				}
				else if(now.age>100||now.age<0){
					printf("	!!!!年龄不合法!!!!\n");
					printf("	请重新输入年龄 (输入-1停止录入) :");
				}
				else
				{
					printf("	年龄修改成功！\n\n");
					e[id].age = now.age;
					flag=0;
				}
		}
		break;
		case 4:
		printf("	请输入学生的性别 (1.男  2.女) : ");
		flag = 1;
		while(flag)
		{
			scanf("%d",&now.sex);
				if(now.sex == -1){
					printf("	修改信息失败！\n");
					printf("	按任意键返回主页 ");
					home();
				}
				else if(now.sex!=1&&now.sex!=2){
					printf("	!!!!输入信息不合法!!!!\n");
					printf("	请重新输入性别 (输入-1停止录入) :");
				}
				else
				{
					printf("	性别修改成功！\n\n");
					e[id].sex = now.sex;
					flag=0;
				}
		}
		break;

		case 5:
		printf("	请输入学生的出生年月 (例 2000.1.1) : ");
		flag = 1;
		while(flag)
		{
			scanf("%d.%d.%d",&now.year,&now.month,&now.day);
				if(now.year==-1||now.month==-1||now.day==-1){
					printf("	修改信息失败！\n");
					printf("	按任意键返回主页 ");
					home();
				}
				else if(now.month <=0||now.month>12||now.day<=0||now.day>arr[now.month]){
					printf("	!!!!输入信息不合法!!!!\n");
					printf("	请重新输入日期 (输入-1停止录入) :");
				}
				else
				{
					printf("	日期修改成功！\n\n");
					e[id].year = now.year;
					e[id].month = now.month;
					e[id].day = now.day;
					flag=0;
				}
		}
		break;

		case 6:
		printf("	请输入学生的家庭地址 : ");
		scanf("%s",e[id].address);
		printf("	地址修改成功！\n\n");
		break;

		case 7:
		printf("	请输入学生的电话 : ");
		scanf("%lld",&now.phone);
		printf("	电话修改成功！\n\n");
		break;

		case 8:
		printf("	请输入学生的email : ");
		scanf("%s",now.email);
		printf("	email修改成功! \n\n");
		break;

		case 9:
		printf("	请输入学生的成绩 (语文,数学,英语 例 76,75,74) :");
		flag = 1;
		while(flag)
		{
			scanf("%lf,%lf,%lf",&now.chinese,&now.math,&now.english);
				if(now.chinese==-1||now.math==-1||now.english==-1){
					printf("	修改信息失败！\n");
					printf("	按任意键返回主页 ");
					home();
				}
				else if(now.chinese<0||now.chinese>100||now.math<0||now.math>100||now.english<0||now.english>100){
					printf("	!!!!输入信息不合法!!!!\n");
					printf("	请重新输入成绩 (输入-1停止录入) :");
				}
				else
				{
					printf("	成绩输入成功！\n\n");
					e[id].chinese = now.chinese;
					e[id].math = now.math;
					e[id].english = now.english;
					flag=0;
				}
		}
		break;
		default:
				printf("  请输入正确的编号!!!!\n");
				printf("  按回车继续！");  
				ch = getchar();
				ch = getchar();
				home();
		break;
	}
	printf("	信息录入成功!!!\n	");
	printf("	按任意键返回\n 		");
	ch = getchar();
	ch = getchar();
	home();
}
void print(){
	freopen("student.txt","w",stdout);
	int i=0;
	char ch;
	printf("	学号 	姓名 		性别 	年龄 		生日 			地址 			邮箱 		成绩\n");
	for(i =0;i<100000;i++)
		if(ash[i])
			for(int j=0;j<eid;j++)
				if (e[j].id == i){
					printf("	%.2d	%.5s		",e[j].id,e[j].name);
	if(e[j].sex == 1)
	printf("男");
	else printf("女");
	printf("	%.2d		%.4d.%.2d.%2d 		%.10s			%.10s 	%.5lf,%.5lf,%.5lf\n",e[j].age,e[j].year,e[j].month,e[j].day,e[j].address,e[j].email);
				}

}
void home(){
		system("cls");
		printf("     	**********************************     \n");
		printf("     	*	  学生信息管理系统       *		\n");
		printf("     	*   ==========================   *		\n");
		printf("     	*   1. 录入学生信息              *		\n");
		printf("     	*   2. 浏览学生信息              *		\n");
		printf("     	*   3. 查询学生信息              *     \n"); 
		printf("     	*   4. 删除学生信息              *     \n"); 
		printf("     	*   5. 修改学生信息              *     \n"); 
		printf("     	*   0. 退出系统                  *     \n");
		printf("     	**********************************     \n");
		printf("     	请选择你需要的操作:  ");
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
			case 0:
				printf("	按任意键退出系统 \n");
				print();
				ch = getchar();
				return;
			default:
				printf("	请输入正确的编号!!!!\n");
				printf("	按回车继续！");  
				ch = getchar();
				home();
				break;
		}
}
int main(int argc, char* argv[])
{
	home(); 
	return 0;
}



