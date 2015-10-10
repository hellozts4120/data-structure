#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,int> vertex_index;
map<int,string> index_vertex;

const int MAXP = 40,INFINITE = 100000;
int Dist[MAXP][MAXP];	//记录两点最短距离
int Pre[MAXP][MAXP];	//prev[x][y]：若x-->y已是最短距离，此值为x；若通过中继u，x-->u-->y更短，此值为u。总之，储存y的前驱顶点。

void InitDist(int v){	//初始状态，图中都是孤立的点，没有边；自己到自己的距离为0，到其他点的距离为无穷大。
	for(int i = 0;i < v;i++){
		for(int j = 0;j < v;j++){
			if(i != j){
				Dist[i][j] = INFINITE;
			}
			else{
				Dist[i][j] = 0;
			}
		}
	}
}

void InitPre(int v){
	for(int i = 0;i < v;i++){
		for(int j = 0;j < v;j++){
			Pre[i][j] = -1;
		}
	}
}

void BuildPath(string from, string to, int dist){
	int i,j;
	i = vertex_index[from];
	j = vertex_index[to];
	if(Dist[i][j] > dist){
		Dist[i][j] = dist;
		Dist[j][i] = dist;
		Pre[i][j] = i;
		Pre[j][i] = j;
	}
}

void Floyd(int v){	//use Floyd Algorithm
	for(int k = 0;k < v;k++){
		for(int i = 0;i < v;i++){
			for(int j = 0;j < v;j++){
				if(Dist[i][j] > (Dist[i][k] + Dist[k][j])){
					Dist[i][j] = (Dist[i][k] + Dist[k][j]);
					Pre[i][j] = Pre[k][j];
				}
			}
		}
	}
}

void GetRoute(int i,int j){	//Get Route;
	if(i == j){
		cout << index_vertex[i];
		return;
	}
	GetRoute(i,Pre[i][j]);
	cout<<"->"<<'('<<Dist[Pre[i][j]][j]<<')'<<"->"<<index_vertex[j];
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("fuck.txt", "w", stdout);
	int p,q,r;
	string from,to;
	int dist;
	cin >> p;
	InitDist(p);
	InitPre(p);
	for(int i = 0;i < p;i++){
		cin >> from;
		vertex_index.insert(pair<string,int>(from,i));
		index_vertex.insert(pair<int,string>(i,from));
	}
	cin >> q;
	for(int i = 0;i < q;i++){
		cin >> from >> to >> dist;
		BuildPath(from,to,dist);
	}
	Floyd(p);
	cin >> r;
	for(int i = 0;i < r;i++){
		cin >> from >> to;
		GetRoute(vertex_index[from],vertex_index[to]);
		cout << endl;
	}
	return 0;
}