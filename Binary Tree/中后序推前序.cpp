//根据后序和中序遍历写出前序
#include<cstdio>

int t1[1001],t2[1001];
void Search(int a,int b,int n,int flag)
{
    int i;
    if(n == 1)//存在左子树或右子树，进行遍历即可
    {
       printf(" %d",t1[a]);
       return ;
    }
    else if(n <= 0){//不存在左子树或者右子树，则返回上一层
        return ;
	}
    for(i=0;t1[a]!=t2[b+i];i++) ;//找出根节点
	if(flag == 1)//最原始的根节点
		printf("%d",t1[a]);
	else //一般的根节点
		printf(" %d",t1[a]);
    Search(a-n+i,b,i,0);//左子树的遍历
    Search(a-1,b+i+1,n-i-1,0);//右子树的遍历
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
    Search(n,1,n,1);//因为后序最后遍历的是根节点,所以这里和前面的开始点不同，注意一下

    return 0;
}