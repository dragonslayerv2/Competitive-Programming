#include<stdio.h>

struct tree
{
 int num;
 tree *l;
 tree *r;
}*root=NULL;

tree *createnode(int n)
{
     tree *p=new tree;
     p->l=p->r=NULL;
     p->num=n;
     return p;    
}

void insert(tree *p)
{
     if(root==NULL)
     {
                   root=p;
                   return;
     }
     else
     {
                   tree *t=root;
                   
                   while(1)
                   {
                           
                           if(p->num>t->num) 
                           {
                                             if(t->r==NULL) {t->r=p;return;}
                                             else t=t->r;
                           }
                           else             
                           {
                                             if(t->l==NULL) {t->l=p;return;}
                                             else t=t->l;
                           }
                   }
     
     }
}
int x=0;
int k;
int flag=0;
void inorder(tree *sr)
{
 if(sr!=NULL)
 {
            if(flag==1) return;
            inorder(sr->l);
            if(flag==1) return;
             x++;
             if(x==k)
                     {flag=1;printf("%d\n",sr->num);return;}
         if(flag==1) return;
         inorder(sr->r);

 }
 else
         return;
}

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%d",&k);
    int i=0;
    while(n--)
    {
              
              int q;
              scanf("%d",&q);
              if(q>=0)
                      {i++;insert(createnode(q));}
              else if(q==-1&&k<=i)
                  {
                                  x=0;flag=0;inorder(root);
                  }
              
    }
    return 0;
}
