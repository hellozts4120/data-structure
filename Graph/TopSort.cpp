#include<iostream>
#include<cstring>
using namespace std;

struct GraphNode{
	int sonNum;
	int farNum;
	int Son[100];
};

bool Visited[100];

int main(){
	GraphNode v[100];
	memset(v,0,sizeof(v));
	memset(Visited,false,sizeof(Visited));
	int V,A;
	int from,to;
	cin >> V >> A;
	for(int i = 0; i < A; i++){
		cin >> from >> to;
		v[from].Son[v[from].sonNum] = to;
		v[from].sonNum++;
		v[to].farNum++;
	}
	int vNum = 0;
	while(vNum < V){
		for(int i = 1; i <= V; i++){
			if(v[i].farNum == 0 && !Visited[i]){
				cout << "v" << i << " ";
				Visited[i] = true;
			}
			else{
				continue;
			}
			for(int j = 0; j < v[i].sonNum; j++){
				v[v[i].Son[j]].farNum--;
			}
			vNum++;
			break;
		}
	}
	cout << endl;
	return 0;
}