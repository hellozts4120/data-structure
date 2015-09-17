#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<malloc.h>
using namespace std;

struct BstNode{
	int value;
	BstNode *Left;
	BstNode *Right;
};


BstNode * newTree(){
	BstNode *newOne;
	newOne = (BstNode *)malloc(sizeof(BstNode));
	newOne->Left = NULL;
	newOne->Right = NULL;
	return newOne;
}

void PreOrder(BstNode *t){
	if(t){
		printf("%d ",t -> value);
		PreOrder(t -> Left);
		PreOrder(t -> Right);
	}
}

void Search(BstNode *t,int x){
	if(t == NULL){
		return;
	}
	else if(t->value > x){
		if(t->Left == NULL){
			t->Left = newTree();
			t->Left->value = x;
			return;
		}
		Search(t->Left,x);
	}
	else if(t->value < x){
		if(t->Right == NULL){
			t->Right = newTree();
			t->Right->value = x;
			return;
		}
		Search(t->Right,x);
	}
	else return;
}

void Insert(BstNode *t,int x){
	Search(t,x);
}

int main(){
	BstNode Root;
	char flag = ' ';
	int x;
	cin >> x;
	Root.value = x;
	Root.Left = NULL;
	Root.Right = NULL;
	for(;flag == ' ';){
		cin >> x;
		flag = getchar();
		Insert(&Root,x);
	}
	PreOrder(&Root);
	return 0;
}