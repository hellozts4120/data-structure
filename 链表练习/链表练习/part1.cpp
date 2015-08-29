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
	printf("输入学号，成绩，姓名，输入一次一回车:\n");
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
		printf("学号未找到！\n");
	}
	p = (stuS *)malloc(sizeof(stuS));
	printf("输入学号，成绩，姓名，输入一次一回车:\n");
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
	char menu[4][100] = {"1 在链表末尾添加新表元","2 在指定表元之后插入新表元","3 显示链表中所有表元","4 删除链表中指定表元"};
	int i,ans,number;
	while(1){
		printf("请选择下列菜单命令:\n");
		for(i = 0;i < 4;i++){
			printf("\t%s\n",menu[i]);
		}
		printf("\t其他选择则结束本程序运行!\n");
		scanf("%d",&ans);
		switch(ans){
			case 1: head = append(head);break;
			case 2: printf("输入插入学生编号！\n");
					scanf("%d",&number);
					insert(head,number);break;
			case 3: travelStuLink(head);break;
			case 4: printf("请输入要删除的学生编号！\n");
					scanf("%d",&number);
					head = delStu(head,number);break;
			default: return 0;
		}
	}
	system("pause");
	return 0;
}