#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct Node{
	char value;
	Node *next;
	Node *front;
};
Node *head = (Node*)malloc(sizeof(Node));
Node *tail = (Node*)malloc(sizeof(Node));
char str[10005];
char ans[10000000];
int count = 0;

void Create(char *c){
	Node *temp = head;
	tail->next = NULL;
	tail->front = head;
	head->next = tail;
	head->front = NULL;
	head->value = '-';
	tail->value = '-';
	while(*c != '\0'){
		Node *cur = (Node*)malloc(sizeof(Node));
		cur->value = *c++;
		cur->front = temp;
		cur->next = temp->next;
		temp->next->front = cur;
		temp->next = cur;
		temp = cur;
	}
}

void Insert(char c,int pos){
	int n = -1;
	Node *temp = head;
	Node *cur = (Node*)malloc(sizeof(Node));
	while(n != pos){
		temp = temp->next;
		n++;
	}
	cur->value = c;
	cur->front = temp->front;
	cur->next = temp;
	temp->front->next = cur;
	temp->front = cur;
}

void PrintAll(bool flag){
	Node *temp = head->next;
	if(temp == tail){
		ans[count++] = '-';
	}
	else{
		while(temp->next != NULL){
			ans[count++] = temp->value;
			temp = temp->next;
		}
	}
	ans[count++] = '\n';
	if(flag || count >= 9000000){
		ans[count] = '\0';
		printf("%s",ans);
		count = 0;
	}
}

void Delete(int pos){
	Node *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL, *temp = head;
	Node *begin = head, *end = tail;
	bool flag = true;
	int n = -1;
	int sameCount;

	while(n < pos - 2){
		n++;
		temp = temp->next;
	}
	begin = temp;
	end = temp;
	n = 0;
	while((n < 4) && (end->next != tail)){		//1 longest seq will have 5 char;0,1,2,3,4...
		end = end->next;
		n++;
	}
	while(flag && (temp != tail)){
		flag = false;
		sameCount = 1;
		while(temp != end){
			temp = temp->next;
			if(temp->front->value == temp->value){
				sameCount++;
			}
			else{
				sameCount = 1;
			}
			if(sameCount == 3){
				flag = true;
				if(temp->value == temp->next->value){
					sameCount++;
					temp = temp->next;
				}
				if(temp->value == temp->next->value){
					sameCount++;
					temp = temp->next;
				}
				if(sameCount == 3){
					p1 = temp;
					p2 = temp->front;
					p3 = p2->front;
					p3->front->next = p1->next;
					p1->next->front = p3->front;
					temp = temp->next;
					delete p1,p2,p3;
				}
				else if(sameCount == 4){
					p1 = temp;
					p2 = temp->front;
					p3 = p2->front;
					p4 = p3->front;
					p4->front->next = p1->next;
					p1->next->front = p4->front;
					temp = temp->next;
					delete p1,p2,p3,p4;
				}
				else {
					p1 = temp;
					p2 = temp->front;
					p3 = p2->front;
					p4 = p3->front;
					p5 = p4->front;
					p5->front->next = p1->next;
					p1->next->front = p5->front;
					temp = temp->next;
					delete p1,p2,p3,p4,p5;
				}
				break;
			}
		}
		if(flag && (temp != tail)){
			begin = temp;
			n = 0;
			while((n < 2) && (begin->front != head)){
				n++;
				begin = begin->front;
			}
			end = temp;
			n = 0;
			while((n < 1) && (end->next != tail)){
				n++;
				end = end->next;
			}
			temp = begin;
		}
	}
}


int main(){
	int n;
	//head = NULL;
	gets(str);
	scanf("%d",&n);
	Create(str);
	for(int i = 0; i < n; i++){
		int k;
		char c;
		scanf("%d ",&k);
		c = getchar();
		Insert(c,k);
		Delete(k);
		PrintAll(i == n - 1?1:0);
	}
	return 0;
}