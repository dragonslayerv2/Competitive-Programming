// Binary tree sorting and searching...
#include<stdio.h>

static int a=0;
int n,k,value;
struct tree
{
 int n,pos;
 tree *l;
 tree *r;
} *head=NULL,*temp,*t,*x;

void check(int v,int x)
{
     if(head==NULL)
     {a++;
                   head=new tree;
                   head->n=v;
                   head->pos=x;
                   head->r=head->l=NULL;return;
     }
     
     temp=head;
     
     while(temp)
     { t=temp;
       if(temp->n>v)
       {
        temp=temp->l;
       }
       else if(temp->n<v)
       {
        temp=temp->r;
       }
      else 
      {
       if(x-temp->pos>=k)
       {
        temp->pos=x;
        a++;
       }
       return;
      }
     }
     
     if(t->n>v)
       {
                  
        t->l=new tree;
        (t->l)->n=v;
        (t->l)->pos=x;
        t->l->l=t->l->r=NULL;
       }
       else if(t->n<v)
       {
        t->r=new tree;
        (t->r)->n=v;
        (t->r)->pos=x;
t->r->l=t->r->r=NULL;
       }
       a++;
}
int main()
{
 
 scanf("%d %d",&n,&k);
 
 for(int i=0;i<n;i++)
 {
         scanf("%d",&value);
         check(value,i);
         
 }
 printf("%d",a);
}
