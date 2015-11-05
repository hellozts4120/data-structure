#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node{
	char label[100];
	int priority;
	int left,right;
	int parent;
	Node(){
		left = right = priority = 0;
	};
}Treap[50005];

int cmp(Node a, Node b){
	return (strcmp(a.label,b.label) < 0);
}

void Insert(int i){
	int temp = i - 1;
	while(Treap[temp].priority < Treap[i].priority){
		temp = Treap[temp].parent;
	}
	Treap[i].left = Treap[temp].right;
	Treap[temp].right = i;
	Treap[i].parent = temp;
}

void InorderTraverse(int i){
	if(i){
		cout << "(";
		InorderTraverse(Treap[i].left);
		cout << Treap[i].label << "/" << Treap[i].priority;
		InorderTraverse(Treap[i].right);
		cout << ")";
	}
	return;
}

int main(){
	int num;
	while(cin >> num){
		if(!num) break;
		memset(Treap,0,sizeof(Treap));
		Treap[0].priority = 100000;
		for(int i = 1; i <= num; i++){
			char str[1000];
			int temp = 0;
			int j;
			cin >> str;
			for(j = 0; str[j] != '/'; j++){		//可使用正则表达式'scanf("%*[ ]%[^/]/%d",treap[i].str,&treap[i].value);'
				Treap[i].label[j] = str[j];
			}
			Treap[i].label[j] = '\0';
			while(str[++j]){
				temp = 10 * temp + (str[j] - '0');
			}
			Treap[i].priority = temp;
		}
		sort(Treap + 1,Treap + num + 1,cmp);
		for(int i = 1; i <= num; i++){
			Insert(i);
		}
		InorderTraverse(Treap[0].right);
		cout << endl;
	}
	return 0;
}
		