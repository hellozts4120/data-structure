#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<cmath>
using namespace std;

int variable;
int n;
int result;
char dispbuf[100][100];
char str[51];
int numSeq[51];
char OutStr[51];

struct BinaryTreeNode{
	char value;
	int num;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

stack<BinaryTreeNode*> TreeStack;
stack<char> OperatorStack;
stack<int> Final;

void Trans(char str[],char post[],int &m){
	stack<char>Stack;
	for(int i = 0;i < strlen(str);i++){
		if(((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z'))){
			post[m++] = str[i];
		}
		if(str[i] == '('){
			Stack.push(str[i]);
		}
		if(str[i] == '+')
		{
			while(!Stack.empty()&&(Stack.top()=='*'||Stack.top()=='/'||Stack.top()=='-'||Stack.top()=='+')){
				post[m++]=Stack.top();Stack.pop();
			}
			Stack.push(str[i]);
		}
		 if(str[i]=='-')
            {
			while(!Stack.empty()&&(Stack.top()=='*'||Stack.top()=='/'||Stack.top()=='-'||Stack.top()=='+')){
				post[m++]=Stack.top();Stack.pop();
			}
			Stack.push(str[i]);
            }
		 if(str[i] == '*')
		 {
			 while(!Stack.empty()&&(Stack.top()=='/'||Stack.top()=='*')){
				 post[m++]=Stack.top();Stack.pop();
			 }
			 Stack.push(str[i]);
		 }
		 if(str[i] == '/')
		 {
			 while(!Stack.empty()&&(Stack.top()=='/'||Stack.top()=='*')){
				 post[m++]=Stack.top();Stack.pop();
			 }
			 Stack.push(str[i]);
		 }
		 if(str[i] == ')'){
			 while(Stack.top() != '('){
				 post[m++]=Stack.top();Stack.pop();
			 }
			 Stack.pop();
		 }
	}
	while(!Stack.empty()){
		 post[m++]=Stack.top();Stack.pop();
	}
}

BinaryTreeNode *BuildTree(){
	BinaryTreeNode *node;
	BinaryTreeNode *temp;
	for(int i = 0;i < strlen(OutStr);i++){
		if(((OutStr[i] >= 'a') && (OutStr[i] <= 'z')) || ((OutStr[i] >= 'A') && (OutStr[i] <= 'Z'))){
			node = new BinaryTreeNode;  
			node->value = OutStr[i];
			node->left = NULL;
			node->right = NULL;
			node->num = 0;
			TreeStack.push(node);
		}
		else if (OutStr[i] == '*' || OutStr[i] == '/' || OutStr[i] == '+' || OutStr[i] == '-'){
			temp = new BinaryTreeNode;
			temp->value = OutStr[i];
			temp->left = NULL;
			temp->right = NULL;
			temp->num = 0;
			temp->right = TreeStack.top();
			TreeStack.pop();
			temp->left = TreeStack.top();
			TreeStack.pop();
			TreeStack.push(temp);
		}
	}
	return TreeStack.top();
}

int CalcuTreeLevel(BinaryTreeNode *root){
	int LeftLevel,RightLevel;
	if(root == NULL){
		return 0;
	}
	LeftLevel = 1 + CalcuTreeLevel(root->left);
	RightLevel = 1 + CalcuTreeLevel(root->right);
	if(LeftLevel > RightLevel){
		return LeftLevel;
	}
	return RightLevel;
}

void Init_Disp(){
	for(int i = 0;i < 100;i++){
		for(int j = 0;j < 100;j++){
			dispbuf[i][j] = ' ';
		}
	}
}

void Delete_Out_Disp(){
	int effectiveLine = 0;
	int j;
	for(int i = 0;i < 100;i++){
		j = 99;
		while(dispbuf[i][j] == ' ' && j >= 0){--j;}
		if(j > -1){
			dispbuf[i][j + 1] = '#';
			effectiveLine++;
			continue;
		}
		else{
			break;
		}
	}
	for(int i = 0;i < effectiveLine;i++){
		for(int k = 0;k < 100;k++){
			if(dispbuf[i][k] != '#'){
				cout << dispbuf[i][k];
			}
			else {
				break;
			}
		}
		cout << endl;
	}
}

void PrintTree(BinaryTreeNode *root,int root_x,int root_y,int r_c_interval, char disp_buf[][100]){
	//参数从左至右依次为：根结点、根结点的水平位置、根结点的竖直位置、当前根结点与其左右儿子的水平间距、用于暂存打印内容的缓存
	int LeftChild,RightChild;
	LeftChild = root_x - r_c_interval;
	RightChild = root_x + r_c_interval;
	if(root == NULL){
		return;
	}
	disp_buf[root_y][root_x - 1] = root->value;
	if(root->left != NULL){
		disp_buf[root_y + 1][root_x - 2] = '/';
	}
	if(root->right != NULL){
		disp_buf[root_y + 1][root_x] = '\\';
	}
	PrintTree(root->left,LeftChild,(root_y + 2),(r_c_interval >> 1),disp_buf);
	PrintTree(root->right,RightChild,(root_y + 2),(r_c_interval >> 1),disp_buf);
}

void GetNum(){
	for(int i = 0;i < strlen(OutStr);i++){
		if((OutStr[i] >= 'a' && OutStr[i] <= 'z') || (numSeq[i] >= 'A' && numSeq[i] <= 'Z')){
			Final.push(numSeq[i]);
		}
		else{
			int a,b;
			int c;
			a = Final.top();
			Final.pop();
			b = Final.top();
			Final.pop();
			switch(OutStr[i]){
				case '+':
					c = a+b;
					break;
				case '-':
					c = b-a;
					break;
				case '*':
					c = a*b;
					break;
				case '/':
					c = b/a;
					break;
				default:;
			}
			Final.push(c);
		}
	}
	result = Final.top();
}

int main(){
	cin >> str;
	cin >> variable;
	n = 0;
	int level,input;
	char give;
	Trans(str,OutStr,n);
	while(variable--){
		cin >> give >> input;
		for(int i = 0;i < strlen(str);i++){
			if(OutStr[i] == give){
				numSeq[i] = input;
			}
		}
	}
	for(int j=0;j<n;j++){
		cout << OutStr[j];
	}
	cout << endl;
	BinaryTreeNode *root = BuildTree();
	Init_Disp();
	level = CalcuTreeLevel(root);
	//cout << pow(2,level-1)-1;
	PrintTree(root,pow(2,level-1),0,pow(2,level-2),dispbuf);
	Delete_Out_Disp();
	GetNum();
	cout << result << endl;
	return 0;
}