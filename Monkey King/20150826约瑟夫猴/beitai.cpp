#include <stdio.h>
 
struct Monkey
{
    int i;
    Monkey * next;
};
 
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    Monkey * head,* curr;
    curr=NULL;
    head=NULL;
    Monkey *m=new Monkey;
    m->i=0;
    head=m;
    curr=m;
    for(int i=1;i<n;i++)
    {
        Monkey *m=new Monkey;
        m->i=i;
        curr->next=m;
        curr=m;
    }
    curr->next=head;
    int p=1;
    while(curr->next!=NULL)
    {
        if(curr->next->next==curr->next)
        {
            printf("%d\n",curr->next->i+1);
            break;
        }
        if(p==t)
        {
            Monkey *t=curr->next;
            curr->next=curr->next->next;
            delete t;
            p=1;
        }
        p++;
        curr=curr->next;
    }
    return 0;
}