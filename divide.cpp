#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100		
int num1[MAX],num2[MAX],ans[MAX],tempnum2[MAX],long1,long2,MAXLONG;
char str2[MAX + 1],str1[MAX + 1],nose[MAX];

int substract(int maxlong,int *num1,int *num2)	//maxlongΪ���������нϳ������ĳ��ȣ����豣֤num1 >= num2;
{													//������߷�0λ��λ��
	int i;
	int highestpos = 0;
	for(i = 0;i < maxlong;i++){
		num1[i] -= num2[i];
		if(num1[i] < 0){
			num1[i] += 10;
			num1[i + 1]--;
		}
		if(num1[i]){highestpos = i;}
	}
	return highestpos;
}

int *maxcompare(int maxlong,int *num1,int *num2)	//�Ƚ����������Ƿ�num1�ϴ�
{
	int i;
	bool bothzero = true;
	for(i = maxlong -1;i >= 0;i--){
		if(num1[i] > num2[i]){return num1;}
		else if(num1[i] < num2[i]){return num2;}
		else if(num1[i]){bothzero = false;}
	}
	if(bothzero){return NULL;}
	return num1;
}

int length(int maxlong,int *a)	//��������ĳ���
{
	int i;
	for(i = maxlong - 1;a[i] == 0 && i >= 0;i--){
		if(i >= 0){
			return (i+1);
		}
	}
		return 0;
}

void shift(int maxlong,int *num1,int *num2,int n)		//��������num1����nλ������10��n�η����������num2
{
	int i;
	memcpy(num2,num1,maxlong * sizeof(int));
	if(n <= 0){
		return;
	}
	for(i = maxlong - 1;i >= 0;i--){
		if(i >= n){
			num2[i] = num1[i - n];
		}
		else{num2[i] = 0;}
	}
}


int main()
{
	int n,i,j,highest;
	memset(ans,0,sizeof(ans));
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));	//��num1,num2,abs����λ����ʼ������0��
	scanf("%d",&n);
	//gets(nose);
	while(n--){
		scanf("%s",str1);
		scanf("%s",str2);
		long1 = strlen(str1);
	for(i = 0,j = long1 - 1;j >= 0;j--,i++){		//���г˷��ǴӺ�λ��ǰλ�˵�
		num1[i] = str1[j] - '0';
	}
	long2 = strlen(str2);
	for(i = 0,j = long2 - 1;j >= 0;j--,i++){		//���г˷��ǴӺ�λ��ǰλ�˵�
		num2[i] = str2[j] - '0';
	}
	if(long1 >= long2){MAXLONG = long1;}
	if(long1 < long2){MAXLONG = long2;}
	highest = 0;
	int shiftlong = length(MAX,num1) - length(MAX,num2);
	while(maxcompare(MAX,num1,num2) == num1){
		shift(MAX,num2,tempnum2,shiftlong);
		while(maxcompare(MAX,num1,tempnum2) == num1){
			substract(MAXLONG,num1,tempnum2);
			ans[shiftlong]++;
		}
		if(highest == 0 && ans[shiftlong]){
			highest = shiftlong;
		}
		shiftlong--;
	}
	for(i = highest;i >= 0;i--){
		printf("%d",ans[i]);
	}
	printf("\n");
	}
	system("pause");
}
