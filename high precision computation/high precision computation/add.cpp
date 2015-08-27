#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX 200

int main()
{
	char str[MAX + 1];
	int num1[MAX + 1],num2[MAX + 1],ans[MAX+1],long1,long2,i,j,highest = 0,maxhigh;
	for(i = 0;i < MAX + 1;i++){
		ans[i] = 0;
		num1[i] = 0;
		num2[i] = 0;
	}
	scanf("%s",str);
	long1 = strlen(str);
	for(i = 0,j = long1 - 1;j >= 0;j--,i++){
		num1[i] = str[j] - '0';
	}
	scanf("%s",str);
	long2 = strlen(str);
	for(i = 0,j = long2 - 1;j >= 0;j--,i++){
		num2[i] = str[j] - '0';
	}
	if(long1 > long2){maxhigh = long1;}
	else {maxhigh = long2;}
	for(i = 0;i < maxhigh;i++){
		ans[i] = ans[i]+ num1[i] + num2[i];
	}
	for(j = 0;j < maxhigh;j++){
		if(ans[j] >= 10){
			ans[j + 1] += 1;
			ans[j] = ans[j] % 10;
		}
		if(ans[j]){highest = i;}
	}
	for(i = highest - 1;i >= 0;i--){
		printf("%d",ans[i]);
	}
	system("pause");
}

