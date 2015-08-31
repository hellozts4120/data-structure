#include<cstdio>

int n;
class Stack{		//ջ������
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

bool Stack::full(){		//�Ƿ���ջ
	return (top > n - 1);
}

bool Stack::empty(){	//�Ƿ��ջ
	return (top < 0);
}
		
void Stack::pop(){		//��ջ
	top--;
}

void Stack::push(int i){	//��ջ
	top++;
	sta[top] = i;
}

int plan = 0;
int GetPlan(Stack a,int i){	//a:ջ����;i:��ǰ�ⲿԪ��ʣ����
	if(a.empty() && i == 0){	//��ǰ��ջ������Ԫ�س�ջ
		plan++;
		return 0;
	}
	else if(a.empty()){			//��ǰ��ջ����Ԫ��δ��ջ
		a.push(i);
		GetPlan(a,--i);
	}
	else if(i == 0){			//δ��ջ������Ԫ�ؾ���ջ
		a.pop();
		GetPlan(a,i);
	}
	else{	//��������δ��ջ����Ԫ��δ��ջ
		a.push(i);
		GetPlan(a,--i);
		a.pop();
		i++;		//�����������һ��Ϊǰ���У�����ջһԪ�غ����²�������һ��Ϊ����������ֱ�ӳ�ջһԪ�أ�Ȼ�������²�����
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