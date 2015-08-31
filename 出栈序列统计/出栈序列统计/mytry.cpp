#include<cstdio>

int n;
class Stack{		//栈的主类
	private:
		int sta[15];
		int top;
	public:
		Stack():top(-1){};
		void push(int i);
		void pop();
		bool empty();
		bool full();
};

bool Stack::full(){		//是否满栈
	return (top > n - 1);
}

bool Stack::empty(){	//是否空栈
	return (top < 0);
}
		
void Stack::pop(){		//出栈
	top--;
}

void Stack::push(int i){	//入栈
	top++;
	sta[top] = i;
}

int plan = 0;
int GetPlan(Stack a,int i){	//a:栈的类;i:当前外部元素剩余数
	if(a.empty() && i == 0){	//当前空栈且所有元素出栈
		plan++;
		return 0;
	}
	else if(a.empty()){			//当前空栈且有元素未入栈
		a.push(i);
		GetPlan(a,--i);
	}
	else if(i == 0){			//未空栈但所有元素均入栈
		a.pop();
		GetPlan(a,i);
	}
	else{	//最复杂情况，未空栈，有元素未入栈
		a.push(i);
		GetPlan(a,--i);
		a.pop();
		i++;		//分两种情况，一种为前两行，即入栈一元素后重新操作；另一种为后半情况，即直接出栈一元素，然后再重新操作；
		a.pop();
		GetPlan(a,i);
	}
	return 0;
}

int main()
{
	Stack S;
	scanf("%d",&n);
	GetPlan(S,n);
	printf("%d\n",plan);
}