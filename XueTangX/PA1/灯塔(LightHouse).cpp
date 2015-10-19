#include<stdio.h>

int x[4000005],y[4000005];
int L[4000005],R[4000005];
long result = 0;

void QuickSort(int num[],int num1[],int left,int right){
	int i = left,j = right;
	int temp = num[i];
	int temp1 = num1[i];
	while(i < j){
		while((num[j] > temp) && (j > i)){
			j--;
		}
		if(i < j){
			num[i] = num[j];
			num1[i] = num1[j];
			i++;
		}
		while((num[i] <= temp) && (j > i)){
			i++;
		}
		if(i < j){
			num[j] = num[i];
			num1[j] = num1[i];
			j--;
		}
	}
	num[i] = temp;
	num1[i] = temp1;
	if(left < i - 1){
		QuickSort(num,num1,left,i - 1);
	}
	if(i + 1 < right){
		QuickSort(num,num1,i + 1,right);
	}
}

void Merge(int left,int mid,int right){
	 int n1 = mid - left + 1;  
	 int n2 = right - mid;
	 for (int i = 0; i < n1; i++){  
		 L[i] = y[left + i];  
	 }  
	 for (int j = 0; j < n2; j++){  
		 R[j] = y[mid + j + 1];  
	 }  
	 L[n1] = 100000005;  
	 R[n2] = 100000005; 
	 int i = 0;
	 int j = 0;
	 for(int k = left; k <= right; k++){
		 if(L[i] > R[j]){
			 y[k] = R[j++];
		 }
		 else{
			 y[k] = L[i++];
			 result += (long(n2)) - j;
		 }
	 }
}

void Merge_Sort(int left,int right){
	int mid;
	if(left == right){
		return;
	}
	mid = left + ((right - left) >> 1);
	Merge_Sort(left,mid);
	Merge_Sort(mid + 1,right);
	Merge(left,mid,right);
}

int main(){
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
	setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	QuickSort(x,y,0,n - 1);
	Merge_Sort(0,n - 1);
	printf("%ld\n",result);
	return 0;
}
