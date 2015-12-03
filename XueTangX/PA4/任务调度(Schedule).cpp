#include<cstdio>
#include<cstring>

const int MAX = 5000010;

struct Heap{
	long long priority;
	char num[10];
	bool operator < (const Heap &a){
		if(priority < a.priority){
			return true;
		}
		else if(priority == a.priority){
			int i = 0;
			while(num[i] == a.num[i]){
				i++;
			}
			if(num[i] < a.num[i]){
				return true;
			}
		}
		return false;
	}
}Task[MAX];

void PercolateDown(int n, int index){
	Heap temp = Task[index];
	int num = index;
	int child;
	while((num<<1) + 1 < n){
		child = (num<<1) + 1;
		if(child < n-1 && Task[child+1] < Task[child]){
			child++;
		}
		if(Task[child] < temp){
			Task[num] = Task[child];
		}
		else{
			break;
		}
		num = child;
	}
	Task[num] = temp;
}

void BuildHeap(int n, Heap *task){
	for(int i = ((n-1)>>1); i>=0 && i<n; i--){
		PercolateDown(n,i);
	}
}

int main(){
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
	setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
	int m,n;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%lld %s",&Task[i].priority,Task[i].num);
	}
	BuildHeap(n,Task);
	int size = n;
	for(int i = 0; (i < m) && (size); i++){
		printf("%s\n",Task[0].num);
		Task[0].priority *= 2;
		if(Task[0].priority >= 4294967296){
			Heap temp = Task[0];
			Task[0] = Task[size-1];
			Task[size-1] = temp;
			size--;
		}
		PercolateDown(size,0);
	}
	return 0;
}