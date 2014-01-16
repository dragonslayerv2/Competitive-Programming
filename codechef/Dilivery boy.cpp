#include<stdio.h>

int main()
{
    unsigned int n,m;
    unsigned int t[250][250];
    unsigned int s,g,d;
    unsigned int o1,o2;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    scanf("%d",&t[i][j]);
            }
    }
    
    scanf("%d",&m);
    while(m--)
    {
              scanf("%d %d %d",&s,&g,&d);
              o1=t[s][g]+t[g][d];
              o2=o1-t[s][d];
              printf("%d %d\n",o1,o2);
    }
    return 0;
}
