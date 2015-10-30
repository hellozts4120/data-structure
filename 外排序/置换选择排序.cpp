#include<iostream>
using namespace std;

int InitLen[100];
int Heap[100];
int Out[100];
int n1,n2;

void SiftDown(int x){
	int temp = Heap[x];
	int child;
	for(;x*2 < n2;x = child){
		child = x * 2 + 1;
		if(child < n2 && Heap[child + 1] < Heap[child]){
			child++;
		}
		if(Heap[child] < temp){
			Heap[x] = Heap[child];
		}
		else{
			break;
		}
	}
	Heap[x] = temp;
}

int main(){
	cin >> n1 >> n2;
	for(int i = 0; i < n1; i++){
		cin >> InitLen[i];
	}
	for(int i = 0; i < n2; i++){
		cin >> Heap[i];
	}
	int cur = 0;
	for(int i = 0; i < n1; i++){
		if(i == 0){
			Out[cur] = Heap[0];
			continue;
		}
		if(InitLen[i] > Out[cur]){
			Heap[0] = InitLen[i];
		}
		else{
			Heap[0] = Heap[n2 - 1];
			--n2;
			if(!n2){
				break;
			}
		}
		SiftDown(0);
		if(Heap[0] != Out[cur]){
			Out[++cur] = Heap[0];
		}
	}
	for(int i = 0; i <= cur; i++){
		cout << Out[i] << " ";
	}
	cout << endl;
	return 0;
}