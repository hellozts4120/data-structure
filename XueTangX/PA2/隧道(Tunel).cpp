#include<stdio.h>
#include<malloc.h>

struct queueNode{
	int value;
	queueNode *next,*pre;
};

struct PqueueNode{
	int value;
	int num;
	PqueueNode *next,*pre;
};

int main(){
	queueNode *head = (queueNode*)malloc(sizeof(queueNode));
	queueNode *tail = head;
	queueNode *temp;
	PqueueNode *phead = (PqueueNode*)malloc(sizeof(PqueueNode));
	PqueueNode *ptail = phead;
	PqueueNode *temp1;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		char c;
		int a;
		do
		{
			c = getchar();
		} while ((c != 'E') && (c != 'M') && (c != 'D'));
		switch(c){
		case 'E':
			int x;
			scanf("%d",&x);
			temp = (queueNode*)malloc(sizeof(queueNode));
			temp->value = x;
			tail->next = temp;
			temp->pre = tail;
			tail = temp;
			/* deal with Pqueue */
			a = 1;
			temp1 = (PqueueNode*)malloc(sizeof(PqueueNode));
			ptail->next = temp1;
			temp1->pre = ptail;
			ptail = temp1;
			while((ptail->pre != phead) && (ptail->pre->value <= x)){
				a += ptail->pre->num;
				temp1 = ptail->pre;
				temp1->pre->next = ptail;
				ptail->pre = temp1->pre;
				delete temp1;
			}
			ptail->num = a;
			ptail->value = x;
			break;
		case 'D':
			printf("%d\n",head->next->value);
			head = head->next;
			delete head->pre;
			/* deal with Pqueue */
			if(!(--phead->next->num)){
				phead = phead->next;
				delete phead->pre;
			}
			break;
		case 'M':
			printf("%d\n",phead->next->value);
			break;
		}
	}
	return 0;
}