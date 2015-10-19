#include<stdio.h>
#include<malloc.h>

struct Node{
	int value;
	Node *left;
	Node *right;
};

int PreOrder[4000005];
int PostOrder[4000005];

Node* ReBuild(int num,int *PreOrder,int *PostOrder){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->value = *PreOrder;
	if(num == 1){
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	int pos = 0;
	while(pos < num){
		if(PostOrder[pos] == *(PreOrder + 1)){
			break;
		}
		pos++;
	}
	temp->left = ReBuild((pos + 1),(PreOrder + 1),PostOrder);
	temp->right = ReBuild((num - pos - 2),(PreOrder + pos + 2),(PostOrder + pos + 1));
	return temp;
}

void InTraverse(Node *root){
	if(root == NULL){
		return;
	}
	InTraverse(root->left);
	printf("%d ",root->value);
	InTraverse(root->right);
}

int main(){
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
	setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&PreOrder[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&PostOrder[i]);
	}
	Node *root = ReBuild(n,PreOrder,PostOrder);
	InTraverse(root);
	printf("\n");
	return 0;
}