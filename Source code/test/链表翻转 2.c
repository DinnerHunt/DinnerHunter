#include <stdio.h>
#include <stdlib.h>
typedef struct _Node 
{
	int value;
	struct _Node *next;
}Node;

typedef struct _list{
	Node *head;
}List;
void add(List* pList,int number){
	Node *p=(Node*) malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	Node *last=pList->head;
	if(last){
		while(last->next)
			last = last->next;
		last->next=p;
	}
	else
		pList->head=p;
}
Node* listinvert(Node* head){
	if(!head)
		return 0;
	Node* xpre=head;
	Node* x=head->next;
	for(;xpre->next!=0;x=xpre->next)
	{
		xpre->next=x->next;
		x->next=head;
		head=x;
	}
	return head;
}
void print(List* pList){
	Node* p=pList->head;
	for(;p;p=p->next)
		printf("%d ",p->value);
}
void freelist(List* pList){
	Node* p=pList->head;
	Node* q;
	for(;p;p=q){
			q=p->next;
			free(p);
	}
} 
int main(){
	int number;
	List list;
	list.head=NULL;
	while(scanf("%d",&number)!=EOF){
		if(number==-1)
			break;
		add(&list,number);
	}
	list.head=listinvert((list.head));
	print(&list);
	freelist(&list);
	
	return 0;
}