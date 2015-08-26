#include<stdio.h>
void main()
{
	int m,n,monkey[300],i;
	int index,pos,left;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		monkey[i] = 1;
	}
	left = n;
	index = 0;
	i = 0;
	while(left > 0){
		if(monkey[i] > 0){
			index++;
			if(index % m == 0){
				monkey[i] = 0;
				pos = i;
				index = 0;
				left--;
			}
		}
		if(i < n-1){i++;}
		else{i = 0;}
	}
	printf("%d",pos+1);
}
	


