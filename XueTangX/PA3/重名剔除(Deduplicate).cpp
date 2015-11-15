#include<cstdio>
#include<cstring>

const int MAX = 600010;

struct Node{
	char name[41];
	Node *next;
	bool IsHave;
	Node(){
		name[0] = '\0';
		next = NULL;
		IsHave = false;
	}
};

class HashNode{
private:
	Node *head;
public:
	HashNode(){
		head = new Node;
	};
	void AddNode(Node *temp){
		temp->next = head->next;
		head->next = temp;
	}
	Node *IsAleadyHave(Node *temp){
		Node *p = new Node;
		for(p = head; p->next != NULL; p = p->next){
			if(strcmp(p->next->name,temp->name) == 0){
				return p->next;
			}
		}
		return NULL;
	}
};

HashNode FoodList[MAX];

/*int CalHash(char food[]){
	int count = 0;
	for(int i = 0; food[i]; i++){
		count += food[i] - 'a';
	}
	return count;
}*/

int CalHash(char food[]){
	int nHash = 0;
	for(int i = 0; food[i]; i++){
		nHash ^= (nHash << 5)|(nHash >> 27) + food[i];
	}
	if(nHash < 0){
		nHash = -nHash;
	}
	return (nHash % 350899);
}

int main(){
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
	setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
	int n,key;
	char food[41];
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%s",food);
		key = CalHash(food);
		Node *temp = new Node;
		strcpy(temp->name,food);
		Node *temp1 = FoodList[key].IsAleadyHave(temp);
		if(temp1 == NULL){
			FoodList[key].AddNode(temp);
		}
		else{
			if(temp1->IsHave == false){
				printf("%s\n",temp->name);
				temp1->IsHave = true;
			}
		}
	}
	return 0;
}

