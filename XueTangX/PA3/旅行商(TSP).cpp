#include<cstdio>

const int MAX = 1000010;
int VisitNum = 1;		//至少有起始的第一个村庄

class Stack{
private:
	int top;
	int elem[MAX];
	int Size;
public:
	Stack(){
		top = -1;
	};
	void push(int i){
		elem[++top] = i;
	}
	void pop(){
		--top;
	}
	int Top(){
		return elem[top];
	}
	bool empty(){
		return (top < 0);
	}
};

Stack S;

struct Edge{
	int direction;
	Edge *nextEdge;
};

struct VertexNode{
	int data;
	int InDegree;
	int VillageNum;
	Edge *FirstEdge;
};

struct Matrix{
	VertexNode Nodes[MAX];
	int VertexNum;
	int EdgeNum;
}AdjacentMatrix;

void CreateMatrix(){
	int n,m;
	scanf("%d%d",&n,&m);
	AdjacentMatrix.EdgeNum = m;
	AdjacentMatrix.VertexNum = n;
	for(int i = 1; i <= n; i++){		//init village, all isolated
		AdjacentMatrix.Nodes[i].data = i;
		AdjacentMatrix.Nodes[i].VillageNum = 1;
		AdjacentMatrix.Nodes[i].InDegree = 0;
		AdjacentMatrix.Nodes[i].FirstEdge = NULL;
	}
	for(int i = 1; i <= m; i++){		//init road;
		int start,end;
		scanf("%d%d",&start,&end);
		Edge *temp = new Edge;
		temp->direction = end;
		temp->nextEdge = AdjacentMatrix.Nodes[start].FirstEdge;
		AdjacentMatrix.Nodes[end].InDegree++;
		AdjacentMatrix.Nodes[start].FirstEdge = temp;
	}
}

void TopSort(){
	//printf("fuck");
	Edge *temp = NULL;
	for(int i = 1; i <= AdjacentMatrix.VertexNum; i++){
		if(!AdjacentMatrix.Nodes[i].InDegree){
			S.push(AdjacentMatrix.Nodes[i].data);
		}
	}
	while(!S.empty()){
		int cur = S.Top();
		S.pop();
		temp = AdjacentMatrix.Nodes[cur].FirstEdge;
		while(temp != NULL){
			if((--AdjacentMatrix.Nodes[temp->direction].InDegree) == 0){
				S.push(temp->direction);
			}
			if(AdjacentMatrix.Nodes[cur].VillageNum >= AdjacentMatrix.Nodes[temp->direction].VillageNum){
				AdjacentMatrix.Nodes[temp->direction].VillageNum = AdjacentMatrix.Nodes[cur].VillageNum + 1;
			}
			if(VisitNum <= AdjacentMatrix.Nodes[temp->direction].VillageNum){
				VisitNum = AdjacentMatrix.Nodes[temp->direction].VillageNum;
			}
			temp = temp->nextEdge;
		}
	}
}

int main(){
	CreateMatrix();
	//printf("fuck");
	TopSort();
	printf("%d\n",VisitNum);
	return 0;
}