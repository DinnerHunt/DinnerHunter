// test.cpp : Defines the entry point for the console application.
//

// 往下到 32  A
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int maxd = 1000;	
struct book{						//记录书籍信息
	char name[100];					//书籍姓名
	char writer[100];				//作者
	char publisher[100];			//发行商
	int id,money;					//书籍的编号与价格
}table[maxd];						//用数组记录所有信息
int size,right[maxd],tim;			//size书在table表中的位子，right数组模拟链表操作，方便删除记录， tim是用来统计有多少出借信息的
struct recode{
	int flag,grades,id;
	int year,month,day;
	char name[100];
}data[maxd];
int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
void home();
int check(char *a,char *b){			// 判断两个字符串是否相等
	int len1 = strlen(a);
	int len2 = strlen(b);
	if(len1 != len2 ) return 0;
	for(int i=0;i<len1;i++)
		if(a[i]!=b[i]) return 0;
	return 1;
}

// 往下到 105 B
void hs1(){
	char str[100];
	int number;
	printf("书籍的属性 - - - 名称 作者 发行商 编号 价格 \n");
	right[size] = size+1;
	size++;
	printf("请输入书籍名称: ");
	scanf("%s",str);
	strncpy(table[size].name,str,100);
	printf("请输入书籍的作者: ");
	scanf("%s",str);
	strncpy(table[size].writer,str,100);
	printf("请输入书籍的发行商: ");
	scanf("%s",str);
	strncpy(table[size].publisher,str,100);
	printf("请输入书籍的编号: ");
	scanf("%d",&number);
	table[size].id = number;
	printf("请输入书籍的价格: ");
	scanf("%d",&number);
	table[size].money = number;
	printf("第%d书籍添加成功！！！！\n",size);
	printf("按任意键返回!");
	str[0] = getchar();
	str[0] = getchar();
	home();
}
void hs2(){
	int number,id;
	char str[100];
	printf("请输入需要修改书籍的编号: ");
	scanf("%d",&id);
	int i;
	for(i=right[0];i;i=right[i])
		if(table[i].id == id)
			id = i;
	if(!id) { 
		printf("输入书籍编号不存在!!!!\n");
		printf("按任意键返回!");
		str[0] = getchar();
		str[0] = getchar();
		home();
	}
	printf("请输入需要修改的选项( 1.书籍名称  2.作者  3.发行商  4.价格  5.编号 ) :  ");
	scanf("%d",&number);
	switch(number){
		case 1:
			printf("请输入新的书籍名称 :");
			scanf("%s",table[id].name);
			break;
		case 2:
			printf("请输入新的书籍作者 :");
			scanf("%s",table[id].writer);
			break;
		case 3:
			printf("请输入新的书籍发行商 :");
			scanf("%s",table[id].publisher);
			break;
		case 4:
			printf("请输入新的书籍价格 :");
			scanf("%d",table[id].money);
			break;
		case 5:
			printf("请输入新的编号 :");
			scanf("%d",table[id].id);
	}
	printf("信息修改成功！！！！\n");
	printf("按任意键返回!");
	str[0] = getchar();
	str[0] = getchar();
	home();
}
// 往下到 164 C
void hs3(){
	char str[100];
	int id,last=0,flag=1;
	printf("请输入需要删除书籍的编号\n");
	scanf("%d",&id);
	for(int i=right[last];i;last = i,i=right[i])
		if(table[i].id == id){
			flag = 0;
			right[last] = right[i];
		}
	if(flag) printf("编号不存在！！！！\n");
	else printf("书籍删除成功！！！！\n");
	printf("按任意键返回!");
	str[0] = getchar();
	str[0] = getchar();
	home();
}
void hs4(){
	int flag=0;
	char str[100];
	printf("请输出是出借,还是归还(1.出借  2.归还) : ");
	scanf("%d",&data[tim].flag);
	printf("请输入书籍编号 : ");
	scanf("%d",&data[tim].id);
	for(int i= right[0];i;i=right[i])
		if(table[i].id == data[tim].id)
			flag = 1;
	if(!flag)
	{
		printf("编号不存在!!!!!\n"); 
		printf("按任意键返回!");
		str[0] = getchar();
		str[0] = getchar();
		home();
	}
	printf("请输入时间 (格式为 2010.1.1)  :");
	scanf("%d.%d.%d",&data[tim].year,&data[tim].month,&data[tim].day);
	if(data[tim].month<=0||data[tim].month>12||data[tim].day<=0||data[tim].day >arr[data[tim].month])
	{
		printf("输入日期不合法!!!!!\n"); 
		printf("按任意键返回!");
		str[0] = getchar();
		str[0] = getchar();
		home();	
	}
	printf("请输入借书者姓名 ： ");
	scanf("%s",str);
	strncpy(data[tim].name,str,100);
	printf("请输入班级编号: ");
	scanf("%d",&data[tim].grades);
	tim++;
	printf("书籍借入信息登记成功!!!\n");
	printf("按任意键返回!");
	str[0] = getchar();
	str[0] = getchar();
	home();
}
// 往下到 257 D
void hs5(){
	char str[100];
	int number,flag,last=0,money;
	book book1;
	printf("请选择排序的标签 ( 1.价格  2.编号 ) :  ");
	scanf("%d",&number);
	printf("	书籍名称	作者		发行商		价格	 编号\n");
		flag =1;
		while(flag){
			flag = 0;
			money = 100000000;
			for(int i=right[0];i;i=right[i]){
				switch(number)
				{
					case 1:
						if(table[i].money < money && table[i].money > last){
							strncpy(book1.name,table[i].name,100);
							strncpy(book1.publisher,table[i].publisher,100);
							strncpy(book1.writer,table[i].writer,100);
							money = table[i].money;
							book1.money = table[i].money;
							book1.id = table[i].id;
							flag = 1;
						}
						break;
					case 2:
						if(table[i].id < money && table[i].id > last){
								strncpy(book1.name,table[i].name,100);
								strncpy(book1.publisher,table[i].publisher,100);
								strncpy(book1.writer,table[i].writer,100);
								money = table[i].id;
								book1.money = table[i].money;
								book1.id = table[i].id;
								flag = 1;
							}
							break;
				}
			}
			last = money;
			if(flag)
				printf("	%s 	  	%s 	  	 %s 	 	%d 	  %d\n",book1.name,book1.writer,book1.publisher,book1.money,book1.id);
		}
	printf("按任意键返回!");
	str[0] = getchar();
	str[0] = getchar();
	home();
}
void hs6(){
	char str[100];
	int number;
	int year,month,day,id,flag=0,i;
	printf("请入需要搜索的信息 (1.日期 2.姓名 3.书籍编号)");
	scanf("%d",&number);
	printf("\n 	书籍编号   借出/借入  借者	  班级	    日期 \n");
	switch(number){
		case 1:
			printf("请输入需要查找的日期 (例 2008.1.1) :");
			scanf("%d.%d.%d",&year,&month,&day);
			for(i=0;i<tim;i++)
				if(data[i].year == year&&data[i].month == month && data[i].day == day)
					printf("	%d 	       %d          %s     %d 	    %d/%d/%d\n",data[i].id,data[i].flag,data[i].name,data[i].grades,data[i].year,data[i].month,data[i].day);
		break;
		case 2:
			printf("请输入需要查找的名字 :");
			scanf("%s",str);
			for(i=0;i<tim;i++)
					if(check(data[i].name,str))
						printf("	%d 	       %d          %s     %d 	    %d/%d/%d\n",data[i].id,data[i].flag,data[i].name,data[i].grades,data[i].year,data[i].month,data[i].day);
		break;
		case 3:
			printf("请输入需要查找的书籍编号 :");
			scanf("%d",&id);
			for(i=0;i<tim;i++)
					if(data[i].id == id)
						printf("	%d 	       %d          %s     %d 	    %d/%d/%d\n",data[i].id,data[i].flag,data[i].name,data[i].grades,data[i].year,data[i].month,data[i].day);
		break;
	}
	printf("按任意键返回!");
	str[0] = getchar();
	str[0] = getchar();
	home();
}
void hs7(){
	char str[100];
	printf("\n 	书籍编号   借出/借入  借者	  班级	    日期 \n");
	for(int i=0;i<tim;i++)
	printf("	%d 	       %d          %s     %d 	    %d/%d/%d\n",data[i].id,data[i].flag,data[i].name,data[i].grades,data[i].year,data[i].month,data[i].day);
	printf("\n\n");
	printf("按任意键返回!");
	str[0] = getchar();
	str[0] = getchar();
	home();
}
// 剩下的 A
void home(){
		system("cls");
		printf("     *    coding by 腾达科技有限公式  *     \n");
		printf("     **********************************     \n");
		printf("     *	  图书馆书籍管理系统          *		\n");
		printf("     *   ==========================   *		\n");
		printf("     *   1. 添加书籍                  *		\n");
		printf("     *   2. 修改书籍属性              *		\n");
		printf("     *   3. 删除书籍                  *     \n"); 
		printf("     *   4. 添加出借记录              *     \n"); 
		printf("     *   5. 查看所有书籍情况          *     \n");
		printf("     *   6. 搜索书籍出借情况          *     \n"); 
		printf("     *   7. 查看所有出借情况          *     \n");
		printf("     *   8. 退出			          *     \n");
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
				printf("  按回车退出系统 \n");
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

int main(int argc, char* argv[])
{
	home(); 
	return 0;
}

