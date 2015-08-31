#include<cstdio>
#include<cstring>


int main()
{
	int i,j,n,num;
	char str[20][100];
	scanf("%d",&n);
	getchar();
	num = n;
	for(i = 0;i < n;i++){
		gets(str[i]);
		for(j = 0;str[i][j] != '\0';j++){
			if((str[i][j] >= 'a' && str[i][j] <= 'z') || (str[i][j] >= 'A' && str[i][j] <= 'Z')){
				str[i][j] += 1;
			}
			else if(str[i][j] == 'z'){str[i][j] == 'a';}
			else if(str[i][j] == 'Z'){str[i][j] == 'A';}
		}
	}
	for(i = 0;i < n;i++){
		printf("%s\n",str[i]);
	}
}