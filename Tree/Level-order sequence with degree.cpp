#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct DegreeTree{
	char info;
	int degree;
	DegreeTree *left;
	DegreeTree *right;
};
DegreeTree *root[100];

DegreeTree *MakeTree(DegreeTree *root){
	DegreeTree *p = new DegreeTree;
	p->left = NULL;
	p->right = NULL;
	char space,num,next;
	cin >> root->info;
	cin >> space;
	cin >> num;
	cin >> space;
	root->degree = num - '0';
	cin >> next;
	while(next != '\n'){
		root->left = p;
		p->info = next;
		cin >> space;
		cin >> num;
		cin >> space;
		p->degree = num - '0';
		(root->degree)--;
		if(root->degree >= 0){
			while(root->degree > 0){
				DegreeTree *q = new DegreeTree;
				q->left = NULL;
				q->right = NULL;
				cin >> q->info;
				cin >> space;
				cin >> num;
				cin >> space;
				q->degree = num - '0';
				p->right = q;
				p = q;
				(root->degree)--;
			}
		}

	}
}

void PrintTree(DegreeTree *root){
	if(root == NULL){
		return;
	}
	PrintTree(root->left);
	cout << root->info << " ";
	PrintTree(root->right);
}

void DeleteTree(DegreeTree *root){
	if(root != NULL){
		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
		root = NULL;	//·ÀÖ¹Ò°Ö¸Õë;
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		MakeTree(root[i]);
	}
	for(int i = 0;i < n;i++){
		PrintTree(root[i]);
		DeleteTree(root[i]);
	}
	return 0;
}
