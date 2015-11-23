#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int Hash[100107][105];
char Dic[100107][300];
int visit[100107];

int CalHash(char str[]){  
    unsigned int seed = 131;  
    unsigned int key = 0;  
    for(int i = 0; str[i]; i++){
        key = key * seed + str[i];  
    }  
    return (key & 0x7FFFFFFF)%100107;  
}  

int main(){
	freopen("in.txt","r",stdin);
	freopen("outt.txt","w",stdout);
	for(int i = 0; i < 100107; i++){
		Hash[i][0] = 0;
		Dic[i][0] = '\0';
		visit[i] = 0;
	}
	int n,m;
	char str[260];
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		for(int j = 0; j < num; j++){
			scanf("%s",str);
			int key = CalHash(str);
			while((strcmp(Dic[key], str)) && visit[key]){
				key += 3;
			}
			strcpy(Dic[key],str);
			visit[key] = 1;
			Hash[key][++Hash[key][0]] = i;
		}
	}
	scanf("%d",&m);
	for(int i = 0; i < m; i++){
		cin >> str;
		int here = 0;
		int key = CalHash(str);
		while(visit[key] && !here){
			if(!strcmp(str,Dic[key])){
				here = 1;
			}
			else{
				key += 3;
			}
		}
		if(!Hash[key][0]){
			printf("NOT FOUND\n");
			continue;
		}
		for(int j = 1; j <= Hash[key][0]; j++){
			if(Hash[key][j] == Hash[key][j+1]){
				continue;
			}
			if(j == Hash[key][0]){
				printf("%d\n",Hash[key][j]);
			}
			else{
				printf("%d ",Hash[key][j]);
			}
		}
	}
	return 0;
}