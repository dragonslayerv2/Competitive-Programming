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

int pushnode(node **head,node *n)
{
    if(n==NULL) return 0;
    if(*head==NULL) 
                    *head=n;
    else
    {
                    n->next=*head;
                    *head=n;
    }
    return 1;
}

int pop(node **head)
{
    if(*head==NULL) return ERRNO;
    
    else
    {
        node * temp=*head;
        int n=temp->data;
        *head=(*head)->next;
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

void reverse(node **head)
{
   node *rear;
   node *temp;
   rear=*head;
   while(rear->next)
   {
         temp=rear->next;
         rear->next=temp->next;
         temp->next=*head;
         *head=temp;           
   }
}

void split(node *head,node**first,node**second)
{
     node *first=NULL;
     node *second=NULL;
     
     int k=1;
     
     while(head)
     {
               if((k++)%2)
               {
                          pushnode(&first,createnode(head->data));
               }
               else
               {
                          pushnode(&second,createnode(head->data));
               }
               head=head->next;
     }
}

int main()
{
    node *head=NULL;
    for(int i=0;i<=20;i++)
            pushnode(&head,createnode(i));
    
    node *temp=head;
    
    getchar();
    return 0;
}
