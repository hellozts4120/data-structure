#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 50005
using namespace std;

int n,k;
int father[MAX];
int ranks[MAX];
//father[A]=B,rank[A]=0��ʾA��Bͬ��;rank[A]=1��ʾB���Գ�A;rank[A]=2 ��ʾA���Գ�B

int Find(int x){
	if(father[x] == -1){
		return x;	//��ʱ���ĸ��ڵ㼴Ϊ���Լ�
	}
	int temp = father[x];
	father[x] = Find(father[x]);	//��ʱ�����ֱ�ӹҵ�root��;
	ranks[x] = (ranks[x] + ranks[temp]) % 3;
	return father[x];
}

bool Union(int X,int Y, int cases){
	int Xfather,Yfather;
	Xfather = Find(X);
	Yfather = Find(Y);
	if(Xfather == Yfather){		//���ߵ�fatherΪͬ��ʱ����ֱ�ӹ��ɵó����
		if((cases == 1) && (ranks[X] != ranks[Y])){
			return true;
		}
		if((cases == 2) && ((3+ranks[Y]-ranks[X])%3 != 1)){
			return true;
		}
		else return false;
	}
	else{		//���ߵ�fatherΪ��ͬ��ʱ����Ҫ��
		father[Yfather] = Xfather;
		ranks[Yfather] = (ranks[X] - ranks[Y] + cases + 2) % 3;
	}
	return false;
}


int main(){
	cin >> n >> k;
	int wrong = 0;
	memset(father,-1,sizeof(father));
	memset(ranks,0,sizeof(ranks));
	for(int i = 0;i < k;i++){
		int cases,X,Y;
		cin >> cases >> X >> Y;
		if((X>n) || (Y>n) || ((X==Y) && (cases == 2))){
			wrong++;
		}
		else if(Union(X,Y,cases)){
			wrong++;
		}
	}
	cout << wrong << endl;
	return 0;
}