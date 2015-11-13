#include<cstring>
#include<cstdio>

int a[1000010];
int b[1000010];

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int m,n;
	int temp;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	int cur = 0;
	for(int i = 0; i < m; i++){
		scanf("%d",&temp);
		while(temp > a[cur] && cur < n){
			printf("%d ",a[cur]);
			cur++;
		}
		if(a[cur] == temp){
			cur++;
		}
		else{
			printf("%d ",temp);
		}
	}
	while(cur < n){
		printf("%d ",a[cur++]);
	}
	printf("\n");
	return 0;
}