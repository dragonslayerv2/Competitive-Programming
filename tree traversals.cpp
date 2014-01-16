/*
  Name: Binary Tree Traversals
  Copyright: 
  Author: Shobhit Saxena
  Date: 05/11/12 23:32
  Description: 
*/



typedef struct tree
{
       int n;
       tree *lchild;
       tree *rchild;
}tree;



void intrav(tree *root)
{
     if(root)
     {
              inorder(root->lchild);
              printf("%d",root->n);
              inorder(root->rchild);
     }
}
void pretrav(tree *root)
{
     if(root)
     {
              printf("%d",root->n);
              pretrav(root->lchild);
              pretrav(root->rchild);
     }
}
void posttrav(tree *root)
{
     if(root)
     {
              posttrav(root->lchild);
              posttrav(root->rchild);
              printf("%d",root->n);
     }
}
