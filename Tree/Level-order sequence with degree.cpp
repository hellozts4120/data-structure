#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct Tree{
	char info;
	Tree *child[26];
	Tree(char name){
		info = name;
		for(int i = 0; i < 26; i++){
			child[i] = NULL;
		}
	};
	~Tree(){
		for(int i = 0; i < 26; i++){
			delete child[i];
			child[i] = NULL;
		}
	};
};

void makeTree(Tree *&root){
	int sonNum;
	char name;
	queue<Tree*>q_root;
	queue<int>q_child_seq;
	cin >> name >> sonNum;
	root = new Tree(name);
	for(int i = 0; i < sonNum; i++){
		q_root.push(root);
		q_child_seq.push(i);
	}
	while(!q_root.empty()){
		Tree *curNode = q_root.front();
		cin >> name >> sonNum;
		curNode -> child[q_child_seq.front()] = new Tree(name);
		for(int i = 0; i < sonNum; i++){
			q_root.push(curNode -> child[q_child_seq.front()]);
			q_child_seq.push(i);
		}
		q_root.pop();
		q_child_seq.pop();
	}
}

void PostOut(Tree *root){
	for(int i = 0; (root->child[i])&&(i<26); i++){
		PostOut(root->child[i]);
	}
	cout << root->info << ' ';
}

int main(){
	int n;
	cin >> n;
	Tree *root;
	while(n--){
		makeTree(root);
		PostOut(root);
	}
	return 0;
}
