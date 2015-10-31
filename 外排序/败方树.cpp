#include<iostream>
using namespace std;

int Loser[1000];
int Tree[1000];
int ChangeNum[1000],ChangeValue[1000];
int CurMan;
int n,m;

void Play(int i){
	int parent = (i + n)/2;
	while(parent > 0){
		if(Loser[i] > Loser[Tree[parent]]){
			int temp = Tree[parent];
			Tree[parent] = i;
			i = temp;
		}
		parent /= 2;
	}
	Tree[0] = i;
}

void Rebuild(int i){
	int parent = (i + n)/2;
	while(parent > 0){
		if(Loser[i] > Loser[Tree[parent]]){
			int temp = Tree[parent];
			Tree[parent] = i;
			i = temp;
		}
		Tree[0] = i;
		parent /= 2;
	}
	Tree[0] = i;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> Loser[i];
		Tree[i] = n;
	}
	for(int i = 0; i < m; i++){
		cin >> ChangeNum[i] >> ChangeValue[i];
	}
	for(int i = n - 1; i >= 0; i--){
		Play(i);
	}
	for(int i = 0; i < n; i++){
		cout << Loser[Tree[i]] << " ";
	}
	cout << endl;
	for(int i = 0; i < m; i++){
		Loser[ChangeNum[i]] = ChangeValue[i];
		Rebuild(ChangeNum[i]);
		for(int j = 0; j < n; j++){
			cout << Loser[Tree[j]] << " ";
		}
		cout << endl;
	}
	return 0;
}