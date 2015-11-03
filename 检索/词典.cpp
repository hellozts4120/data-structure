#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct Node{
	char val[12];
	char eng[12];
};

Node Dic[100010];

int cmp(const void *a , const void *b){
	return strcmp(((Node *)a)->val , ((Node *)b)->val);
}

int Search(const void *a, const void *b){
	return strcmp((char *)a , ((Node *)b)->val);
}

int main(){
	char foreign[15], english[30];
	int cur = 0;
	Node *temp;
	while(fgets(english,29,stdin) && english[0] != '\n'){
		sscanf(english,"%s%s",Dic[cur].eng,Dic[cur].val);
		cur++;
	}
	qsort(Dic,cur,sizeof(Node),cmp);
	while(scanf("%s",foreign) != EOF){
		temp = NULL;
		temp = (Node *)bsearch(foreign,Dic,cur,sizeof(Node),Search);
		if(temp){
			cout << temp->eng << endl;
		}
		else{
			cout << "eh" << endl;
		}
	}
	return 0;
}