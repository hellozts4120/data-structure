#include<cstdio>
#include<iostream>
using namespace std;	//��С�ѽṹ�У�������value��Զ����С��
int heap[100001];		//�ѽṹ��û�����պã�Ҫ��ѵ����
int curSize;

void percolateDown(int hole){
	int child;
	int tmp = heap[hole];
	for(;hole * 2 <= curSize;hole = child){
		child = hole * 2;
		if(child != curSize && heap[child + 1] < heap[child]){	//�ȵ�ǰ��㻹С�Ļ�����
			child++;
		}
		if(heap[child] < tmp){
			heap[hole] = heap[child];
		}
		else break;
	}
	heap[hole] = tmp;
}

void insert(int x){
	heap[++curSize] = x;
	int hole = curSize;
	int tmpNum = heap[hole];
	for(;(hole > 1) && (tmpNum < heap[hole / 2]);hole /= 2){
		heap[hole] = heap[hole / 2];
	}
	heap[hole] = x;
}

void removeMin(){
	if(curSize == 0){
		return;
	}
	printf("%d\n",heap[1]);
	heap[1] = heap[curSize--];
	percolateDown(1);
}

int main(){
	int time;
	cin >> time;
	while(time--){
		curSize = 0;
		int n;
		int flag;
		cin >> n;
		for(int i = 0;i < n;i++){
			scanf("%d",&flag);
			if(flag == 1){
				int insertNum;
				scanf("%d",&insertNum);
				insert(insertNum);
			}
			else if(flag == 2){
				removeMin();
			}
			else break;
		}
	}
	return 0;
}