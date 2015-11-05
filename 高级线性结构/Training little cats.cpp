/*	矩阵连乘	*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX = 105;
long long board[MAX][MAX];
long long board_1[MAX][MAX];
long long board_2[MAX][MAX];

void Multiply(long long a[MAX][MAX],long long b[MAX][MAX],int n){	//矩阵的幂乘实现
	memset(board_2,0,sizeof(board_2));
	for(int i = 1; i <= n+1; i++){
		for(int j = 1; j <= n+1; j++){
			if(a[i][j]){				//稀疏矩阵的加速幂运算
				for(int k = 1; k <= n+1; k++){
					if(b[j][k]){
						board_2[i][k] += a[i][j] * b[j][k];
					}
				}
			}
		}
	}
	for(int i = 1; i <= n+1; i++){
		for(int j = 1; j <= n+1; j++){
			b[i][j] = board_2[i][j];
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("outt.txt","w",stdout);
	int m,n,k;
	while(cin >> n >> m >> k){
		char cur;
		int temp;
		if(!n && !m && !k){
			break;
		}
		memset(board,0,sizeof(board));
		memset(board_1,0,sizeof(board_1));
		for(int i = 1; i <= n+1; i++){
			board[i][i] = 1;
			board_1[i][i] = 1;
		}
		for(int i = 0; i < k; i++){
			cin >> cur;
			getchar();
			if(cur == 'g'){
				cin >> temp;
				board[temp][n+1]++;
			}
			if(cur == 'e'){
				cin >> temp;
				for(int j = 1; j <= n+1; j++){
					board[temp][j] = 0;
				}
			}
			if(cur == 's'){
				int temp1;
				cin >> temp >> temp1;
				for(int j = 1; j <= n+1; j++){
					int x;
					x = board[temp][j];
					board[temp][j] = board[temp1][j];
					board[temp1][j] = x;
				}
			}
		}
		while(m){
			if(m & 1){
				Multiply(board,board_1,n);
			}
			Multiply(board,board,n);
			m >>= 1;
		}
		for(int i = 1; i <= n; i++){
			cout << board_1[i][n+1] << " ";
		}
		cout << endl;
	}
	return 0;
}