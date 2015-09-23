#include<iostream>
#include<cstdio>
using namespace std;

char Input[2000];
char Output[1000];
struct BinaryTree{
	char value;
	BinaryTree *left;
	BinaryTree *right;
};

BinaryTree *Stack[1000];	//��ջ��ֻ���游�ڵ�
BinaryTree *Queue[1000];	//�ö���ʵ�ֿ���

BinaryTree *MakeTree(int n){		//������ǰ������
	BinaryTree *root = new BinaryTree;
	root->value = Input[0];
	root->left = NULL;
	root->right = NULL;
	int pos = -1;
	Stack[++pos] = root;
	for(int i = 2;i < n*2;i += 2){
		BinaryTree *temp = new BinaryTree;
		temp->value = Input[i];
		temp->left = NULL;
		temp->right = NULL;
		BinaryTree *parent = Stack[pos];
		if(parent->left == NULL){
			parent->left = temp;
		}
		else if(parent->right == NULL){
			parent->right = temp;
		}
		else{
			while(Stack[pos]->right != NULL){
				pos--;
			}
			Stack[pos]->right = temp;
		}
		if(Input[i + 1] == '0'){
			Stack[++pos] = temp;
		}
	}
	return root;
}

void MirrorReflect(BinaryTree *root){
	int Qpos = -1,front = 0;		//��ʼʱ����Ϊ�գ���ʱ��־Ϊpos+1 = front;
	int Spos = -1;
	int out = -1;
	BinaryTree *head;
	Queue[++Qpos] = root;		//���
	//����(���������������ף�Ȼ��Ӻ���ǰ�����������ڵ�����󣬼�����������)
	while(Qpos+1 != front){		//���зǿ�
		head = Queue[front++];
		Output[++out] = head->value;
		if(head->left != NULL){
			BinaryTree *current = head->left;
			while(current != NULL){
				Stack[++Spos] = current;
				current = current->right;
			}
			while(Spos != -1){
				Queue[++Qpos] = Stack[Spos--];
			}
		}
	}
	//print
	for(int i = 0;i <= out;i++){
		if(Output[i] != '$'){
			cout << Output[i] << " ";
		}
	}
	cout << endl;
}

void DeleteTree(BinaryTree *root){
	if(root != NULL){
		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
		root = NULL;	//��ֹҰָ��;
	}
}

int main(){
	int n;
	cin >> n;
	int place = 0;
	for(int i = 0;i < n;i++){
		cin >> Input[place++];
		cin >> Input[place++];
		getchar();
	}
	BinaryTree *root = MakeTree(n);
	MirrorReflect(root);
	DeleteTree(root);
	return 0;
}