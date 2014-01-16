#include<stdio.h>
 
struct node
{
 
    struct node *edge[10];
    int wt[10],id,edgeno;
} ver[10];
 
int makegraph()
{
    int i=0,j=0,nov=0;
    char ch;
    printf("Enter number of vertices in the graph");
    scanf("%d",&nov);
    for(i=0;i<nov;i++)
    {
        ver[i].id=i;
        ver[i].edgeno=0;
        for(j=0;j<nov;j++)
        {fflush(stdin);
            printf("Is there any edge between vertex %d and %d(y/n)\n",i,j);
            scanf("%c",&ch);
            if(ch=='y')
            {
                       fflush(stdin);
                ver[i].edge[j]=&ver[j];
                ver[i].edgeno++;
                printf("Enter the weight of the edge between %d and %d");
                scanf("%d",&ver[i].wt[j]);
            }
        }
    }
    return nov;
}

void showgraph(int nov)
{
    int i,j;
    for(i=0;i<nov;i++)
    {
        printf("ver[%d]:-\nEdges:-",i);        
        for(j=0;j<ver[i].edgeno;j++)
        {
            printf("(%d,%d),",ver[i].edge[j]->id,ver[i].wt[j]);
        }
    }
}

int main()
{
    showgraph(makegraph());
    getchar();
    return 0;
}
 
