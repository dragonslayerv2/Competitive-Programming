#include<stdio.h>


int main()
{
    int x,y;int t;
    scanf("%d",&t);
    while(t--)
    {
              
              scanf("%d %d",&x,&y);
              if(x==0||y==0) printf("0\n");
              else printf("%d\n",x/2+y/2+1);
    }
    
    return 0;
}
