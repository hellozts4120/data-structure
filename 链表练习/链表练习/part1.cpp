#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
struct stuS
{
	int number;
	int score;
	char name[20];
	stuS *next;
};

stuS *append(stuS *a) 
{
	stuS *w = a,*p;
	p = (stuS *)malloc(sizeof(stuS));
	printf("����ѧ�ţ��ɼ�������������һ��һ�س�:\n");
	scanf("%d",&p->number);
	scanf("%d",&p->score);
	scanf("%s",p->name);
	p -> next = NULL;
	if(a == NULL){
		return p;
	}
	while(w -> next != NULL){
		w = w -> next;
	}
	w -> next = p;
	return a;
}

void insert(stuS *a,int num)
{
	stuS *w = a,*p;
	while(w != NULL && w -> number != num){
		w = w -> next;
	}
	if(w == NULL){
		printf("ѧ��δ�ҵ���\n");
	}
	p = (stuS *)malloc(sizeof(stuS));
	printf("����ѧ�ţ��ɼ�������������һ��һ�س�:\n");
	scanf("%d",&p->number);
	scanf("%d",&p->score);
	scanf("%s",p->name);
	p -> next = w -> next;
	w -> next = p;
}

void travelStuLink(stuS *a)
{
	stuS *p = a;
	if(a == NULL){
		printf("No Students information!\n");
		return;
	}
	if(a){
		printf("Students information below:\n");
		while(p != NULL){
			printf("%d\t%s\t%d\n",p->number,p->name,p->score);
			p = p -> next;
		}
	}
}

stuS *delStu(stuS *a,int num)
{
	stuS *w, *p;
	if(a == NULL){
		return NULL;
	}
	p = a;
	while(p != NULL && p -> number != num){
		w = p;
		p = p -> next;
	}
	if(p){
		if(p == a){
			a = p -> next;
		}
		else{
			w -> next = p -> next;
			free(p);
			printf("Number Deleted!\n");
		}
	}
	else{
		printf("No find!\n");
	}
	return a;
}
		

int main()
{
	stuS *head = NULL;
	char menu[4][100] = {"1 ������ĩβ����±�Ԫ","2 ��ָ����Ԫ֮������±�Ԫ","3 ��ʾ���������б�Ԫ","4 ɾ��������ָ����Ԫ"};
	int i,ans,number;
	while(1){
		printf("��ѡ�����в˵�����:\n");
		for(i = 0;i < 4;i++){
			printf("\t%s\n",menu[i]);
		}
		printf("\t����ѡ�����������������!\n");
		scanf("%d",&ans);
		switch(ans){
			case 1: head = append(head);break;
			case 2: printf("�������ѧ����ţ�\n");
					scanf("%d",&number);
					insert(head,number);break;
			case 3: travelStuLink(head);break;
			case 4: printf("������Ҫɾ����ѧ����ţ�\n");
					scanf("%d",&number);
					head = delStu(head,number);break;
			default: return 0;
		}
	}
	system("pause");
	return 0;
}