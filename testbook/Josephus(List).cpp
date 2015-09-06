#include<cstdio>
#include<iostream>
#include<List>
using namespace std;

int main()
{
	int M,N;
	int i,j,mprime,numleft;
	list<int>L;
	list<int>::iterator iter;
	cin >> N >> M;
	numleft = N;
	mprime = M % N;
	for(i = 1; i <= N;i++){
		L.push_back(i);
	}
	iter = L.begin();
	for(i = 0;i < N;i++){
		mprime = mprime % numleft;
		if(mprime <= numleft / 2){
			for(j = 0;j < mprime;j++){
				iter++;
				if(iter == L.end()){
					iter = L.begin();
				}
			}
		}
		else
			for(j = 0;j < mprime / 2;j++){
				if(iter == L.begin()){
					iter = --L.end();
				}
				else
					iter--;
			}
			cout << *iter << " ";
			iter = L.erase(iter);
			if(iter == L.end()){
				iter = L.begin();
			}
	}

	cout << endl;
	return 0;
}