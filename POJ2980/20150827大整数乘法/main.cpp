#include<stdio.h>
#include<string.h>
#define MAX 200		

int main()
{
	char str[MAX + 1];
	int num1[MAX],num2[MAX],ans[MAX * 2],i,j,n,long1,long2,upgrade,highest = 0;
	for(i = 0;i < MAX * 2;i++){
		ans[i] = 0;
	}
	scanf("%s",str);
	long1 = strlen(str);
	for(i = 0,j = long1 - 1;j >= 0;j--,i++){		//阵列乘法是从后位向前位乘的
		num1[i] = str[j] - '0';
	}
	scanf("%s",str);
	long2 = strlen(str);
	for(i = 0,j = long2 - 1;j >= 0;j--,i++){
		num2[i] = str[j] - '0';
	}
	for(i = 0;i < long2;i++){
		for(j = 0; j < long1;j++){		//A的第i位和B的第j位相乘结果一定出现在第i + j位
			ans[i + j] += num2[i] * num1[j];
		}
	}
	upgrade = 0;
	for(n = 0;n < i + j;n++){
		if(ans[n] >= 10){
			upgrade = ans[n] / 10;
			ans[n + 1] += upgrade;
			ans[n] = ans[n] % 10;
		}
		if(ans[n]){highest = n;}
	}
	for(i = highest;i >= 0;i--){
		printf("%d",ans[i]);
	}
}





