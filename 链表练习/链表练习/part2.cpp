#include<cstdio>
#include<malloc.h>
#include<cstdlib>
struct intNode
{
	int value;
	intNode *next;
};

intNode *creat(int n)
{
	intNode *head,*tail,*p;
	int i;
	head = NULL;
	tail = NULL;
	for(i = 0;i < n;i++){
		p = (intNode *)malloc(sizeof(intNode));
		printf("Enter NO.%d Value:",i + 1);
		scanf("%d",&p -> value);
		if(head == NULL){
			head = p;
			tail = p;
		}
		else{
			tail -> next = p;
			tail = tail -> next;
		}
	}
	if(tail != NULL){
		tail -> next = NULL;
	}
	return head;
}

intNode *creatsort(int n)
{
	intNode *head,*p,*q,*r;
	int i;
	head = NULL;
	for(i = 0;i < n;i++){
		p = (intNode *)malloc(sizeof(intNode));
		printf("Enter NO.%d Value:",i + 1);
		scanf("%d",&p -> value);
		q = head;
		while(q != NULL && (p -> value) > (q -> value)){
			r = q;
			q = q -> next;
		}
		if(q == head){
			head = p;
			p -> next = q;
		}
		else{r -> next = p;
		p -> next = q;
		}
	}
	return head;
}


int main()
{
	intNode *p,*q;
	int choose;
	int n;
	printf("输入链表的表元个数：");
	scanf("%d",&n);
	printf("1.顺序输出；2.按从小到大输出\n");
	scanf("%d",&choose);
	if(choose == 1){
		q = creat(n);
	}
	else{q = creatsort(n);}
	while(q){
		printf("%d ",q -> value);
		q = q -> next;
	}
	system("pause");
	return 0;
}