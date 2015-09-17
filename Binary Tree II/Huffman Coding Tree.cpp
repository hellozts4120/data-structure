#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 200;

struct HuffmanNode{
	int value;
	int left,right,parent;
}HuffmanNodes[MAX];

int MovingTree(int index,int depth){
	int sum = 0;
	int child = 0;
	if(HuffmanNodes[index - 1].left){
		sum += MovingTree(HuffmanNodes[index - 1].left,depth + 1);
		child++;
	}
	if(HuffmanNodes[index - 1].right){
		sum += MovingTree(HuffmanNodes[index - 1].right,depth + 1);
		child++;
	}
	if(child == 0){
		sum = HuffmanNodes[index - 1].value * depth;
	}
	return sum;
}

int main(){
	int weight;
	int result = 0;
	int n;
	cin >> n;
	memset(HuffmanNodes,0,sizeof(HuffmanNodes));
	for(int i = 0;i < n;i++){
		cin >> weight;
		HuffmanNodes[i].value = weight;
	}
	for(int i = n;i < n * 2 - 1;i++){
		int min1 = 100000, min2 = 100000;
		int minIndex1 = -1, minIndex2 = -1;
		for(int j = 0;j < i;j++){
			if(HuffmanNodes[j].parent){
				continue;
			}
			if(HuffmanNodes[j].value < min1){
				min2 = min1;
				minIndex2 = minIndex1;
				min1 = HuffmanNodes[j].value;
				minIndex1 = j;
			}
			else if(HuffmanNodes[j].value < min2){
				min2 = HuffmanNodes[j].value;
				minIndex2 = j;
			}
		}
		HuffmanNodes[minIndex1].parent = i;
		HuffmanNodes[minIndex2].parent = i;
		HuffmanNodes[i].value = min1 + min2;
		HuffmanNodes[i].left = minIndex1 + 1;
		HuffmanNodes[i].right = minIndex2 + 1;
	}
	for(int i = 0;i < n * 2 - 1;i++){
		if(!HuffmanNodes[i].parent){
			result = MovingTree(i + 1,0);
			break;
		}
	}
	cout << result << endl;
	return 0;
}