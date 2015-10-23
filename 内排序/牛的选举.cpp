#include<iostream>
#include<cstdlib>
using namespace std;

struct Ox{
	int num;
	long ticket1,ticket2;
};

Ox AllOx[50005];

int cmp1(const void *a , const void *b){
	return ((Ox *)b)->ticket1 - ((Ox *)a)->ticket1;
}

int cmp2(const void *a , const void *b){
	return ((Ox *)b)->ticket2 - ((Ox *)a)->ticket2;
}

int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> AllOx[i].ticket1 >> AllOx[i].ticket2;
		AllOx[i].num = i + 1;
	}
	qsort(AllOx,n,sizeof(AllOx[0]),cmp1);
	qsort(AllOx,k,sizeof(AllOx[0]),cmp2);
	cout << AllOx[0].num << endl;
	return 0;
}