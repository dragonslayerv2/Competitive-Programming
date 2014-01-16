#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define max(a,b) (a>b?a:b)


typedef struct tree
{
       int n;
       tree *lchild;
       tree *rchild;
}tree;


tree *createnode(int n)
{
     tree *temp;
     temp=(tree *)malloc(sizeof(tree));
     assert(temp);
     temp->n=n;
     temp->rchild=temp->lchild=NULL;
     return temp;
}


void insertnode(tree **root,tree *t)
{
     
     
     if(!(*root)) *root=t;
     else if((*root)->n>t->n) insertnode(&((*root)->lchild),t);
     else insertnode(&((*root)->rchild),t);
}

inline void insert(tree **root,int n)
{
       insertnode(root,createnode(n));
}

void inorder(tree *root)
{
     if(root)
     {
              inorder(root->lchild);
              printf("%d",root->n);
              inorder(root->rchild);
     }
}




int height(tree *t)
{
    if(t==NULL)
               return 0;
    
    int h1=height(t->lchild);
    int h2=height(t->rchild);
    return 1+max(h1,h2);
}

int main()
{
    tree *root=NULL;
    int n;
    do
    {
          
          scanf("%d",&n);
          if(n==-1) break;
          insert(&root,n);
    }while(n!=-1);
    
    inorder(root);
    printf("..........................\n height= %d",height(root));
    
    fflush(stdin);
    getchar();
}
