#include<stdio.h>
#include<string.h>
#define MAX 100		
int num1[MAX],num2[MAX],abs[MAX],long1,long2,maxlong;
char str2[MAX + 1],str1[MAX + 1];

int substract(int maxlong,int num1[],int num2[])	//maxlongΪ���������нϳ������ĳ��ȣ����豣֤num1 >= num2;
{													//������߷�0λ��λ��
	int i,j;
	int highestpos;
	for(i = 0;i < maxlong;i++){
		num1[i] -= num2[i]
		if(num1[i] < 0){
			num1[i] += 10;
			num1[i + 1]--;
		}
		if(num1[i]){highestpos = i;}
	}
	return highestpos;
}

bool maxcompare(int maxlong,int num1[],int num2[])	//�Ƚ����������Ƿ�num1�ϴ�
{
	int i;
	bool bothzero = true;
	for(i = maxlong -1;i >= 0;i++){
		if(num1[i] > num2[i]){return true;}
		else if(num1[i] < num2[i]){return false;}
		else if(num1[i]){bothzero = false;}
	}
	if(bothzero){return false;}
	return true;
}

int length(??)	//��������ĳ���
{


void shift(int maxlong,int num1[],int num2[],int n)		//��������num1����nλ������10��n�η����������num2
{
	int i;
	if(n <= 0){return;}
	for(i = maxlong - 1;i >= 0;i++){


int main()
{
	int n,i,j,highest;
	scanf("%d",&n);
	while(n--){
		gets(str1);
		gets(str2);
		long1 = strlen(str1);
	for(i = 0,j = long1 - 1;j >= 0;j--,i++){		//���г˷��ǴӺ�λ��ǰλ�˵�
		num1[i] = str1[j] - '0';
	}
	long2 = strlen(str2);
	for(i = 0,j = long2 - 1;j >= 0;j--,i++){		//���г˷��ǴӺ�λ��ǰλ�˵�
		num2[i] = str2[j] - '0';
	}
	highest = 0;
	if(long1 > long2){maxlong = long1;}
	else{maxlong = l2;}
