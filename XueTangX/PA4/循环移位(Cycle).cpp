#include<cstdio>
#include<cstring>

const int MAX = 200010;
int Next[MAX];
char str1[MAX],str2[MAX];

int KMP(int n1, int n2){
	int i = 0, j = 0;
	for(; j < n1 && i < n2; ){
		while(j > -1 && str1[j] != str2[i]){
			j = Next[j];
		}
		i++;
		j++;
	}
	return (i - j);
}

void GetNext(){
	int len = strlen(str1);
	int i = 0, j = -1;
	Next[i] = j;
	while(i < len){
		if(j == -1 || str1[i] == str1[j]){
			i++;
			j++;
			Next[i] = j;
		}
		else{
			j = Next[j];
		}
	}
}

int main(){
	while(scanf("%s%s",str1,str2) != EOF){
		memset(Next,0,sizeof(Next));
		int n1, n2;
		n1 = strlen(str1);
		n2 = strlen(str2);
		if(n1 != n2){
			printf("NO\n");
			continue;
		}
		for(int i = n1; i < 2*n1; i++){
			str2[i] = str2[i-n2];
		}
		str2[2*n2] = '\0';
		GetNext();
		int ans = KMP(n1, 2*n2);
		//printf("%d\n",ans);
		if(ans > n2){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}