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
	if(len<40){				// ���������������������������� 
		len++;
		printf("  ������ķ��������: (1 - ����    2-  ֧��):   ");
		scanf("%d",&a);
		printf("  �������������:   "); 
		scanf("%s",str);
		arr[len].leixing = a;
		arr[len].id=len;
		strncpy(arr[len].str,str,100);
		if(a==1)
		printf("  ���һ���µ��������ͣ���ţ�%d , �������ƣ�%s\n",len,str);	
		else 
		printf("  ���һ���µ�֧�����ͣ���ţ�%d , �������ƣ�%s\n",len,str);
	}
	else  printf("  ���������Ѵ����ޣ��޷���ӣ�\n");
	printf("  ���س�������");
	char ch; 
	ch = getchar();
	ch = getchar();
	home(); 
}
void hs2(){
	int id,a;
	char str[100];
	printf("  ��������Ҫ�޸ķ���ı��:  ");
	scanf("%d",&id);
	if(id<=0||id>len) printf("������ķ����Ų����ڣ����ܲ���!\n");
	else {
		printf("  ������ķ��������: (1 - ����    2-  ֧��):   ");
		scanf("%d",&a);
		printf("  ����������������:   "); 
		scanf("%s",str);
		arr[id].leixing = a;
		strncpy(arr[id].str,str,100);
		if(a==1)
			printf("  ���Ϊ%d�ķ��� %s ����޸�,Ŀǰ������������\n",id,str);
		else 
			printf("  ���Ϊ%d�ķ��� %s ����޸�,Ŀǰ����֧������\n",id,str);
	} 
	printf("  ���س�������");
	char ch; 
	ch = getchar();
	ch = getchar();
	home(); 
}
void hs3(){
	printf("������          ��������          ��������\n");
	int i;
	for(i=1;i<=len;i++){
	printf("   %2d          	   %10s         ",arr[i].id,arr[i].str);
	if(arr[i].leixing == 1) printf("����\n");
	else printf("֧��\n");
	}
	printf("  ���س�������");
	char ch; 
	ch = getchar();
	ch = getchar();
	home();
}
void hs4(){
	char str[100];
	int money,id;
	printf("  ���������ı��:  ");
	scanf("%d",&id);
	if(id<=0||id>len) printf("  ������ķ����Ų����ڣ����ܲ���!\n");
	else{
		size++;
		printf("  ���뱾��ת�˼�¼������ : ");
		scanf("%s",str);
		printf("  ���뱾��ת�˼�¼�Ľ�� : ");
		scanf("%d",&money);
		table[size].money=money;
		table[size].day =26;
		table[size].year =2018;
		table[size].moth =4;
		table[size].id = id;
		strncpy(table[size].str,str,100);
		printf("  �ôμ�¼�Ѿ����!\n"); 
		
	}
	printf("  ���س�������");
	char ch; 
	ch = getchar();
	ch = getchar();
	home();
}
void hs5(){
	char ch,str[100];
	int number,id,year,moth,day,money;
	printf("  �������¼���: ");
	scanf("%d",&id);
	ch = getchar();
	if(id>0&&id<=size)
	{
		printf("  �Ƿ���Ҫ�޸�ת�˼�¼�ķ��� : (y/n)  ");
		scanf("%c",&ch);
		if(ch == 'y')
		{
			printf("  �����뱾�μ��˼�¼�ķ����� :   ");
			scanf("%d",&number);
			if(number<=0&&number>len){
				printf("  ������ķ����Ų����ڣ����β���������ϵͳ!\n");
				home();
			}
			ch = getchar();
		}
		printf("  �Ƿ���Ҫ�޸�ת�˼�¼������ : (y/n)  ");
		scanf("%c",&ch);
		if(ch == 'y')
		{
			printf("  �����뱾�μ��˼�¼������ :  ");
			scanf("%s",str);
			ch = getchar();
		}
		
		printf("  �Ƿ���Ҫ�޸�ת�˼�¼�Ľ�� : (y/n)  ");
		scanf("%c",&ch);
		if(ch == 'y')
		{
			printf("  �����뱾�μ��˼�¼�Ľ�� :   ");
			scanf("%d",&money);
			ch = getchar();
		}
		
		printf("  �Ƿ���Ҫ�޸�ת�˼�¼��ʱ�� : (y/n)  ");
		scanf("%c",&ch);
		if(ch == 'y')
		{
			printf("  �����뱾�μ��˼�¼����� :   ");
			scanf("%d",&year);
			table[id].year = year;
			ch = getchar();
			printf("  �����뱾�μ��˼�¼����� :   ");
			scanf("%d",&moth);
			if( moth <=0||moth> 12) {
				printf("  ��������·ݲ����ڣ����β���������ϵͳ!\n");
				home();
			}
			ch = getchar();
			printf("  �����뱾�μ��˼�¼����� :   ");
			scanf("%d",&day);
			
			if(day <=0 || day> riqi[moth] ){
				printf("  ����������ڲ����ڣ����β���������ϵͳ!\n");
				home();
			}
				ch = getchar();
		}
		
		table[id].id = number;
		strncpy(table[id].str,str,100);
		table[id].money = money;
		table[id].moth = moth;
		table[id].day = day;
		printf("���μ�¼�޸���ɣ�");
	}
	else printf("  ������ļ�¼��Ų����ڣ����ܲ���!\n");
	printf("  ���س�������"); 
	ch = getchar();
	ch = getchar();
	home();
}
void hs6(){
	int id;
	printf("  �������¼���: ");
	scanf("%d",&id);
	if(id<=0||id>size) printf("������ļ��˱�Ų����ڣ����ܲ���!\n");
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
		printf("��¼ɾ���ɹ�!!\n");
		size--;
	}
	printf("  ���س�������"); 
	char ch;
	ch = getchar();
	ch = getchar();
	home();
}
void hs7(){
	
	printf("��¼���          ��������          ���          ��¼ʱ��          ����\n");
	int i;
	for(i=1;i<=size;i++)
	{
		printf(" %2d           %10s            %5d          %4d.%2d.%2d          %s\n",i,arr[table[i].id].str,arr[table[i].id].leixing==1?table[i].money:-table[i].money,table[i].year,table[i].moth,table[i].day,table[i].str);
	}
	printf("  ���س�������"); 
	char ch;
	ch = getchar();
	ch = getchar();
	home();
}
void hs8(){
	int moth;
	char ch;
	printf("  ����������Ҫ�˽���·�:  ");
	scanf("%d",&moth);
	if(moth<=0||moth>12)printf("  ��������·ݲ����ڣ����ܲ���!\n");
	else{
		int i,j,sum,mun=0;
		printf("��������		���\n");
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
		printf("%d�µ���֧���Ϊ:%d\n  ",moth,mun);
	}
	printf("  ���س�������"); 
	ch = getchar();
	ch = getchar();
}
void home(){
		system("cls");
		printf("     **********************************     \n");
		printf("     *	  ��ӭʹ�ü��ü��˹���ϵͳ    *		\n");
		printf("     *   ==========================   *		\n");
		printf("     *   1. ��Ӽ��˷���              *		\n");
		printf("     *   2. �޸ļ��˷���              *		\n");
		printf("     *   3. ��ʾȫ�����˷���          *     \n"); 
		printf("     *   4. ��Ӽ��˼�¼              *     \n"); 
		printf("     *   5. �޸ļ��˼�¼              *     \n"); 
		printf("     *   6. ɾ�����˼�¼              *     \n"); 
		printf("     *   7. ��ʾ���˼�¼              *     \n");
		printf("     *   8. ��ʾ�¶ȿ������ݱ���      *     \n");
		printf("     *   9. ע��                      *     \n");
		printf("     **********************************     \n");
		printf("  ��ѡ������Ҫ�Ĳ���:  ");
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
				printf("  ���س�ע�� \n");
				ch = getchar();
				return;
			default:
				printf("  ��������ȷ�ı��!!!!\n");
				printf("  ���س�������");  
				ch = getchar();
				home();
				break;
		}
}
void d1(){
	 char str1[100],str2[100],ch;
	 printf("  �������˺�:  ");
	 scanf("%s",str1);
	 ch = getchar();
	 printf("  ����������:  "); 
	 scanf("%s",str2);
	 int i;
	 for(i=1;i<=user_number;i++)
	 	if(check(user[i].name,str1)){
	 		if(check(user[i].password,str2))
	 		{
				printf("  �𾴵�%s��,��ӭ����\n",user[i].name);	 
				printf("  ���س����ؽ���ϵͳ��ҳ ");
				
				//printf("  \n\n\n\n\n���Թ��ܽ���!!!\n");
				//printf("  ���س����ص�����ҳ ");
				ch = getchar();
				ch = getchar();
				//login();
				home();
				login();
			}
			else
			{
				printf(" ������󣡣��� \n");
				printf("  ���س����ص������ ");
				ch = getchar();
				ch = getchar();
				login(); 
			}
		}
	printf("  �û�������!!!!\n");
	printf("  ���س����ص������ ");
	ch = getchar();
	ch = getchar();
	login(); 		
}
void d2(){
	char str1[100],str2[100],str3[100],ch;
	printf("  ������ע���˻���:   ");
	scanf("%s",str1);
	int i;
	for(i=1;i<=user_number;i++)
		if(check(user[i].name,str1))
		{
			printf(" �û����ظ�!!!!\n");
			printf(" ���س����ص������ ");
			ch = getchar();
			ch = getchar();
			login(); 	
		}
	ch = getchar();
	printf("  �û����Ϸ�������\n"); 
	printf("  ����������:   ");
	scanf("%s",str2);
	ch = getchar();
	printf("  ������������:   "); 
	scanf("%s",str3);
	ch = getchar();
	if(check(str3,str2)){
		printf("  �û�ע��ɹ�������!\n");
		printf("  ���س����ص������ ");
		user_number++;
		strncpy(user[user_number].name,str1,100);
		strncpy(user[user_number].password,str2,100);
		ch = getchar();
		ch = getchar();
		login(); 
	}
	else{
		printf("  �û�ע��ʧ�ܣ�������\n");
		printf("  �������벻һ��������!\n");
		printf("  ���س����ص������ ");
		ch = getchar();
		ch = getchar();
		login(); 
	} 
}
void login(){
	system("cls");
		printf("     **********************************     \n");
		printf("     *	  ��ӭʹ�ü��ü��˹���ϵͳ    *		\n");
		printf("     *	           �������           *		\n");
		printf("     *                                *     \n");
		printf("     *          1  �˻�����           *     \n");
		printf("     *          2  �û�ע��           *     \n");
		printf("     *          3  �˳�               *     \n");
		printf("     **********************************     \n");
		printf("  ��ѡ������Ҫ�Ĳ���:  ");
		int k; 
		char ch;
		scanf("%d",&k);
		ch = getchar();	
		if(k==1)  d1();
		else if(k==2) d2();
		else {
			printf("  ���س��˳�ϵͳ \n");
			ch = getchar();
			return;
		}
}  
int main(){
	login(); 
	return 0;
}

