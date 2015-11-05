/*	ʹ��Gauss��Ԫ����Ҫ��������Ϥ��	*/
#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 35;
int sta[MAX];
int ans[MAX];
int board[MAX][MAX];

int Gauss(int n){	//Gauss��Ԫ��������
	int row,col,max;
	row = 0;
	col = 0;
	while(row < n && col < n){
		max = row;
		for(int i = row; i < n; i++){
			if(board[i][col] > board[max][col]){
				max = i;
			}
		}
		if(!board[max][col]){
			col++;
			continue;
		}
		if(max != row){
			for(int i = col; i <= n; i++){
				int temp = board[row][i];
				board[row][i] = board[max][i];
				board[max][i] = temp;
			}
		}
		for(int i = row + 1; i < n; i++){
			if(board[i][col] == 0){
				continue;
			}
			for(int j = col; j <= n; j++){
				board[i][j] = (board[i][j] - board[row][j] + 2) % 2;	//�˹�ʽ��Ҫ
			}
		}
		row++;
		col++;
	}
	for(int i = row; i < n; i++){
		if(board[i][n]){	//�޽�
			return -1;
		}
	}
	if(row == n){	//ǡ����Ψһ��
		return 1;
	}
	else{
		return (1 << (n - row));
	}
}

int main(){
	int result;
	int n,cases;
	cin >> cases;
	while(cases--){
		memset(sta,0,sizeof(sta));	//3�����㣬��Ϊ��ȫ�ֱ������Ա����
		memset(ans,0,sizeof(ans));
		memset(board,0,sizeof(board));
		cin >> n;
		int x,y;
		for(int i = 0; i < n; i++){
			cin >> sta[i];
		}
		for(int i = 0; i < n; i++){
			cin >> ans[i];
		}
		while((cin >> x >> y) && (x || y)){
			board[y - 1][x - 1] = 1;
		}
		for(int i = 0; i < n; i++){
			board[i][i] = 1;
			board[i][n] = (ans[i] - sta[i] + 2) % 2;	//���һλ�Ǳ�ʾ���Է�������ĳ���������й����������״̬�ĸı����
		}
		int res = Gauss(n);
		if(res == -1){
			cout << "Oh,it's impossible~!!" << endl;
		}
		else{
			cout << res << endl;
		}
	}
	return 0;
}