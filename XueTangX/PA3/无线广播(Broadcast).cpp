#include<cstdio>

const int MAX = 10010;
int n,m;

class Queue{
private:
	int elem[MAX];
	int Size;
	int head,tail;
public:
	Queue(){
		Size = MAX;
		head = 1;
		tail = 0;
	};
	void enqueue(int i){
		elem[++tail] = i;
	}
	void dequeue(){
		head++;
	}
	bool empty(){
		return (head > tail);
	}
	int front(){
		return elem[head];
	}
	int back(){
		return elem[tail];
	}
};

Queue Q;

struct Edge{
	int direction;
	Edge *nextEdge;
};

struct VertexNode{
	int data;
	Edge *FirstEdge;
	VertexNode(){
		data = 0;
		FirstEdge = NULL;
	};
};

struct Matrix{
	VertexNode Nodes[MAX];
	int Size;
}AdjacentMatrix;

void CreatePath(int start, int end){
	Edge *temp = new Edge;
	temp->direction = end;
	temp->nextEdge = AdjacentMatrix.Nodes[start].FirstEdge;
	AdjacentMatrix.Nodes[start].FirstEdge = temp;
}

int BFS(int n){
	for(int i = 1; i <= n; i++){
		if(!AdjacentMatrix.Nodes[i].data){
			int t = 1;
			int temp;
			int to;
			AdjacentMatrix.Nodes[i].data = 1;
			Q.enqueue(i);
			while(!Q.empty()){
				temp = Q.front();
				Edge *q = AdjacentMatrix.Nodes[temp].FirstEdge;
				if(AdjacentMatrix.Nodes[temp].FirstEdge){
					to = q->direction;
					while(q != NULL){
						if(AdjacentMatrix.Nodes[to].data == 0){
							AdjacentMatrix.Nodes[to].data = AdjacentMatrix.Nodes[temp].data * (-1);
							Q.enqueue(to);
						}
						else if(AdjacentMatrix.Nodes[to].data == AdjacentMatrix.Nodes[temp].data){
							t = -1;
							break;
						}
						q = q->nextEdge;
						if(q != NULL){
							to = q->direction;
						}
					}
				}
				Q.dequeue();
			}
			if(t == -1){
				return -1;
			}
			while(!Q.empty()){
				Q.dequeue();
			}
		}
	}
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	AdjacentMatrix.Size = n;
	for(int i = 0; i < m; i++){
		int start,end;
		scanf("%d%d",&start,&end);
		CreatePath(start,end);
		CreatePath(end,start);
	}
	int ans = BFS(n);
	printf("%d\n",ans);
	return 0;
}