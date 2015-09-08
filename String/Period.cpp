#include<iostream>
#include<cstring>
using namespace std;

char str[1000001];
int Next[1000001];

void getnext(){
	int i = 0,j = -1;
	Next[0] = j;
	int len = strlen(str);
	while(i < len){
		if(str[i] == str[j] || j == -1){
			i++;
			j++;
			Next[i] = j;	//若此两位匹配成功，则均前进一位，同时Next[i] = j;
		}
		else j = Next[j];	//匹配不成功，则返回至第Next[j]位匹配
	}
}

int main()
{
	int time = 1;
	int len,length;
	while(scanf("%d",&len) && len){
		scanf("%s",str);
		getnext();
		printf("Test case #%d\n",time);
		for(int i = 1;i <= len;i++){
			length = i - Next[i];	//循环节的长度
			if((i != length) && (i % length == 0)){//若有多个循环
				printf("%d %d\n",i,i / length);
			}
		}
		printf("\n");
		time++;
	}
	return 0;
}

