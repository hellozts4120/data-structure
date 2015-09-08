#include<iostream>
#include<cstring>
using namespace std;

char str[1000001];
int Next[1000001];

void getnext(){
	int i = 0,j = -1;
	Next[0] = j;
	int len = strlen(str);
	while(i < len){
		if(str[i] == str[j] || j == -1){
			i++;
			j++;
			Next[i] = j;	//������λƥ��ɹ������ǰ��һλ��ͬʱNext[i] = j;
		}
		else j = Next[j];	//ƥ�䲻�ɹ����򷵻�����Next[j]λƥ��
	}
}

int main()
{
	int time = 1;
	int len,length;
	while(scanf("%d",&len) && len){
		scanf("%s",str);
		getnext();
		printf("Test case #%d\n",time);
		for(int i = 1;i <= len;i++){
			length = i - Next[i];	//ѭ���ڵĳ���
			if((i != length) && (i % length == 0)){//���ж��ѭ��
				printf("%d %d\n",i,i / length);
			}
		}
		printf("\n");
		time++;
	}
	return 0;
}

