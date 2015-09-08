#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;		//using KMP;

int Next[1000001];
char str[1000001];

void getnext(){
	int i = 0,j = -1;
	Next[0] = j;
	int len = strlen(str);
	while(i < len){
		if(str[i] == str[j] || j == -1){
			i++;
			j++;
			Next[i] = j;
		}
		else{
			j = Next[j];
		}
	}
}

int main()
{
	while(scanf("%s",str)){
		int len = strlen(str);
		if(str[0] == '.'){
			break;
		}
		getnext();
		if(len % (len - Next[len]) == 0){
			printf("%d\n",len / (len - Next[len]));
		}
		else
			printf("1\n");
	}
	return 0;
}


