#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int M,N;
	int Num[500];
	int OutPut[500];
	int i,j,status,numleft;
	cin >> N >> M;
	numleft = N;
	status = 0;
	i = 0;
	j = 0;
	memset(Num,0,sizeof(Num));
	while(numleft > 0){
		if(Num[i] == 0){
			status++;
			if(status % (M + 1) ==0){
				Num[i] = 1;
				OutPut[j] = i + 1;
				j++;
				status = 0;
				numleft--;
			}
		}
		if(i < N - 1){
			i++;
		}
		else
			i = 0;
	}
	for(i = 0;i < j;i++){
		cout << OutPut[i] << " ";
	}
	cout << endl;
	return 0;
}