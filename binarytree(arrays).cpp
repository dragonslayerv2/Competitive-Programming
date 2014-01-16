//BST using arrays ... insert leaf will insert a leaf into the tree. Remember to put tree[1]=MYNULL. tree must contain 2^h+1 leaf space.
// Return type: 0 if node is already present.
//              1 if node is inserted
//              -1 if not enough space.

// Arguments c node to be inserted, tree in which to be inserted and n be the size of tree


#include<stdio.h>
#define MAX 100
#define MYNULL -1
#define lchild(x) x<<1
#define rchild(x) ((x<<1)+1)
inline int insertleaf(int c,int tree[],int n)
{
            int pos=1;
            while(1)
            {
                    
                    if(pos>=n) return -1;
                    if(tree[pos]==MYNULL)
                    {
                                tree[pos]=c;
                                tree[lchild(pos)]=MYNULL;
                                tree[rchild(pos)]=MYNULL;
                                return 1;
                    }
                    else if(tree[pos]==c)
                                    return 0;
                    
            else pos=(c>tree[pos])?rchild(pos):lchild(pos);            
            }
}
int main()
{
    int tree[MAX];
    tree[1]=MYNULL;
    while(1)
    {
            int c;
            scanf("%d",&c);
            printf("\n%d=> ",insertleaf(c,tree,MAX));
            
            
    }        
}
