#include<cstdio>
#include<iostream>
using namespace std;
int str1[1001],str2[1001];

void Search(int Left,int Right,int n){
	if(n == 1){
		printf("%d ",str1[Left]);
		return;
	}
	else if(n <= 0){
		return;
	}
	else{
		int i;
		for(i = 0;str1[Left] != str2[Right + i];i++);
		Search(Left + 1,Right,i);
		Search(Left + i + 1,Right + i + 1,n - i - 1);
		printf("%d ",str1[Left]);
	}
}

int main()
{
	int n,i;
	while(scanf("%d",&n) > 0){
		if(n <= 0){
			break;
		}
		for(i = 1;i <= n;i++){
			scanf("%d",&str1[i]);
		}
		for(i = 1;i <= n;i++){
			scanf("%d",&str2[i]);
		}
		Search(1,1,n);
		printf("\n");
	}
	return 0;
}