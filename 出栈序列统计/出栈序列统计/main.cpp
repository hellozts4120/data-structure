#include<cstdio>
#include<cstring>

int n;
template <typename T>
class Stack{
	private:
		int top;
		T sta[16];
	public:
		Stack():top(-1){};
		void push(T d){
			sta[++top] = d;
		}
		void pop(){
			top--;
		}
		bool empty(){
			return top < 0;
		}
		bool full(){
			return top > n - 1;
		}
};

int f = 0;
int fun(Stack<int> sta,int s){
	if(sta.empty() && s == 0){
		f++;
		return 0;
	}
	else if(sta.empty()){
		sta.push(s);
		fun(sta,--s);
		sta.pop();
	}
	else if(s == 0){
		sta.pop();
		fun(sta,s);
	}
	else{
		sta.push(s);
		fun(sta,--s);
		sta.pop();
		s++;
		sta.pop();
		fun(sta,s);
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	Stack<int> a;
	fun(a,n);
	printf("%d\n",f);
}