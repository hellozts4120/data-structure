//���ݺ�����������д��ǰ��
#include<cstdio>

int t1[1001],t2[1001];
void Search(int a,int b,int n,int flag)
{
    int i;
    if(n == 1)//�����������������������б�������
    {
       printf(" %d",t1[a]);
       return ;
    }
    else if(n <= 0){//�������������������������򷵻���һ��
        return ;
	}
    for(i=0;t1[a]!=t2[b+i];i++) ;//�ҳ����ڵ�
	if(flag == 1)//��ԭʼ�ĸ��ڵ�
		printf("%d",t1[a]);
	else //һ��ĸ��ڵ�
		printf(" %d",t1[a]);
    Search(a-n+i,b,i,0);//�������ı���
    Search(a-1,b+i+1,n-i-1,0);//�������ı���
}
int main()
{
    int n,i;
	int space = 1,temp = 0,flag;
	char c;
    while((c = getchar()) != '\n')
    {
        if(c == ' '){
			t2[space] = temp;
			space++;
			temp = 0;
			flag = 0;
		}
		else{
			flag = 1;
			temp = temp * 10 + c - 48;
		}

	}
	if(flag){
		t2[space] = temp;
	}
	space = 1;
	temp = 0;
	while((c = getchar()) != '\n')
    {
        if(c == ' '){
			t1[space] = temp;
			space++;
			temp = 0;
			flag = 0;
		}
		else{
			flag = 1;
			temp = temp * 10 + c - 48;
		}

	}
	if(flag){
		t1[space] = temp;
	}
	n = space;
    Search(n,1,n,1);//��Ϊ�������������Ǹ��ڵ�,���������ǰ��Ŀ�ʼ�㲻ͬ��ע��һ��

    return 0;
}