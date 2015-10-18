#include<stdio.h>

int Stack[10000000];
int OutPut[10000000];
int ans[10000000];
int count = 0;
int top = -1;

void Push(int i){
	top++;
	Stack[top] = i;
}
void Pop(){
	top--;
}
int GetTop(){
	return Stack[top];
}
bool empty(){
	return (top < 0);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&OutPut[i]);
	}
	int cur = 1;
	for(int i = 0; i < n; i++){
		if(GetTop() > OutPut[i]){
			printf("No\n");
			return 0;
		}
		if(cur <= OutPut[i]){
			while(cur <= OutPut[i]){
				Push(cur++);
				ans[count++] = 1;
			}
		}
		if(top >= m){
			printf("No\n");
			return 0;
		}
		if(OutPut[i] == GetTop()){
			Pop();
			ans[count++] = 2;
		}
	}
	for(int i = 0; i < count; i++){
		if(ans[i] == 1){
			printf("push\n");
		}
		else{
			printf("pop\n");
		}
	}
	return 0;
}