#include<stdio.h>
#include<string.h>
int num[500005];

void QuickSort(int num[],int left,int right){	//快速排序的地方本人思路不清楚，因此有部分参考
	int i = left,j = right;
	int temp = num[i];
	while(i < j){
		while((num[j] > temp) && (j > i)){
			j--;
		}
		if(i < j){
			num[i] = num[j];
			i++;
		}
		while((num[i] <= temp) && (j > i)){
			i++;
		}
		if(i < j){
			num[j] = num[i];
			j--;
		}
	}
	num[i] = temp;
	if(left < i - 1){
		QuickSort(num,left,i - 1);
	}
	if(i + 1 < right){
		QuickSort(num,i + 1,right);
	}
}

int Binary_Search(int num[],int a,int n){
	int left = 0,right = n,mid;
	while(left <= right){
		mid = left + ((right - left) >> 1);
		if(num[mid] >= a){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return left;
}

void GetAnswer(int num[],int min,int max,int n){
	int min0,max0;
	min0 = Binary_Search(num,min,n - 1);
	max0 = Binary_Search(num,max,n - 1);
	if(num[max0] == max){
		printf("%d\n",max0 - min0 + 1);
	}
	else{
		printf("%d\n",max0 - min0);
	}
}

int main(){
	int n,m;
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&num[i]);
	}
	QuickSort(num,0,n - 1);
	for(int i = 0; i < m; i++){
		scanf("%d%d",&a,&b);
		GetAnswer(num,a,b,n);
	}
	return 0;
}