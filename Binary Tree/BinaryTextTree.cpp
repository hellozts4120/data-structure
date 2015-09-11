#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char BiTree[100];

void InitTree(){	//�ı�����ʼ��
    int i;
    for(i = 0; i < 100; i++)
        BiTree[i] = 0;
}

void Create(){		//��������Ҫ
	char c;
	char data[10];
	int level;		//�����
	int pindex;
	int index;
	cin >> data;	//����ÿ���ڵ㴦����Ϣ���������;
	if(data[0] == '0' && data[1] == '\0'){
		return;		//�����롰0����������������
	}
	c = data[strlen(data) - 1];		//�ڵ��ַ��������һλ������Ϣ;
	for(level = 0;data[level] == '-';level++);	//leȷ���˽�����ڲ���level;
	for(pindex = pow(2,level) - 1;pindex > 1 && !BiTree[pindex];pindex--);	//ȷ�������pindex;
	if(pindex == 0){
		index = 1;		//��ʱ���Ϊ���ڵ�
	}
	else index = 2 * pindex;	//���ӱ��Ϊ�����*2;
	if(BiTree[index]){
		index++;	//�������Ѿ��������ˣ���ǰΪ�Һ���
	}
	BiTree[index] = c;
	Create();
}

void PreOrder(int root){	//ǰ��
	if(BiTree[root] == 0 || BiTree[root] == '*'){
		return;
	}
	printf("%c",BiTree[root]);
	PreOrder(2 * root);
	PreOrder(2 * root + 1);
}

void MidOrder(int root){	//����
	if(BiTree[root] == 0 || BiTree[root] == '*'){
		return;
	}
	MidOrder(2 * root);
	printf("%c",BiTree[root]);
	MidOrder(2 * root + 1);
}

void PostOrder(int root){	//����
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
		printf("\n");	//������֮����һ�����и������ʶ��һ��'\n';
	
	return 0;
}