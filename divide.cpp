#include<stdio.h>
#include<string.h>
#define MAX 100		
int num1[MAX],num2[MAX],abs[MAX],long1,long2,maxlong;
char str2[MAX + 1],str1[MAX + 1];

int substract(int maxlong,int num1[],int num2[])	//maxlong为两大整数中较长整数的长度，且需保证num1 >= num2;
{													//返回最高非0位的位置
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

bool maxcompare(int maxlong,int num1[],int num2[])	//比较两个数中是否num1较大
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

int length(??)	//求大整数的长度
{


void shift(int maxlong,int num1[],int num2[],int n)		//将大整数num1左移n位，即乘10的n次方，结果放入num2
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
	for(i = 0,j = long1 - 1;j >= 0;j--,i++){		//阵列乘法是从后位向前位乘的
		num1[i] = str1[j] - '0';
	}
	long2 = strlen(str2);
	for(i = 0,j = long2 - 1;j >= 0;j--,i++){		//阵列乘法是从后位向前位乘的
		num2[i] = str2[j] - '0';
	}
	highest = 0;
	if(long1 > long2){maxlong = long1;}
	else{maxlong = l2;}
