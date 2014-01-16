#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct node
{
       int data;
       node *lchild,*rchild;
};

node *createnode(int n)
{
     node *temp=new node;
     temp->data=n;
     assert(temp);
     temp->lchild=NULL;
     temp->rchild=NULL;
     return temp;
}

void insertleaf(node *leaf,node *root)
{
     assert(root);
     printf("Presently at %d\n",root->data);
     if(!root->lchild) 
     {
                     printf("Left subtree: No subtree\n");
     }
     else
     {
                     printf("Left subtree: Exist\n");
     }
     if(!root->rchild)
     {
                      printf("Right subtree: No right subtree\n");
     }
     else
     {
         printf("Right subtree : Exist\n");
     }
     printf("Options\n L. Insert at left\nR. Insert at right.\n l. move to left subtree \n r. move to right subtree\n=>");
     char ch;
     fflush(stdin);
     scanf("%c",&ch);
     switch(ch)
     {
               case 'L': root->lchild=leaf;break;
               case 'R': root->rchild=leaf;break;
               case 'l': insertleaf(leaf,root->lchild);break;
               case 'r': insertleaf(leaf,root->rchild);break;
               default:printf("invalid operation");getchar();
     }
     printf("---------\n");
}

int main()
{
    node *root=createnode(1);
    for(int i=2;i<100;i++)
    {
            system("cls");
            insertleaf(createnode(i),root);
    }
    return 0;
}
