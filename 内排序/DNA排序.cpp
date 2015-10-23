#include<iostream>
#include<cstdlib>
using namespace std;

char L[50],R[50];

struct DNA{
	char str[50];
	int ReverseNum;
}AllDNA[100];

int cmp(const void *a , const void *b){
	return ((DNA *)a)->ReverseNum - ((DNA *)b)->ReverseNum;
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> AllDNA[i].str;
		AllDNA[i].ReverseNum = 0;
		for(int j = 0; j < n - 1; j++){
			if(AllDNA[i].str[j] == 'A'){
				continue;
			}
			for(int k = j + 1; k < n; k++){
				if(AllDNA[i].str[j] > AllDNA[i].str[k]){
					AllDNA[i].ReverseNum++;
				}
			}
		}
	}
	qsort(AllDNA,m,sizeof(AllDNA[0]),cmp);
	for(int i = 0; i < m; i++){
		cout << AllDNA[i].str << endl;
	}
	return 0;
}