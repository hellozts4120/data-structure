#include<cstdio>
#include<cstring>

const int MAX = 100010;
int father[MAX];
int ranks[MAX];

int Find(int x){
	if(father[x] == x){
		return x;
	}
	else{
		father[x] = Find(father[x]);
		return father[x];
	}
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	father[x] = y;
}

int main(){
	int cases;
	int n,m;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; i++){
			father[i] = i;
			ranks[i] = 0;
		}
		for(int i = 0; i < m; i++){
			char c[10];
			int a,b;
			scanf("%s %d %d",c,&a,&b);
			if(c[0] == 'D'){
				if(!ranks[a] && !ranks[b]){
					ranks[a] = b;
					ranks[b] = a;
				}
				else if(!ranks[a]){
					ranks[a] = b;
					Union(a,ranks[b]);
				}
				else if(!ranks[b]){
					ranks[b] = a;
					Union(b,ranks[a]);
				}
				else{
					Union(a,ranks[b]);
					Union(b,ranks[a]);
				}
			}
			if(c[0] == 'A'){
				if(Find(a) == Find(b)){
					printf("In the same gang.\n");
				}
				else if(Find(a) == Find(ranks[b])){
					printf("In different gangs.\n");
				}
				else{
					printf("Not sure yet.\n");
				}
			}
		}
	}
	return 0;
}