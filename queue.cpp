#include<stdio.h>
#define ERRNO -1
struct node
{
       int data;
       node *next;
};

node * createnode(int n)
{
     node *temp=new node;
     if(temp==NULL) return NULL;
     temp->data=n;
     temp->next=NULL;
     return temp;
}

int pushnode(node **head,node **rear,node *n)
{
    if(n==NULL) return 0;
    if(*head==NULL) 
                    *rear=*head=n;
    else
    {
                    (*rear)->next=n;
                    *rear=n;
    }
    return 1;
}

int pop(node **head,node **rear)
{
    if(*head==NULL) return ERRNO;
    else
    {
        node *temp=*head;
        int n=temp->data;
        *head=(*head)->next;
        if(head==NULL) rear=NULL;
        delete temp;
        return n;
        
    } 
        
}
void print(node *head)
{
     while(head)
     {
                printf("%d ",head->data);
                head=head->next;
     }
}
int main()
{
    node *head, *rear;
    
    head=rear=NULL;
    pushnode(&head,&rear,createnode(2));
    pushnode(&head,&rear,createnode(4));
    pushnode(&head,&rear,createnode(3));    
    printf("%d\n",pop(&head,&rear));
        printf("%d\n",pop(&head,&rear));
            printf("%d\n",pop(&head,&rear));printf("%d\n",pop(&head,&rear));
    getchar();
    return 0;
}
