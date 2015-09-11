#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char BiTree[100];

void InitTree(){	//文本树初始化
    int i;
    for(i = 0; i < 100; i++)
        BiTree[i] = 0;
}

void Create(){		//造树，重要
	char c;
	char data[10];
	int level;		//结点层次
	int pindex;
	int index;
	cin >> data;	//输入每个节点处的信息，包括层次;
	if(data[0] == '0' && data[1] == '\0'){
		return;		//若输入“0”则树的制造终了
	}
	c = data[strlen(data) - 1];		//节点字符串的最后一位，即信息;
	for(level = 0;data[level] == '-';level++);	//le确定此结点所在层数level;
	for(pindex = pow(2,level) - 1;pindex > 1 && !BiTree[pindex];pindex--);	//确定父编号pindex;
	if(pindex == 0){
		index = 1;		//此时结点为根节点
	}
	else index = 2 * pindex;	//左孩子编号为父编号*2;
	if(BiTree[index]){
		index++;	//若左孩子已经被创造了，则当前为右孩子
	}
	BiTree[index] = c;
	Create();
}

void PreOrder(int root){	//前序
	if(BiTree[root] == 0 || BiTree[root] == '*'){
		return;
	}
	printf("%c",BiTree[root]);
	PreOrder(2 * root);
	PreOrder(2 * root + 1);
}

void MidOrder(int root){	//中序
	if(BiTree[root] == 0 || BiTree[root] == '*'){
		return;
	}
	MidOrder(2 * root);
	printf("%c",BiTree[root]);
	MidOrder(2 * root + 1);
}

void PostOrder(int root){	//后序
	if(BiTree[root] == 0 || BiTree[root] == '*'){
		return;
	}
	PostOrder(2 * root);
	PostOrder(2 * root + 1);
	printf("%c",BiTree[root]);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		InitTree();
		Create();
		PreOrder(1);
		printf("\n");
		PostOrder(1);
		printf("\n");
		MidOrder(1);
		printf("\n");
		printf("\n");	//两棵树之间用一个空行隔开，故多打一个'\n';
	
	return 0;
}